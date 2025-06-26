#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>

using namespace std;

int main()
{
    // Input file streams
    ifstream finnish_file("../finnish.txt");
    ifstream english_file("../english.txt");

    // Word containers as vectors
    vector<string> finnish_words;
    vector<string> english_words;

    string line;

    // Retrieving words from the files
    while(getline(finnish_file, line)) {
        finnish_words.push_back(line);
    }
    finnish_file.close();

    while(getline(english_file, line)) {
        english_words.push_back(line);
    }
    english_file.close();

    // Generate a random index from 0 to vector size
    random_device seed;
    mt19937 gen{seed()};
    uniform_int_distribution<> dist{0, static_cast<int>(finnish_words.size() - 1)};
    int choice = dist(gen);

    // Print the finnish word, then ask for the english translation
    cout << "The word is: " << finnish_words[choice] << endl;
    cout << "Translation: ";

    string input;
    getline(cin, input);

    if (input == english_words[choice]) {
        cout << "Correct, the word was: " << english_words[choice] << endl;
    } else {
        cout << "False, correct form is: " + english_words[choice] << endl;
    }

    return 0;
}
