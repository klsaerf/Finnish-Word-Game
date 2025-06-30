/* Finnish Word Game
 * main.cpp
 *
 * Description:
 *  A simple word game to help learn Finnish vocabulary.
 *  The game is a quiz-type game where you need to find
 *  the correct translation of the given word. The words
 *  are obtained from https://1000mostcommonwords.com.
 *
 * Author : Kaan Pide
 * Created: 26.06.2025
 */

#include "WordGame.h"
#include <iostream>

using namespace std;

int main()
{
    WordGame game;

    // Difficulty choosing dialogue
    cout << "Choose a difficulty level (1 is easiest, 4 is hardest): ";
    int difficulty;
    cin >> difficulty;
    while (!game.setDifficulty(difficulty)) cin >> difficulty;

    // Main game loop
    while (true) {
        game.askQuestion();

        char ans;
        cin >> ans;

        if (toupper(ans) == 'Q') break;

        game.checkAnswer(ans);

    }


    return 0;
}
