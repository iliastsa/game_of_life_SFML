#include "./include/app.h"
#include "../cell/include/cell.h"
#include <SFML/Graphics.hpp>

using namespace std;

App::App(int width, int height, std::string name)
    : width(width),
      height(height),
      name(name) 
{};

void App::run(){
    Cell rect(0, 0, Cell::Alive, 3);

    sf::RenderWindow App(sf::VideoMode(width, height), "Hello, world!");

    rect.setPosition(0, 0);
    sf::Clock clock;

    while (App.isOpen()) {
        sf::Event Event;
        while (App.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
                App.close();
        }
        App.clear(sf::Color::Blue);

        if(clock.getElapsedTime() > sf::milliseconds(50)){
            rect.setPosition(rect.getPosition().x + 1, rect.getPosition().y + 1);
            clock.restart();
        }

        App.draw(rect);
        App.display();
    }
}
