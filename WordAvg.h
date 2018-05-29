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
    float partialSum = 0;
    float avg = 0;

    WordAvg();
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

    const string &getWord() const {
        return word;
    }

    const vector<int> &getGrades() const {
        return grades;
    }

    int getCount() const {
        return count;
    }

    float getPartialSum() const {
        return partialSum;
    }

    void setWord(const string &word);

    void setGrades(const vector<int> &grades);

    void setCount(int count);

    void setPartialSum(float partialSum);

    void setAvg(float avg);
};

#define CPD_FINAL_WORDAVG_H

#endif //CPD_FINAL_WORDAVG_H
