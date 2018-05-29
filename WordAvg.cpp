//
// Created by guedes on 5/27/18.
//

#include "WordAvg.h"

WordAvg::WordAvg(string &w, int grade) {
    this->grades = *new vector<int>();
    this->word = w;
    this->grades.push_back(grade);
    this->count++;
}

void WordAvg::add(int grade) {
    this->grades.push_back(grade);
    this->count++;
}

void WordAvg::generateParcialSun() {
    float p = 0;
    for (int i = 0; i < this->grades.size(); i++) {
        p += this->grades[i];
    }
    this->setPartialSum(p);
}

void WordAvg::setWord(const string &word) {
    WordAvg::word = word;
}

void WordAvg::setGrades(const vector<int> &grades) {
    WordAvg::grades = grades;
}

void WordAvg::setCount(int count) {
    WordAvg::count = count;
}

void WordAvg::setPartialSum(float partialSum) {
    WordAvg::partialSum = partialSum;
}

void WordAvg::setAvg(float avg) {
    WordAvg::avg = avg;
}

bool WordAvg::operator<(const WordAvg &rhs) const {
    return word < rhs.word;
}

bool WordAvg::operator>(const WordAvg &rhs) const {
    return rhs < *this;
}

bool WordAvg::operator<=(const WordAvg &rhs) const {
    return !(rhs < *this);
}


bool WordAvg::operator>=(const WordAvg &rhs) const {
    return !(*this < rhs);
}


bool WordAvg::operator==(const WordAvg &rhs) const {
    return word == rhs.word;
}

bool WordAvg::operator!=(const WordAvg &rhs) const {
    return !(rhs == *this);
}


float WordAvg::generateAvg() {
    this->generateParcialSun();
    this->setAvg(this->partialSum / this->count);
    return this->getAvg();
}

float WordAvg::getAvg() {
    return  WordAvg::avg;
}
