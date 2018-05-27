//
// Created by guedes on 5/26/18.
//

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "WordInfo.cpp"

using namespace std;

class Helper{
public:
    vector<WordInfo*> static readFile(){
        ifstream in("train.tsv");
        vector<WordInfo*>  output = *new vector<WordInfo *> ;

        if(!in) {
            cout << "\nerror: { Cannot open input file } \n";
            exit(1);
        }
        string line;
        string token;
        string pices [4];
        int i;
        std::string::size_type sz;
        std::getline(in, line);
        while (std::getline(in, line)) {
            i=0;
            std::istringstream iss(line);
            while(std::getline(iss, token, '\t') && i < 4){
                pices[i] = token;
                i++;
            }
            output.push_back(new WordInfo (stoi(pices[0]), stoi(pices[1]), pices[2], stoi(pices[3]) ));
        }
        return output;
    }
};


