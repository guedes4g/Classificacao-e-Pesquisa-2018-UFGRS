//
// Created by guedes on 5/27/18.
//

#include "WordAvg.h"

WordAvg::WordAvg(string &w, int wordPos, int grade, int phraseId , string phrase) {
    this->wordPosition= *new vector<int>();
    this->grades = *new vector<int>();
    //this->phrases = *new vector<string>();
    this->word = w;
    this->wordPosition.push_back(wordPos);
    //this->phrases.push_back(phrase);
    this->phrasesIds.push_back(phraseId);
    this->grades.push_back(grade);
    this->count++;
}

void WordAvg::add(int wordpos, int grade, int phraseId , string phrase) {
    this->wordPosition.push_back(wordpos);
    this->grades.push_back(grade);
    //this->phrases.push_back(phrase);
    this->phrasesIds.push_back(phraseId);
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
    this->word = word;
}

void WordAvg::setGrades(const vector<int> &grades) {
    this->grades = grades;
}

void WordAvg::setCount(int count) {
    this->count = count;
}

void WordAvg::setPartialSum(float partialSum) {
    this->partialSum = partialSum;
}

void WordAvg::setAvg(float avg) {
    this->avg = avg;
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
    return  this->avg;
}

WordAvg::WordAvg() = default;
