//
// Created by guedes on 5/26/18.
//

#include <string>
#include <vector>
#include <ostream>
#include <sstream>

using namespace std;



class WordInfo{
private:
    int PhraseId;
    int SentenceId;
    string Phrase;
    int sentiment;
    vector<string> words;
public:

    explicit WordInfo(int PhraseId, int SentenceId, const string &Phrase, int sentiment) {
        this->PhraseId = PhraseId;
        this->SentenceId = SentenceId;
        this->Phrase = Phrase;
        this->sentiment = sentiment;
        this->words = this->generateWords(Phrase);
    }

    vector<string> generateWords(const string &str) {
        vector<string> v;
        istringstream iss (str);
        string s;
        while ( getline( iss, s, ' ' ) ) {
            v.push_back(s);
        }
        return v;
    }

    const vector<string> &getWords() const {
        return words;
    }

    void setWords(const vector<string> &words) {
        WordInfo::words = words;
    }

    int getPhraseId() const {
        return PhraseId;
    }

    void setPhraseId(int PhraseId) {
        WordInfo::PhraseId = PhraseId;
    }

    int getSentenceId() const {
        return SentenceId;
    }

    void setSentenceId(int SentenceId) {
        WordInfo::SentenceId = SentenceId;
    }

    const string &getPhrase() const {
        return Phrase;
    }

    void setPhrase(const string &Phrase) {
        WordInfo::Phrase = Phrase;
    }

    int getSentiment() const {
        return sentiment;
    }

    void setSentiment(int sentiment) {
        WordInfo::sentiment = sentiment;
    }

    bool operator==(const WordInfo &rhs) const {
        return PhraseId == rhs.PhraseId &&
               SentenceId == rhs.SentenceId &&
               Phrase == rhs.Phrase &&
               sentiment == rhs.sentiment;
    }

    bool operator!=(const WordInfo &rhs) const {
        return !(rhs == *this);
    }

    friend ostream &operator<<(ostream &os, const WordInfo &info) {
        os << "PhraseId: " << info.PhraseId << " SentenceId: " << info.SentenceId << " Phrase: " << info.Phrase
           << " sentiment: " << info.sentiment;
        return os;
    }
};