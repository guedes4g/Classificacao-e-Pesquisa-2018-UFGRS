#include<iostream>

using namespace std;

template<typename T>
class BTreeNode {


public:
    T *keys;
    int t;
    int n;
    bool leaf;

    BTreeNode<T> **C;

    BTreeNode(int t1, bool leaf1) {

        t = t1;
        leaf = leaf1;

        keys = new T[2 * t - 1];
        C = new BTreeNode<T> *[2 * t];

        n = 0;
    }

    int findKey(T k) {
        int index = 0;
        while (index < n && keys[index] < k)
            ++index;
        return index;
    }

    void remove(T k) {
        int index = findKey(k);

        if (index < n && keys[index] == k) {
            if (leaf)
                removeFromLeaf(index);
            else
                removeFromNonLeaf(index);
        } else {
            if (leaf) {
                cout << "The key " << k << " is does not exist in the tree\n";
                return;
            }

            bool flag = (index == n);

            if (C[index]->n < t)
                fill(index);

            if (flag && index > n)
                C[index - 1]->remove(k);
            else
                C[index]->remove(k);
        }
    }

    void removeFromLeaf(int index) {

        for (int i = index + 1; i < n; ++i)
            keys[i - 1] = keys[i];

        n--;
    }

    void removeFromNonLeaf(int index) {
        T k = keys[index];
        if (C[index]->n >= t) {
            T pred = getPred(index);
            keys[index] = pred;
            C[index]->remove(pred);
        } else if (C[index + 1]->n >= t) {
            T succ = getSucc(index);
            keys[index] = succ;
            C[index + 1]->remove(succ);
        } else {
            merge(index);
            C[index]->remove(k);
        }
    }

    T getPred(int index) {

        BTreeNode<T> *cur = C[index];
        while (!cur->leaf)
            cur = cur->C[cur->n];

        return cur->keys[cur->n - 1];
    }

    T getSucc(int index) {
        BTreeNode<T> *cur = C[index + 1];
        while (!cur->leaf)
            cur = cur->C[0];

        return cur->keys[0];
    }

    void fill(int index) {
        if (index != 0 && C[index - 1]->n >= t)
            borrowFromPrev(index);

        else if (index != n && C[index + 1]->n >= t)
            borrowFromNext(index);

        else {
            if (index != n)
                merge(index);
            else
                merge(index - 1);
        }
    }

    void borrowFromPrev(int index) {

        BTreeNode<T> *child = C[index];
        BTreeNode<T> *sibling = C[index - 1];

        for (int i = child->n - 1; i >= 0; --i)
            child->keys[i + 1] = child->keys[i];

        if (!child->leaf) {
            for (int i = child->n; i >= 0; --i)
                child->C[i + 1] = child->C[i];
        }


        child->keys[0] = keys[index - 1];

        if (!leaf)
            child->C[0] = sibling->C[sibling->n];

        keys[index - 1] = sibling->keys[sibling->n - 1];

        child->n += 1;
        sibling->n -= 1;
    }

    void borrowFromNext(int index) {

        BTreeNode<T> *child = C[index];
        BTreeNode<T> *sibling = C[index + 1];

        child->keys[(child->n)] = keys[index];
        if (!(child->leaf))
            child->C[(child->n) + 1] = sibling->C[0];

        keys[index] = sibling->keys[0];

        for (int i = 1; i < sibling->n; ++i)
            sibling->keys[i - 1] = sibling->keys[i];


        if (!sibling->leaf) {
            for (int i = 1; i <= sibling->n; ++i)
                sibling->C[i - 1] = sibling->C[i];
        }

        child->n += 1;
        sibling->n -= 1;
    }

    void merge(int index) {
        BTreeNode<T> *child = C[index];
        BTreeNode<T> *sibling = C[index + 1];

        child->keys[t - 1] = keys[index];

        for (int i = 0; i < sibling->n; ++i)
            child->keys[i + t] = sibling->keys[i];


        if (!child->leaf) {
            for (int i = 0; i <= sibling->n; ++i)
                child->C[i + t] = sibling->C[i];
        }

        for (int i = index + 1; i < n; ++i)
            keys[i - 1] = keys[i];


        for (int i = index + 2; i <= n; ++i)
            C[i - 1] = C[i];

        child->n += sibling->n + 1;
        n--;


        delete (sibling);
    }

