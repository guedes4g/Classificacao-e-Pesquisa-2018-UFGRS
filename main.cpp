#include <iostream>
#include <tensorflow/c/c_api.h>


#include "BTree.cpp"
#include "HashMap.cpp"
void debugHash();















void debugHash(){
    printf("Hello from TensorFlow C library version %s\n", TF_Version());

    auto *map = new HashMap<string, unsigned int>(100);
    cout << "insert 1" << endl;
    map->insertNode("asa",3);    cout << "insert 2" << endl;

    map->insertNode("aaa",3);    cout << "insert 3" << endl;

    map->insertNode("aba",3);    cout << "insert 4" << endl;
    map->insertNode("aba",3);    cout << "insert 4" << endl;
//
//    map->insertNode("asa",3);    cout << "insert 5" << endl;
//
//    map->insertNode("asa",3);    cout << "insert 6" << endl;
//
//    map->insertNode("asa",3);    cout << "insert 7" << endl;
//
//    map->insertNode("asa",3);    cout << "insert 8" << endl;

    map->set("asa",4);
    cout << "after set "<< map->get("asa") << endl;
    cout << map->get("aaa") << endl;
    map->deleteNode("asa")  ;
    cout << " -- -- -- --" << endl;
    map->deleteNode("asa") ;
    cout << map->get("asa") << endl;

    cout << map->sizeofMap() << endl;
}