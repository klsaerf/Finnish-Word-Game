//
// Created by Kaan Pide on 26.06.2025.
//

#include "WordGame.h"
#include <random>
#include <iostream>
#include <fstream>

WordGame::WordGame() {
    retrieveWords_();
}

WordGame::~WordGame() = default;

void WordGame::askQuestion() const {
    const int choice = randomIndex_();
    // Print the finnish word, then ask for the english translation
    cout << "The word is: " << finnish_words_[choice] << endl;
    cout << "Translation: ";

    string input;
    getline(cin, input);

    // check for correct answer
    if (input == english_words_[choice]) {
        cout << "Correct, the word was: " << english_words_[choice] << endl;
    } else {
        cout << "False, correct form is: " + english_words_[choice] << endl;
    }
}

void WordGame::retrieveWords_() {
    // Input file streams
    ifstream finnish_file("../finnish.txt");
    ifstream english_file("../english.txt");

    string line;

    // Retrieving words from the files
    while(getline(finnish_file, line)) {
        finnish_words_.push_back(line);
    }
    finnish_file.close();

    while(getline(english_file, line)) {
        english_words_.push_back(line);
    }
    english_file.close();
}

int WordGame::randomIndex_() const {
    // Generate a random index from 0 to vector size
    random_device seed;
    mt19937 gen{seed()};
    uniform_int_distribution<> dist{0, static_cast<int>(finnish_words_.size() - 1)};
    return dist(gen);
}
