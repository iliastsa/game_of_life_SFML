#include <SFML/Graphics.hpp>

class Cell : public sf::RectangleShape{
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

    private:
        State state;
};
