/* Finnish Word Game
 * main.cpp
 *
 * Description:
 *  A simple word game to help learn Finnish vocabulary.
 *  The game is a quiz-type game where you need to find
 *  the correct translation of the given word. The words
 *  are obtained from https://1000mostcommonwords.com.
 *
 * For the GUI of this project, the open sourced C++ library
 * SFML was used. https://www.sfml-dev.org/
 * License: https://www.sfml-dev.org/license/
 *
 * Author : Kaan Pide
 * Created: 26.06.2025
 */

#include "UI.h"
#include <iostream>

using namespace std;

int main()
{
    UI window;
    window.mainLoop();

    return 0;
}
