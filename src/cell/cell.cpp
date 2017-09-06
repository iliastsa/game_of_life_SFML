#include "./include/cell.h"

Cell::Cell(const State state){
    setState(state);
    setNextState(state);
}

void Cell::setState(State s){
    state = s;
}

void Cell::setNextState(State s){
    nextState = s;
}

void Cell::updateState(){
    state = nextState;
}
