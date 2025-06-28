//
// Created by Kaan Pide on 26.06.2025.
//

#include "WordGame.h"
#include <random>
#include <iostream>
#include <fstream>

// Helper function that returns a random number from begin to end
int randomNumber(const int begin, const int end) {
    random_device seed;
    mt19937 gen{seed()};
    uniform_int_distribution<> dist{begin, end};
    return dist(gen);
}

// Helper function that shuffles a given vector<int>
void shuffleVector(vector<int>& v) {
    random_device seed;
    mt19937 gen{seed()};
    return shuffle(v.begin(), v.end(), gen);
}

WordGame::WordGame() {
    retrieveWords_();
}

WordGame::~WordGame() = default;

void WordGame::askQuestion() {
    // The vector containing the indexes of the answers
    vector<int> choices;

    // Populating the vector with the indexes
    // 4 answers will be made a difficulty later
    for (int i = 0; i < 4; i++) {
        const int choice = randomNumber(0, static_cast<int>(finnish_words_.size()) - 1);

        // Ensure that answers are unique
        auto search = find(choices.begin(), choices.end(), choice);
        if (search != choices.end()) {
            i--;
            continue;
        }

        choices.push_back(choice);
    }

    // Choosing the correct choice before shuffling the vector
    const int correct_choice = choices[0];
    shuffleVector(choices);

    // Printing the finnish word
    cout << "The word is: " << finnish_words_[correct_choice] << endl;

    // Printing the english answers
    for (int i = 0; i < 4; i++) {
        cout << ANSWER_INDEX[i] << ") " << english_words_[choices[i]] << endl;
        if (choices[i] == correct_choice) {
            correct_answer_.first = ANSWER_INDEX[i];
            correct_answer_.second = choices[i];
        }
    }

    // Answer prompt
    cout << "Answer (a,b,c,d): ";
}

void WordGame::checkAnswer(char answer) const {
    // Check if the given answer is correct
    if (toupper(answer) == correct_answer_.first) {
        cout << "Correct! The answer was: " << english_words_[correct_answer_.second]  << endl;
    } else {
        cout << "Incorrect, the answer was: " << english_words_[correct_answer_.second] << endl;
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
