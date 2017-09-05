#include "./include/cell.h"

Cell::Cell(
        const int position_X, 
        const int position_Y, 
        const State state,
        const int cell_size = 3
        )
    : shape(sf::Vector2f(cell_size, cell_size))
{
    setState(state);
    shape.setPosition(position_X, position_Y);
}

void Cell::setState(State s){
    state = s;

    if(state == Dead)
        shape.setFillColor(sf::Color::Black);
    else
        shape.setFillColor(sf::Color::White);
}

