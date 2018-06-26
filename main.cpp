//#include <iostream>
//#include <tensorflow/c/c_api.h>

#include <iostream>
//#include <string>
#include <vector>


#include "Helper.cpp"
#include "BTree.cpp"
#include "HashMap.cpp"
#include "WordAvg.h"
//void debugHash();

using namespace std;

//Ramiro: para manipular strings tive de inserir esse namespace para usar insert nas strings
using namespace std::__cxx11;



int inputAvg( HashMap<string, WordAvg* >  &map);
void inputListCommentsByWords( HashMap<string, WordAvg* >  &map);
void inputPrefixSearch( HashMap<string, WordAvg* >  &map, vector<WordInfo* > raw);
void inputFile( HashMap<string, WordAvg* > &map, string filePath);


HashMap<string, WordAvg* > strategyOne(vector<WordInfo* > raw){
    //vector<WordInfo* > raw =  Helper::readFile();
    HashMap<string, WordAvg* > map(335941);
    Helper::generateHashWordAvg(raw, map);
    //return(map);
    //inputAvg(map);

    //Trie<WordInfo *> trie = Helper::generateTrie(raw);
    //vector <pair<string, vector<WordInfo*>>> v = trie.searchStartingWith("i");
    //for(auto aux: v){
    //    cout << aux.first << ",  " << endl;
        //for(int j = 0; aux.second.size(); j++){
            //cout << aux.second[j]->getPhraseId() << endl;
        //}
    //}
    return(map);
}

int main(int argc, char **argv){
    if(argc<3){
        vector<WordInfo* > raw =  Helper::readFile();
        HashMap<string, WordAvg* > mapa=strategyOne(raw);
        if(argc==1){
            char flag={0};
            do
            {
                cout << "\t\t\t1 - Avaliar novo comentario" << endl;
                cout << "\t\t\t2 - Listar ocorrencias" << endl;
                cout << "\t\t\t3 - Listar comentarios por palavra" << endl;
                cout << "\t\t\t4 - Busca por prefixo" << endl;
                cout << "\t\t\tq - Encerrar" << endl;
                cout << "Selecione uma opcao valida: ";
                string input="";
                getline(cin, input);
                if (input.length() == 1) {
                     flag = input[0];
                    //cout << (int)flag << endl;
                    switch(flag)
                    {
                        case '1': inputAvg(mapa);
                        break;
                        case '2':;
//                            int tamLista=3;
//                            int lista[3]={0};
//                            for (int i = 0; i < mapa.getCapacity(); i++) {
//                                for (auto &wordavg : mapa.arr[i]) {
//                                    if(lista[0]<=wordavg.value->count)
//                                    {
//                                        lista[0]=wordavg.value->count;
//
//                                        cout << lista[0] << " - " << wordavg.value->word << endl;
//                                    }
//                                    //cout << wordavg.value->count << endl;
//                                }
//                            }
                        break;
                        case '3': inputListCommentsByWords(mapa);
                        break;
                        case '4':inputPrefixSearch(mapa, raw);
                        break;

                    }
                }
            }while(tolower(flag)!='q');
        }
        else{
            inputFile(mapa, ((string)argv[1]));
        }
    }
    else
    {
        cout << "usage: " << ((string)argv[0]) << " [filePath]" << endl;
    }
    return 0;
}

int inputAvg( HashMap<string, WordAvg* > &map){
    string str;
    do{
        cout << "Escreva uma frase para ser avaliada ou aperte Enter para encerrar:" << endl;
        getline( cin, str );
        vector<string> v;
        istringstream iss (str);
        string s;
        while ( getline( iss, s, ' ' ) ) {
            //cout << s << endl;
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
            float avg=(sum/i);
            cout << "Média: " << avg << endl;
            if(avg>2)
            {
                cout << "Sentimento positivo." << endl;
            }else
            if(avg<2)
            {
                cout << "Sentimento negativo." << endl;
            }else
            cout << "Sentimento neutro." << endl;
        }
    }
    while(str.length()>0);
}




