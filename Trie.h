//
// Created by guedes on 5/27/18.
//

#ifndef CPD_FINAL_TRIE_H

template<typename T>
class TrieNode {
public:
    char k{};
    vector<struct TrieNode *> children;
    T info;
    bool isEndOfWord{};

    TrieNode(char k, bool isEndOfWord);

    TrieNode(char k, bool isEndOfWord, T *v);

    void setInfo(T *info) {
        this->info = &info;
    }
};

template<typename T>
class Trie {
    TrieNode<T> *root;
public:
    Trie() {
        root = new TrieNode<T>('\0', false);
    }

    void insert(string key, T v);

    void override(string key, T v);

    T search(string key);

    bool has(string key);

private:
    int search(struct TrieNode<T> *cur, char key);

    TrieNode<T> *insertNode(struct TrieNode<T> *cur, char k, bool terminal, T *v);
};


#define CPD_FINAL_TRIE_H

#endif //CPD_FINAL_TRIE_H
