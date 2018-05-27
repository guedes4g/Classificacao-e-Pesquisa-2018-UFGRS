//
// Created by guedes on 5/27/18.
//


#ifndef CPD_FINAL_WORDAVG_H

using namespace std;
#include <string>
#include <vector>

class WordAvg {
public:
    string word;
    vector<int> grades;
    int count = 0;
    float partialSun = 0;
    float avg = 0;

    explicit WordAvg(string &w, int grade);

    void add(int grade);

    void generateParcialSun();

    float generateAvg();

    float getAvg();

    bool operator<(const WordAvg &rhs) const;

    bool operator>(const WordAvg &rhs) const;

    bool operator<=(const WordAvg &rhs) const;

    bool operator>=(const WordAvg &rhs) const;

    bool operator==(const WordAvg &rhs) const;

    bool operator!=(const WordAvg &rhs) const;
};

#define CPD_FINAL_WORDAVG_H

#endif //CPD_FINAL_WORDAVG_H
