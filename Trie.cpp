
#include "HashMap.cpp"

#include "Trie.h"

using namespace std;

///TRIE NODE

template<typename T>
TrieNode<T>::TrieNode(char k, bool isEndOfWord, T *v) {
    this->k = k;
    this->children = *new vector<struct TrieNode *>;
    this->isEndOfWord = isEndOfWord;
    this->info = *v;
}

template<typename T>
TrieNode<T>::TrieNode(char k, bool isEndOfWord) {
    this->k = k;
    this->children = *new vector<struct TrieNode *>;
    this->isEndOfWord = isEndOfWord;
}


///TRIE

template<typename T>
void Trie<T>::insert(string key, T v) {
    struct TrieNode<T> *cur = this->root;
    for (int i = 0; i < key.size(); i++) {
        auto index = this->search(cur, key[i]);
        if (index == -1) {
            cur = this->insertNode(cur, key[i], false, &v);
        } else {
            cur = cur->children[index];
        }
    }
    cur->isEndOfWord = true;
}

template<typename T>
T Trie<T>::search(string key) {
    struct TrieNode<T> *cur = this->root;

    for (int i = 0; i < key.size(); i++) {
        auto index = this->search(cur, key[i]);
        if (index == -1) {
            return false;
        } else {
            cur = cur->children[index];
        }
    }
    return cur->info;
}

template<typename T>
bool Trie<T>::has(string key) {
    struct TrieNode<T> *cur = this->root;

    for (int i = 0; i < key.size(); i++) {
        auto index = this->search(cur, key[i]);
        if (index == -1) {
            return false;
        } else {
            cur = cur->children[index];
        }
    }
    return cur->isEndOfWord;
}

template<typename T>
TrieNode<T> *Trie<T>::insertNode(TrieNode<T> *cur, char k, bool terminal, T *v) {
    auto *nw = new TrieNode<T>(k, terminal, v);
    cur->children.push_back(nw);
    return nw;
}

template<typename T>
int Trie<T>::search(TrieNode<T> *cur, char key) {
    for (int i = 0; i < cur->children.size(); i++) {
        if (cur->children[i]->k == key) {
            return i;
        }
    }

    return -1;
}

template<typename T>
void Trie<T>::override(string key, T v) {
    struct TrieNode<T> *cur = this->root;
    for (int i = 0; i < key.size(); i++) {
        auto index = this->search(cur, key[i]);
        if (index == -1) {
            cur = this->insertNode(cur, key[i], false, &v);
        } else {
            cur = cur->children[index];
        }
    }
    cur->info = v;
    cur->isEndOfWord = true;
}


//int main() {
//    Trie<int> t = *new Trie<int>();
//    t.insert("Maca", 100);
//    cout << "Found? " << t.has("Maca") << " - " << (t.search("Maca")) << endl;
//    t.override("Maca", 111);
//    cout << "Found? " << t.has("Maca") << " - " << (t.search("Maca")) << endl;
//}