#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
    RenderWindow window(VideoMode(500,500), "TEst");

    Texture cattexture;
    cattexture.loadFromFile("/home/chris/CLionProjects/untitled/images/mem_hero.png");

    Sprite cat;
    cat.setTexture(cattexture);
    cat.setTextureRect(IntRect(0,0,32,32));
    cat.setScale(5.f, 5.f);
    cat.setPosition(50,50);

    float CurrentFrame = 0;
    Clock clock;

    while (window.isOpen()) {

        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time/800;

        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed)
                window.close();
        }

        if((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))){
            CurrentFrame += 0.005*time;
            if(CurrentFrame > 3)
                CurrentFrame = 0;
            cat.setTextureRect(IntRect(32*int(CurrentFrame),32,32,32));
            cat.move(-0.1*time, 0);
        }
        if((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))){
            CurrentFrame += 0.005*time;
            if(CurrentFrame > 3)
                CurrentFrame = 0;
            cat.setTextureRect(IntRect(32*int(CurrentFrame),64,32,32));
            cat.move(0.1*time, 0);
        }
        if((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))){
            CurrentFrame += 0.005*time;
            if(CurrentFrame > 3)
                CurrentFrame = 0;
            cat.setTextureRect(IntRect(32*int(CurrentFrame),96,32,32));
            cat.move(0, -0.1*time);
        }
        if((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))){
            CurrentFrame += 0.005*time;
            if(CurrentFrame > 3)
                CurrentFrame = 0;
            cat.setTextureRect(IntRect(32*int(CurrentFrame),0,32,32));
            cat.move(0, 0.1*time);
        }
        window.clear();
        window.draw(cat);
        window.display();
    }

    return 0;
}
