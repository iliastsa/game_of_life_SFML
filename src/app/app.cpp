#include "./include/app.h"
#include <SFML/Graphics.hpp>

using namespace std;

App::App(int width, int height, std::string name)
    : width(width),
      height(height),
      name(name) 
{};

void App::run(){
    sf::Window App(sf::VideoMode(width, height), name);

    while (App.isOpen()) {
        sf::Event Event;
        while (App.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
                App.close();
        }
        App.display();
    }
}
