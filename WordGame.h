//
// Created by Kaan Pide on 26.06.2025.
//

#ifndef WORDGAME_H
#define WORDGAME_H

#include <string>
#include <vector>

using namespace std;

// The pairing of answer indexes to integer indexes
const vector<char> ANSWER_INDEX = {'A', 'B', 'C', 'D'};

class WordGame {
public:
    WordGame();
    virtual ~WordGame();

    // Void function that asks a question
    // This function will be improved later
    void askQuestion();

    // Void function that checks the inputed
    // answer and prints the result accordingly
    void checkAnswer(char answer) const;
private:
    // Void function retrieving words from
    // the correspondig word files and
    // puts them into the vector containers
    void retrieveWords_();

    // Word containers as vectors
    vector<string> finnish_words_;
    vector<string> english_words_;

    // Stores the current correct answer
    // as a char-int pair, where:
    // first  -> the answer char (a,b,c,d)
    // second -> the answer's index in the
    //           word container
    pair<char, int> correct_answer_;
};



#endif //WORDGAME_H
