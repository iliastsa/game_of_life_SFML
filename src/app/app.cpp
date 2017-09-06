#include "./include/app.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>

using namespace std;

App::App(string name, sf::Image& img)
   :  name(name),
      image(img)
{
    width = img.getSize().x;
    height = img.getSize().y;

    cout << "Width: " << width << " Height: " << height << endl;
    
    cells = new Cell**[height];

    for(int i = 0; i < height; ++i){
        cells[i] = new Cell*[width];
        for(int j = 0; j < width; ++j){
            Cell::State state;

            sf::Color color = image.getPixel(j, i);
            color == sf::Color::Black ? state = Cell::Dead : state = Cell::Alive;

            cells[i][j] = new Cell(state);
        }
        cout << endl;
    }
};

void App::run(){
    sf::RenderWindow window(
            sf::VideoMode(width, height), 
            "Hello, world!",
            sf::Style::Titlebar | sf::Style::Close
            );

    window.setSize(sf::Vector2u(10*width, 10*height));
    window.display();
    printCells(window);

    sf::Clock clock;

    while(window.isOpen()){
        sf::Event Event;
        while(window.pollEvent(Event)){
            if (Event.type == sf::Event::Closed)
                window.close();
        }

        if(clock.getElapsedTime() > sf::milliseconds(50)){
            update();
            printCells(window);
            clock.restart();
        }
    }
}

void App::printCells(sf::RenderWindow& window){
    window.clear(sf::Color::Black);

    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            sf::RectangleShape rect(sf::Vector2f(1, 1));

            rect.setPosition(j, i);

            cells[i][j]->updateState();

            if(cells[i][j]->getState() == Cell::Alive)
                rect.setFillColor(sf::Color::White);
            else
                rect.setFillColor(sf::Color::Black);

            window.draw(rect);
        }
    }
    window.display();
}

int App::countNeighbours(int x, int y){
    int count = 0;

    bool canCheckLeft  = x - 1 >= 0;
    bool canCheckRight = x + 1 < width;
    bool canCheckUp    = y - 1 >= 0;
    bool canCheckDown  = y + 1 < height;

    if(canCheckLeft && canCheckUp && cells[y-1][x-1]->getState() == Cell::Alive)
        count++;

    if(canCheckLeft && canCheckDown && cells[y+1][x-1]->getState() == Cell::Alive)
        count++;

    if(canCheckRight && canCheckUp && cells[y-1][x+1]->getState() == Cell::Alive)
        count++;

    if(canCheckRight && canCheckDown && cells[y+1][x+1]->getState() == Cell::Alive)
        count++;

    if(canCheckLeft && cells[y][x-1]->getState() == Cell::Alive)
        count++;

    if(canCheckRight && cells[y][x+1]->getState() == Cell::Alive)
        count++;

    if(canCheckUp && cells[y-1][x]->getState() == Cell::Alive)
        count++;

    if(canCheckDown && cells[y+1][x]->getState() == Cell::Alive)
        count++;

    return count;
}

void App::update(){
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            int neighbours = countNeighbours(j, i);

            if(cells[i][j]->getState() == Cell::Alive &&
               neighbours < 2
              )
                cells[i][j]->setNextState(Cell::Dead);

            else if(cells[i][j]->getState() == Cell::Alive &&
               (neighbours == 2 || neighbours == 3)
              )
                cells[i][j]->setNextState(Cell::Alive);
            
            else if(cells[i][j]->getState() == Cell::Alive &&
               neighbours > 3
              )
                cells[i][j]->setNextState(Cell::Dead);

            else if(cells[i][j]->getState() == Cell::Dead &&
               neighbours == 3
              )
                cells[i][j]->setNextState(Cell::Alive);
        }
    }
}

App::~App(){
    for(int i = 0; i < width; ++i)
        for(int j = 0; j < height; ++j)
            delete cells[i][j];
}
