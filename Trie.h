//
// Created by guedes on 5/27/18.
//

#ifndef CPD_FINAL_TRIE_H

#include <string>

using namespace std;
#define CPD_FINAL_TRIE_H

template<typename T>
class TrieNode {
public:
    char k{};
    vector<struct TrieNode *> children;
    T info;
    bool isEndOfWord{};

    explicit TrieNode(char k, bool isEndOfWord);

    explicit TrieNode(char k, bool isEndOfWord, T *v);

    void setInfo(T *info) {
        this->info = &info;
    }
};

template<typename T>
class Trie {
    TrieNode<T> *root;
public:
    explicit Trie();

    void insert(string key, T v);

    void override(string key, T v);

    T search(string key);

    bool has(string key);

private:
    int search(struct TrieNode<T> *cur, char key);

    TrieNode<T> *insertNode(struct TrieNode<T> *cur, char k, bool terminal, T *v);
};


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
            return NULL;
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

template<typename T>
Trie<T>::Trie() {
    root = new TrieNode<T>('\0', false);
}


#endif //CPD_FINAL_TRIE_H
