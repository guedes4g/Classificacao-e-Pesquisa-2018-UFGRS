//
// Created by guedes on 5/27/18.
//

#ifndef CPD_FINAL_HASHMAP_H
#include <vector>

template<typename K, typename V>
class Node {
public:
    V value;
    K key;
    Node(K key, V value);
};


template<typename K, typename V>
class HashMap {

public:
    std::vector<Node<K, V>> *arr;
    unsigned int capacity;
    unsigned int size;

    explicit HashMap(unsigned int capacity);

    unsigned int
    hashCode( K object );

    bool insertNode(K key, V value);

    V deleteNode(K key);

    V get(K key);

    bool contains(K key);

    bool set(K key, V value);

    int sizeofMap();

    int getCapacity();

    bool isEmpty() {
        return size == 0;
    }

};

#define CPD_FINAL_HASHMAP_H

#endif //CPD_FINAL_HASHMAP_H
