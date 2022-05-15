//
// Created by chris on 15.05.22.
//

#ifndef UNTITLED_VIEW_H
#define UNTITLED_VIEW_H

#include <SFML/Graphics.hpp>

using namespace sf;

View view;
void GetCoordinatesHero_View(float x, float y){
    view.setCenter(x+100, y);
}

void scroll_map(float time){
    if ((Keyboard::isKeyPressed(Keyboard::Left))) {
        view.move(-0.1*time, 0);
    }
    if ((Keyboard::isKeyPressed(Keyboard::Right))) {
        view.move(0.1*time, 0);
    }
    if ((Keyboard::isKeyPressed(Keyboard::Up))) {
        view.move(0,-0.1*time);
    }
    if ((Keyboard::isKeyPressed(Keyboard::Down))) {
        view.move(0, 0.1*time);
    }
}

#endif //UNTITLED_VIEW_H