void inputListCommentsByWords( HashMap<string, WordAvg* >  &mapa)
{
    string str;
    do{
        cout << "\nEscreva uma palavra para ser avaliada, use + ou - para separar por polaridade, \nou aperte Enter para encerrar:" << endl;
        getline( cin, str );
        vector<string> v;
        istringstream iss (str);
        string s;
        bool flagPolaridade=false, polaridade=false;
        while ( getline( iss, s, ' ' ) ) {
            //cout << s << endl;
            v.push_back(s);
        }
        if(v.size()>1)
        {
            if(v[1]=="+")
            {
                flagPolaridade=true;
                polaridade=true;// true para polaridade  positiva
            }else if(v[1]=="-")
            {
                flagPolaridade=true;
            }
        }
        if(v.size()>0 && mapa.contains(v[0])){
                for(int i=0 ; i<mapa.get(v[0])->count ; i++)
                {
                    if(flagPolaridade)
                    {
                        if(polaridade)
                        {
                            if(mapa.get(v[0])->grades[i]>2)
                            {
                                cout << "Id Frase: " << mapa.get(v[0])->phrasesIds[i];
                                cout << " Nro Palavra  " << mapa.get(v[0])->wordPosition[i];
                                cout << " Sentimento: " << mapa.get(v[0])->grades[i] << endl;
                            }
                        }else
                        {
                            if(mapa.get(v[0])->grades[i]<2)
                            {
                                cout << "Id Frase: " << mapa.get(v[0])->phrasesIds[i];
                                cout << " Nro Palavra  " << mapa.get(v[0])->wordPosition[i];
                                cout << " Sentimento: " << mapa.get(v[0])->grades[i] << endl;
                            }
                        }
                    }
                    else
                    {
                        cout << "Id Frase: " << mapa.get(v[0])->phrasesIds[i];
                        cout << " Nro Palavra  " << mapa.get(v[0])->wordPosition[i];
                        cout << " Sentimento: " << mapa.get(v[0])->grades[i] << endl;
                    }
                }
            }
    }
    while(str.length()>0);
}

void inputPrefixSearch(HashMap<string, WordAvg*>& map, vector<WordInfo* >raw)
{
    string str;
    do{
        cout << "Insira o prefixo de interesse ou aperte Enter para encerrar:" << endl;
        getline( cin, str );
        vector<string> v;
        istringstream iss (str);
        string s;
        while ( getline( iss, s, ' ' ) ) {
            //cout << s << endl;
            v.push_back(s);
        }
        if(v.size()>0)
        {
            Trie<WordInfo *> trie = Helper::generateTrie(raw);
            vector <pair<string, vector<WordInfo*>>> vec = trie.searchStartingWith(v[0]);
            cout << "Palavras que iniciam com: " << v[0] << endl;
            for(auto aux: vec){
                aux.first.erase(aux.first.begin());
                cout << v[0] << aux.first << endl;
                //for(int j = 0; aux.second.size(); j++){
                    //cout << aux.second[j]->getPhraseId() << endl;
                    //cout << aux.first[j] << endl;
                //}
            }
        }

    }
    while(str.length()>0);
}

void inputFile( HashMap<string, WordAvg* > &map, string filePath){

        ifstream in(filePath);
        ofstream out(filePath.insert(filePath.length()-4 , "_out") );
        cout << filePath << "  file"<< endl;
        vector<WordInfo*>  output = *new vector<WordInfo *> ;

        if(!in) {
            cout << "\nerror: { Cannot open input files } \n";
            exit(1);
        }
        string line;
        string token;
        //string pices [4];
        //int i;
        //std::string::size_type sz;
        while(getline(in, line))
        {
            vector<string> v;
            istringstream iss (line);
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
                float avg=(sum/i);
                cout << "Média: " << avg << endl;
                out<<avg<<'\t'<<line<<endl;
            }
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
