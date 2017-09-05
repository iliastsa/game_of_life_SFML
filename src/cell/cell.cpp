#include "./include/cell.h"

Cell::Cell(
        const int position_X, 
        const int position_Y, 
        const State state,
        const int cell_size = 3
        )
    : RectangleShape(sf::Vector2f(cell_size, cell_size))
{
    setState(state);
    setPosition(position_X, position_Y);
}

void Cell::setState(State s){
    state = s;

    if(state == Dead)
        setFillColor(sf::Color::Black);
    else
        setFillColor(sf::Color::White);
}

