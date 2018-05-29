#include <iostream>
#include <tensorflow/c/c_api.h>
#include <vector>
#include <iostream>


#include "Helper.cpp"
#include "BTree.cpp"
#include "HashMap.cpp"
#include "WordAvg.h"
//void debugHash();

using namespace std;



int inputAvg( HashMap<string, WordAvg* >  &map);

void strategyOne(){
    vector<WordInfo* > raw =  Helper::readFile();
    HashMap<string, WordAvg* > map(335941);
    Helper::generateHashWordAvg(raw, map);

   // Helper::generateTrie(raw);
    inputAvg(map);
}

int main(){
    strategyOne();

    return 0;
}

int inputAvg( HashMap<string, WordAvg* > &map){
    string str;
    cout << "Escreve uma frase para ser avaliada:" << endl;
    getline( cin, str );
    vector<string> v;
    istringstream iss (str);
    string s;
    while ( getline( iss, s, ' ' ) ) {
        cout << s << endl;
        v.push_back(s);
    }
    float sum = 0, i = 0;
    for(const string &word: v){
        if(map.contains(word)){
            sum += map.get(word)->getAvg();
            i++;
        }
    }

    if(i){
        cout << "Média: " << (sum/i)<< endl;
    }
}

//void debugHash(){
//    printf("Hello from TensorFlow C library version %s\n", TF_Version());
//
//    auto *map = new HashMap<string, unsigned int>(100);
//    cout << "insert 1" << endl;
//    map->insertNode("asa",3);    cout << "insert 2" << endl;
//
//    map->insertNode("aaa",3);    cout << "insert 3" << endl;
//
//    map->insertNode("aba",3);    cout << "insert 4" << endl;
//    map->insertNode("aba",3);    cout << "insert 4" << endl;
//
//    map->set("asa",4);
//    cout << "after set "<< map->get("asa") << endl;
//    cout << map->get("aaa") << endl;
//    map->deleteNode("asa")  ;
//    cout << " -- -- -- --" << endl;
//    map->deleteNode("asa") ;
//    cout << map->get("asa") << endl;
//
//    cout << map->sizeofMap() << endl;
//}