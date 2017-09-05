#include <SFML/Graphics.hpp>

class Cell{
    public:
        enum State{
            Dead,
            Alive
        };

        Cell(
                const int position_X, 
                const int position_Y, 
                const State state,
                const int cell_size
                );

        State getState(){ return state; }
        void setState(State s);

        sf::RectangleShape getShape(){ return shape; }

    private:
        State state;
        sf::RectangleShape shape;
};