    void insertNonFull(T k) {

        int i = n - 1;
        if (leaf) {
            while (i >= 0 && keys[i] > k) {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1] = k;
            n = n + 1;
        } else {

            while (i >= 0 && keys[i] > k)
                i--;
            if (C[i + 1]->n == 2 * t - 1) {
                splitChild(i + 1, C[i + 1]);
                if (keys[i + 1] < k)
                    i++;
            }
            C[i + 1]->insertNonFull(k);
        }
    }

    void splitChild(int i, BTreeNode<T> *y) {
        auto *z = new BTreeNode<T>(y->t, y->leaf);
        z->n = t - 1;
        for (int j = 0; j < t - 1; j++)
            z->keys[j] = y->keys[j + t];

        if (!y->leaf) {
            for (int j = 0; j < t; j++)
                z->C[j] = y->C[j + t];
        }

        y->n = t - 1;

        for (int j = n; j >= i + 1; j--)
            C[j + 1] = C[j];

        C[i + 1] = z;

        for (int j = n - 1; j >= i; j--)
            keys[j + 1] = keys[j];

        keys[i] = y->keys[t - 1];
        n = n + 1;
    }

    void traverse() {
        int i;
        for (i = 0; i < n; i++) {
            if (!leaf)
                C[i]->traverse();
            cout << " " << keys[i];
        }
        if (!leaf)
            C[i]->traverse();
    }

    BTreeNode<T> *search(T k) {
        int i = 0;
        while (i < n && k > keys[i])
            i++;

        if (keys[i] == k)
            return this;

        if (leaf)
            return NULL;

        return C[i]->search(k);
    }

};


template<typename T>
class BTree {
    BTreeNode<T> *root;
    int t;
public:
    explicit BTree(int _t) {
        root = nullptr;
        t = _t;
    }

    void traverse() {
        if (root != nullptr) root->traverse();
    }


    BTreeNode<T> *search(T k) {
        return (root == nullptr) ? nullptr : root->search(k);
    }

    void insert(T k) {

        if (root == nullptr) {

            this->root = new BTreeNode<T>(t, true);
            root->keys[0] = k;
            root->n = 1;
        } else {

            if (root->n == 2 * t - 1) {
                auto *s = new BTreeNode<T>(t, false);
                s->C[0] = root;
                s->splitChild(0, root);
                int i = 0;
                if (s->keys[0] < k)
                    i++;
                s->C[i]->insertNonFull(k);
                root = s;
            } else
                root->insertNonFull(k);
        }
    }

    void remove(T k) {
        if (!root) {
            cout << "The tree is empty\n";
            return;
        }
        root->remove(k);
        if (root->n == 0) {
            BTreeNode<T> *tmp = root;
            if (root->leaf)
                root = nullptr;
            else
                root = root->C[0];
            delete tmp;
        }
    }
};


int main() {
    auto t = *new BTree<string>(3);


    t.insert("A");
    t.insert("Ab");
    t.insert("Ac");
    t.insert("Av");
    t.insert("Ab");
    t.insert("Ab");
    t.insert("Af");
    t.insert("Aff");
    t.insert("Ag");
    t.insert("Ah");
    t.insert("Ah");
    t.insert("As");
    t.insert("As");
    t.insert("Add");
    t.insert("Afsfs");
    t.insert("Afs");
    t.insert("Agdg");
    t.insert("Agd");
    t.insert("Adsd");
    t.insert("Afs");
    t.insert("Agdgd");
    t.insert("Aere");
    t.insert("Z");

    auto found = *t.search("Z");

    cout << found.findKey("Z") << endl;

//    cout << "Traversal of tree constructed is\n";
//    t.traverse();
//    cout << endl;
//
//    t.remove("A");
//    cout << "Traversal of tree after removing A\n";
//    t.traverse();
//    cout << endl;
//
//    t.remove("Af");
//    cout << "Traversal of tree after removing Af\n";
//    t.traverse();
//    cout << endl;
//
//    t.remove("Afsfs");
//    cout << "Traversal of tree after removing Afsfs\n";
//    t.traverse();
//    cout << endl;
//
//    t.remove("Agdgd");
//    cout << "Traversal of tree after removing Agdgd\n";
//    t.traverse();
//    cout << endl;
//
//    t.remove("Aere");
//    cout << "Traversal of tree after removing Aere\n";
//    t.traverse();
//    cout << endl;
//
//    t.remove("Z");
//    cout << "Traversal of tree after removing Z\n";
//    t.traverse();
//    cout << endl;

    return 0;
}