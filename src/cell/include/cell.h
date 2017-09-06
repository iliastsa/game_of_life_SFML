#include <SFML/Graphics.hpp>

class Cell{
    public:
        enum State{
            Dead,
            Alive
        };

        Cell(const State state);

        State getState(){ return state; }
        void setState(State s);

        State getNextState(){ return nextState; }
        void setNextState(State s);

        void updateState();
    private:
        State state;
        State nextState;
};
