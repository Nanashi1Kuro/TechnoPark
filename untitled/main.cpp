#include <SFML/Graphics.hpp>
#include <iostream>

#include "view.h"

using namespace sf;

class Hero {
private:
    float x, y;
public:
    float w,h, dx,dy, speed = 0;
    int direction = 0;
    String File;
    Image image;
    Texture texture;
    Sprite sprite;

    Hero(String F, float X, float Y, float W, float H){
        File = F;
        w = W;
        h = H;
        image.loadFromFile("/home/chris/CLionProjects/untitled/images/" + File);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        X = x;
        Y = y;
        sprite.setTextureRect(IntRect(0,0,w,h));
    }

    void update(float time){
    switch (direction) {
        case 0:
            dx = speed;
            dy = 0;
            break;
        case 1:
            dx = -speed;
            dy = 0;
            break;
        case 2:
            dy = speed;
            dx = 0;
            break;
        case 3:
            dy = -speed;
            dx = 0;
            break;
        }
    x +=dx*time;
    y +=dy*time;
    speed = 0;
    sprite.setPosition(x,y);
    }

    float getHeroX(){
        return x;
    }
    float getHeroY(){
        return y;
    }
};

int main() {
    RenderWindow window(VideoMode(500,500), "TEst");
    view.reset(FloatRect(0, 0, 500, 500));
    Hero cat("mem_hero.png", 50, 50, 32, 32);
    cat.sprite.setScale(5.f, 5.f);
    float CurrentFrame = 0;
    Clock clock;

    while (window.isOpen()){
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/800;

        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed)
                window.close();
        }

        if ( (Keyboard::isKeyPressed(Keyboard::A))) {
            cat.direction = 1;
            cat.speed = 0.1;
            CurrentFrame += 0.005*time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            cat.sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 32, 32, 32));
            GetCoordinatesHero_View(cat.getHeroX(), cat.getHeroY());
        }
        if ( (Keyboard::isKeyPressed(Keyboard::D))) {
            cat.direction = 0;
            cat.speed = 0.1;
            CurrentFrame += 0.005*time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            cat.sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 64, 32, 32));
            GetCoordinatesHero_View(cat.getHeroX(), cat.getHeroY());
        }
        if ( (Keyboard::isKeyPressed(Keyboard::W))) {
            cat.direction = 3;
            cat.speed = 0.1;
            CurrentFrame += 0.005*time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            cat.sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 96, 32, 32));
            GetCoordinatesHero_View(cat.getHeroX(), cat.getHeroY());
        }
        if ((Keyboard::isKeyPressed(Keyboard::S))) {
            cat.direction = 2;
            cat.speed = 0.1;
            CurrentFrame += 0.005*time;
            if (CurrentFrame > 3) CurrentFrame -= 3;
            cat.sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 0, 32, 32));
            GetCoordinatesHero_View(cat.getHeroX(), cat.getHeroY());
        }

        cat.update(time);
        scroll_map(time);
        window.setView(view);
        window.clear();
        window.draw(cat.sprite);
        window.display();
    }

    return 0;
}
