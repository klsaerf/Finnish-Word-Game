//
// Created by Kaan Pide on 7.07.2025.
//

#ifndef UI_H
#define UI_H

#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class UI {
public:
    UI();
    virtual ~UI();

    // The main loop of the gui
    void mainLoop();
private:
    // The display window, core of gui
    RenderWindow window_;
};



#endif //UI_H
