#include <bits/stdc++.h>
#include <bits/hash_bytes.h>
#include "HashMap.h"
using namespace std;
using byte = unsigned char ;



template<typename K, typename V>
Node<K, V>::Node(K key, V value) {
    this->value = value;
    this->key = key;
}


template<typename K, typename V>
unsigned int HashMap<K, V>::hashCode(const string &s)
{
    const char * str = s.c_str();
    auto length = static_cast<unsigned int>(s.size());
    unsigned int hash = 0xAAAAAAAA;
    unsigned int i    = 0;

    for (i = 0; i < length; ++str, ++i)
    {
        if ((i & 1) == 0) {
            hash ^= (hash << 7) ^ (*str) * (hash >> 3);
        } else {
            hash ^= ~((hash << 11) + ((*str) ^ (hash >> 5)));
        }
    }

    return hash % this->capacity;
}


template<typename K, typename V>
bool HashMap<K, V>::insertNode(K key, V value) {
    unsigned int hashIndex = hashCode( key );
    for(int i = 0; i < arr[hashIndex].size(); i++)
        if (arr[hashIndex][i].key == key) return false;

    arr[hashIndex].push_back(*new Node<K, V>(key, value));
    this->size++;
    return true;
}

template<typename K, typename V>
V HashMap<K, V>::deleteNode(K key) {
    unsigned int hashIndex = hashCode( key );
    for(int i = 0; i < arr[hashIndex].size(); i++){
        if( arr[hashIndex].at(i).key == key){
            V val = arr[hashIndex].at(i).value;
            arr[hashIndex].erase(arr[hashIndex].begin()+i);
            this->size--;
            return val;
        }
    }
}

template<typename K, typename V>
V HashMap<K, V>::get(K key) {
    unsigned int hashIndex = hashCode( key );
    for(int i = 0; i < arr[hashIndex].size(); i++){
        if( arr[hashIndex].at(i).key == key){
            return arr[hashIndex].at(i).value;
        }
    }
}

template<typename K, typename V>
bool HashMap<K, V>::contains(K key) {
    unsigned int hashIndex = hashCode( key );
    for(int i = 0; i < arr[hashIndex].size(); i++){
        if( arr[hashIndex].at(i).key == key){
            return true;
        }
    }
    return false;
}

template<typename K, typename V>
bool HashMap<K, V>::set(K key, V value) {
    unsigned int hashIndex = hashCode( key );
    for(int i = 0; i < arr[hashIndex].size(); i++){
        if( arr[hashIndex].at(i).key == key){
            arr[hashIndex].at(i).value = value;
            return true;
        }
    }
    return false;
}

template<typename K, typename V>
int HashMap<K, V>::sizeofMap() {
    return size;
}

template<typename K, typename V>
int HashMap<K, V>::getCapacity() {
    return capacity;
}

template<typename K, typename V>
HashMap<K, V>::HashMap(unsigned int capacity) {

    this->capacity = capacity;
    size = 0;
    arr = new vector< Node<K, V> > [capacity];
    for (int i = 0; i < capacity; i++){
        arr[i] = * new vector< Node<K, V> >;
    }

}
