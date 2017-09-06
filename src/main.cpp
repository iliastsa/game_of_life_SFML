#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "./app/include/app.h"
using namespace std;

int main(int argc, char** argv) {
    sf::Image img;

    if(argc != 2){
        cout << "Error: invalid arguments" << endl;
        return -2;
    }

    if(!img.loadFromFile(std::string(argv[1]))){
        cout << "Could not load image. Exiting..." << endl;
        return -1;
    }

    App app("Hello world!", img);
    app.run();

    return 0;
}
