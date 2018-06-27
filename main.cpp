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



void inputAvg( HashMap<string, WordAvg* >  &mapa, bool modeloAntigo);
void inputListCommentsByWords( HashMap<string, WordAvg* >  &mapa, bool modeloAntigo);
void inputPrefixSearch( HashMap<string, WordAvg* >  &mapa, Trie<WordInfo *> trie, bool modeloAntigo);
void inputFile( HashMap<string, WordAvg* > &mapa, string filePath, bool modeloAntigo);


HashMap<string, WordAvg* > strategyOne(vector<WordInfo* > raw, bool modeloAntigo=false){
    //vector<WordInfo* > raw =  Helper::readFile();
    HashMap<string, WordAvg* > mapa(335941);
    Helper::generateHashWordAvg(raw, mapa, modeloAntigo);
    //return(mapa);
    //inputAvg(mapa);

    //Trie<WordInfo *> trie = Helper::generateTrie(raw);
    //vector <pair<string, vector<WordInfo*>>> v = trie.searchStartingWith("i");
    //for(auto aux: v){
    //    cout << aux.first << ",  " << endl;
        //for(int j = 0; aux.second.size(); j++){
            //cout << aux.second[j]->getPhraseId() << endl;
        //}
    //}
    return(mapa);
}

int main(int argc, char **argv){
    if(argc<3){
        bool flagModeloAntigo=false;
        vector<WordInfo* > raw =  Helper::readFile();
        Trie<WordInfo *> trie = Helper::generateTrie(raw);
        HashMap<string, WordAvg* > mapaRefinado=strategyOne(raw, flagModeloAntigo);
        HashMap<string, WordAvg* > mapaAntigo=strategyOne(raw, !flagModeloAntigo);
        HashMap<string, WordAvg* > *mapa = flagModeloAntigo ? &mapaAntigo : &mapaRefinado;

        if(argc==1){
            char flag={0};
            do
            {
                cout << "\t\t\t1 - Avaliar novo comentario" << endl;
                cout << "\t\t\t2 - Listar ocorrencias" << endl;
                cout << "\t\t\t3 - Listar comentarios por palavra" << endl;
                cout << "\t\t\t4 - Busca por prefixo" << endl;
                if(flagModeloAntigo)
                {
                    cout << "\t\t\t5 - Carregar modelo refinado" << endl;
                }else
                {
                    cout << "\t\t\t5 - Carregar modelo inicial" << endl;
                }
                cout << "\t\t\tq - Encerrar" << endl;
                cout << "Selecione uma opcao valida: ";
                string input="";
                getline(cin, input);
                if (input.length() == 1) {
                     flag = input[0];
                    //cout << (int)flag << endl;
                    switch(flag)
                    {
                        case '1': inputAvg(*mapa, flagModeloAntigo);
                        break;
                        case '2':;
//                            int tamLista=3;
//                            int lista[3]={0};
//                            for (int i = 0; i < mapaa.getCapacity(); i++) {
//                                for (auto &wordavg : mapaa.arr[i]) {
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
                        case '3': inputListCommentsByWords(*mapa, flagModeloAntigo);
                        break;
                        case '4': inputPrefixSearch(*mapa, trie, flagModeloAntigo);
                        break;
                        case '5':flagModeloAntigo=!flagModeloAntigo;
                            system("cls");
                            cout <<"Carregando modelo...";
                            mapa=flagModeloAntigo ? &mapaAntigo : &mapaRefinado;
                            //mapa=strategyOne(raw, flagModeloAntigo);
                            system("cls");

                        break;
                    }
                }
            }while(tolower(flag)!='q');
        }
        else{
            inputFile(*mapa, ((string)argv[1]), flagModeloAntigo);
        }
    }
    else
    {
        cout << "usage: " << ((string)argv[0]) << " [filePath]" << endl;
    }
    return 0;
}

