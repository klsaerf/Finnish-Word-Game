//
// Created by Kaan Pide on 26.06.2025.
//

#ifndef WORDGAME_H
#define WORDGAME_H

#include <string>
#include <vector>

using namespace std;

class WordGame {
public:
    WordGame();
    virtual ~WordGame();

    // Void function that asks a question
    // This function will be improved later
    void askQuestion() const;
private:
    // Void function retrieving words from
    // the correspondig word files and
    // puts them into the vector containers
    void retrieveWords_();

    // Int function that returns a random
    // index from 0 to the finnish_words_
    // vector's size
    int randomIndex_() const;

    // Word containers as vectors
    vector<string> finnish_words_;
    vector<string> english_words_;
};



#endif //WORDGAME_H
