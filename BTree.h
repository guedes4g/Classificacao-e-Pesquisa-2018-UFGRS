//
// Created by guedes on 5/27/18.
//

#ifndef CPD_FINAL_BTREE_H
template<typename T>
class BTreeNode {


public:
    T *keys;
    int t;
    int n;
    bool leaf;

    BTreeNode<T> **C;

    BTreeNode(int t1, bool leaf1);

    int findKey(T k);

    void remove(T k);

    void removeFromLeaf(int index);

    void removeFromNonLeaf(int index);

    T getPred(int index);

    T getSucc(int index);

    void fill(int index);

    void borrowFromPrev(int index);

    void borrowFromNext(int index);

    void merge(int index);

    void insertNonFull(T k);

    void splitChild(int i, BTreeNode<T> *y);

    void traverse();

    BTreeNode<T> *search(T k);

};


template<typename T>
class BTree {
    BTreeNode<T> *root;
    int t;
public:
    explicit BTree(int _t);

    void traverse();

    BTreeNode<T> *search(T k);

    void insert(T k);

    void remove(T k);
};

#define CPD_FINAL_BTREE_H

#endif //CPD_FINAL_BTREE_H