void inputAvg( HashMap<string, WordAvg* > &mapa, bool modeloAntigo){
    string str;
    do{
        cout << "Escreva uma frase para ser avaliada ou aperte Enter para encerrar:" << endl;
        getline( cin, str );
        if(!modeloAntigo)
        {
            for(char &temp : str)
            {
                temp=tolower(temp);
            }
        }
        vector<string> v;
        istringstream iss (str);
        string s;
        while ( getline( iss, s, ' ' ) ) {
            //cout << s << endl;
            v.push_back(s);
        }
        float sum = 0, i = 0;
        for(const string &word: v){
            if(mapa.contains(word)){
                sum += mapa.get(word)->getAvg();
                i++;
            }
        }
        if(i){
            float avg=(sum/i);
            cout << "Media: " << avg << endl;
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




void inputListCommentsByWords( HashMap<string, WordAvg* >  &mapaa, bool modeloAntigo)
{
    string str;
    do{
        cout << "\nEscreva uma palavra para ser avaliada, use + ou - para separar por polaridade, \nou aperte Enter para encerrar:" << endl;
        getline( cin, str );
        if(!modeloAntigo)
        {
            for(char &temp : str)
            {
                temp=tolower(temp);
            }
        }
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
        if(v.size()>0 && mapaa.contains(v[0])){
                for(int i=0 ; i<mapaa.get(v[0])->count ; i++)
                {
                    if(flagPolaridade)
                    {
                        if(polaridade)
                        {
                            if(mapaa.get(v[0])->grades[i]>2)
                            {
                                cout << "Id Frase: " << mapaa.get(v[0])->phrasesIds[i];
                                cout << " Nro Palavra  " << mapaa.get(v[0])->wordPosition[i];
                                cout << " Sentimento: " << mapaa.get(v[0])->grades[i] << endl;
                            }
                        }else
                        {
                            if(mapaa.get(v[0])->grades[i]<2)
                            {
                                cout << "Id Frase: " << mapaa.get(v[0])->phrasesIds[i];
                                cout << " Nro Palavra  " << mapaa.get(v[0])->wordPosition[i];
                                cout << " Sentimento: " << mapaa.get(v[0])->grades[i] << endl;
                            }
                        }
                    }
                    else
                    {
                        cout << "Id Frase: " << mapaa.get(v[0])->phrasesIds[i];
                        cout << " Nro Palavra  " << mapaa.get(v[0])->wordPosition[i];
                        cout << " Sentimento: " << mapaa.get(v[0])->grades[i] << endl;
                    }
                }
            }
    }
    while(str.length()>0);
}

void inputPrefixSearch(HashMap<string, WordAvg*>& mapa, Trie<WordInfo *> trie, bool modeloAntigo)
{
    string str;
    do{
        cout << "Insira o prefixo de interesse ou aperte Enter para encerrar:" << endl;
        getline( cin, str );
        //if(!modeloAntigo)
        {
            for(char &temp : str)
            {
                temp=tolower(temp);
            }
        }
        vector<string> v;
        istringstream iss (str);
        string s;
        while ( getline( iss, s, ' ' ) ) {
            //cout << s << endl;
            v.push_back(s);
        }
        if(v.size()>0)
        {
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
            trie.~Trie();
        }

    }
    while(str.length()>0);
}

void inputFile( HashMap<string, WordAvg* > &mapa, string filePath, bool modeloAntigo){

        ifstream in(filePath);
        if(!in) {
            cout << "\nerror: { Cannot open input files } \n";
            exit(1);
        }
        ofstream out(filePath.insert(filePath.length()-4 , "_out") );
        cout << filePath << "  file"<< endl;
        vector<WordInfo*>  output = *new vector<WordInfo *> ;
        string line;
        string token;
        //string pices [4];
        //int i;
        //std::string::size_type sz;
        while(getline(in, line))
        {
            if(!modeloAntigo)
            {
                for(char &temp : line)
                {
                    temp=tolower(temp);
                }
            }
            vector<string> v;
            istringstream iss (line);
            string s;
            while ( getline( iss, s, ' ' ) ) {
                cout << s << endl;
                v.push_back(s);
            }
            float sum = 0, i = 0;
            for(const string &word: v){
                if(mapa.contains(word)){
                    sum += mapa.get(word)->getAvg();
                    i++;
                }
            }
            if(i){
                float avg=(sum/i);
                //cout << "Media: " << avg << endl;
                out<<avg<<'\t'<<line<<endl;
            }
        }

}


//void debugHash(){
//    printf("Hello from TensorFlow C library version %s\n", TF_Version());
//
//    auto *mapa = new HashMap<string, unsigned int>(100);
//    cout << "insert 1" << endl;
//    mapa->insertNode("asa",3);    cout << "insert 2" << endl;
//
//    mapa->insertNode("aaa",3);    cout << "insert 3" << endl;
//
//    mapa->insertNode("aba",3);    cout << "insert 4" << endl;
//    mapa->insertNode("aba",3);    cout << "insert 4" << endl;
//
//    mapa->set("asa",4);
//    cout << "after set "<< mapa->get("asa") << endl;
//    cout << mapa->get("aaa") << endl;
//    mapa->deleteNode("asa")  ;
//    cout << " -- -- -- --" << endl;
//    mapa->deleteNode("asa") ;
//    cout << mapa->get("asa") << endl;
//
//    cout << mapa->sizeofMap() << endl;
//}
