//
// Created by Kaan Pide on 7.07.2025.
//

#include "UI.h"

UI::UI():
    window_(RenderWindow(VideoMode::getDesktopMode(), "Finnish Word Game", Style::Close))
{

}

UI::~UI() = default;

void UI::mainLoop() {
    while (window_.isOpen()) {
        while (const std::optional event = window_.pollEvent()) {
            if (event->is<Event::Closed>()) window_.close();
        }

        window_.clear(Color::White);
        window_.display();
    }
}
