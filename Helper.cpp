//
// Created by guedes on 5/26/18.
//

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <utility>      // std::pair

#include "WordInfo.cpp"
#include "WordAvg.h"
#include "HashMap.h"
#include "Trie.h"

using namespace std;

class Helper{
public:
    vector<WordInfo*> static readFile(){
        string filePath, fileExtension;
        ifstream in;
        do{
            cout << "Informe o nome do arquivo de treino ou Enter para encerrar: ";
            getline(cin,filePath);
            in.open(filePath);//"train.tsv");
            if(filePath.empty())
            {
                cout << "Programa encerrado.\n";
                exit(1);
            }
            if(!in) {
                system("cls");
                cout << "Arquivo nao encontrado!\n";
                //exit(1);
            }
        }while(!in);
        fileExtension.assign(filePath, filePath.length()-3, 3);
        vector<WordInfo*>  output = *new vector<WordInfo *> ;
        string line;
        string token;
        string pices [4];
        int i, lineNumber=1;
        std::string::size_type sz;
        if(fileExtension=="tsv"){
            std::getline(in, line);
        }
        while (std::getline(in, line)) {
            i=0;
            std::istringstream iss(line);
            if(fileExtension=="tsv"){
                while(std::getline(iss, token, '\t') && i < 4){
                    pices[i] = token;
                    i++;
                }
                output.push_back(new WordInfo (stoi(pices[0]), stoi(pices[1]), pices[2], stoi(pices[3]) ));
            }else{
                //while(std::getline(iss, token, ' ') && i < 1){
                //    pices[i] = token;
                //    i++;
                //}
                std::getline(iss, token, ' ');
                pices[0] = token;
                std::getline(iss, token);
                output.push_back(new WordInfo (lineNumber, lineNumber, token, stoi(pices[0]) ));
                lineNumber++;
            }
        }
        in.close();
        return output;
    }

    static void generateHashWordAvg(vector<WordInfo*> &vec, HashMap<string, WordAvg *> &mapa, bool modeloAntigo=false){
          for(WordInfo * info: vec){
            //for(string word : info->getWords()){
            for(unsigned int i=0; i<info->getWords().size(); i++){
                    vector<string> aux=info->getWords();
                    if(!modeloAntigo && aux[i].length()>2)
                    {
                        for(char &temp : aux[i])
                        {
                            temp=tolower(temp);
                        }
                        if(!mapa.insertNode(aux[i], new WordAvg(aux[i], i+1, info->getSentiment(), info->getPhraseId(), info->getPhrase()) )){
                            mapa.get(aux[i])->add(i+1, info->getSentiment(), info->getPhraseId(), info->getPhrase());
                        }
                    }
                    else
                    {
                        if(modeloAntigo)
                        {
                            if(!mapa.insertNode(aux[i], new WordAvg(aux[i], i+1, info->getSentiment(), info->getPhraseId(), info->getPhrase()) )){
                                mapa.get(aux[i])->add(i+1, info->getSentiment(), info->getPhraseId(), info->getPhrase());
                            }
                        }
                    }
            }
        }
        for (int i = 0; i < mapa.getCapacity(); i++) {
            for (auto &wordavg : mapa.arr[i]) {
                wordavg.value->generateAvg();
            }
        }
    };

    static Trie<WordInfo *> generateTrie(vector<WordInfo *> &vec) {

        auto * trie = new Trie<WordInfo *>();
        for (WordInfo *info : vec) {
            for (string w : info->getWords()) {
                trie->insert(w, info);
            }
        }


        return *trie;
    }

};


