#include "./include/app.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>

using namespace std;

App::App(int width, int height, std::string name)
    : width(width),
      height(height),
      name(name)
{
    cells = new Cell**[width];
    for(int i = 0; i < width; ++i){
        cells[i] = new Cell*[height];
        for(int j = 0; j < height; ++j){
            Cell::State state;
            rand() % 10 > 5 ? state = Cell::Dead : state = Cell::Alive;
            cells[i][j] = new Cell(i, j, state, 1);
        }
    }
};

void App::run(){
    sf::RenderWindow App(sf::VideoMode(width, height), "Hello, world!");

    sf::Clock clock;

    while (App.isOpen()) {
        sf::Event Event;
        while (App.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
                App.close();
        }
        App.clear(sf::Color::Black);

        if(clock.getElapsedTime() > sf::milliseconds(10)){
            Cell::State state;
            clock.restart();
            for(int i = 0; i < width; ++i)
                for(int j = 0; j < height; ++j){
                    rand() % 10 > 5 ? state = Cell::Dead : state = Cell::Alive;
                    cells[i][j]->setState(state);
                    if(cells[i][j]->getState() != Cell::Dead)
                        App.draw(cells[i][j]->getShape());
                }
        }
        App.display();
    }
}

App::~App(){
    for(int i = 0; i < width; ++i)
        for(int j = 0; j < height; ++j)
            delete cells[i][j];
}
