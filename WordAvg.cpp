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
    this->partialSun = p;
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
    this->avg = (this->partialSun / this->count);
    return this->avg;
}

float WordAvg::getAvg() {
    return this->avg;
}
