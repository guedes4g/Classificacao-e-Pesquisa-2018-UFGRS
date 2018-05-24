//#include<bits/stdc++.h>
//#include <bits/hash_bytes.h>
//
//using namespace std;
//using byte = unsigned char ;
//
//template<typename K, typename V>
//class Node {
//public:
//    V value;
//    K key;
//
//    Node(K key, V value) {
//        this->value = value;
//        this->key = key;
//    }
//
//};
//template<typename K, typename V>
//class HashMap {
//    vector<Node<K, V>> *arr;
//    size_t capacity;
//    size_t size;
//
//public:
//    HashMap(unsigned int capacity) {
//
//        this->capacity = capacity;
//        size = 0;
//        arr = new vector< Node<K, V> > [capacity];
//        for (int i = 0; i < capacity; i++){
//            arr[i] = * new vector< Node<K, V> >;
//        }
//
//    }
//
//
//    unsigned int
//    hashCode( K object )
//    {
//        std::array< byte, sizeof(K) > bytes ;
//
//        const byte* begin = reinterpret_cast< const byte* >( std::addressof(object) ) ;
//        const byte* end = begin + sizeof(K) ;
//        std::copy( begin, end, std::begin(bytes) ) ;
//        unsigned int sum = 7, v = 3, i = 1;
//        for( byte b : bytes ){
//            sum += v*(unsigned int)b;
//
//        }
//        return (sum % this->capacity) ;
//    }
//
//
//    bool insertNode(K key, V value) {
//        unsigned int hashIndex = hashCode( key );
//        cout << "Key = "<< key << "  ,Hash = " << hashIndex << endl;
//        for(int i = 0; i < arr[hashIndex].size(); i++)
//            if (arr[hashIndex][i].key == key) return false;
//
//        arr[hashIndex].push_back(*new Node<K, V>(key, value));
//        this->size++;
//        return true;
//    }
//
//    V deleteNode(K key) {
//        unsigned int hashIndex = hashCode( key );
//        for(int i = 0; i < arr[hashIndex].size(); i++){
//            if( arr[hashIndex].at(i).key == key){
//                V val = arr[hashIndex].at(i).value;
//                arr[hashIndex].erase(arr[hashIndex].begin()+i);
//                this->size--;
//                return val;
//            }
//        }
//        return NULL;
//    }
//
//    V get(K key) {
//        unsigned int hashIndex = hashCode( key );
//        for(int i = 0; i < arr[hashIndex].size(); i++){
//            if( arr[hashIndex].at(i).key == key){
//                return arr[hashIndex].at(i).value;
//            }
//        }
//        return NULL;
//    }
//
//    bool contains(K key) {
//        unsigned int hashIndex = hashCode( key );
//        for(int i = 0; i < arr[hashIndex].size(); i++){
//            if( arr[hashIndex].at(i).key == key){
//                return true;
//            }
//        }
//        return false;
//    }
//
//    bool set(K key, V value) {
//        unsigned int hashIndex = hashCode( key );
//        for(int i = 0; i < arr[hashIndex].size(); i++){
//            if( arr[hashIndex].at(i).key == key){
//                arr[hashIndex].at(i).value = value;
//                return true;
//            }
//        }
//        return false;
//    }
//    int sizeofMap() {
//        return size;
//    }
//
//    int getCapacity(){
//        return capacity;
//    }
//
//    bool isEmpty() {
//        return size == 0;
//    }
//
//};
