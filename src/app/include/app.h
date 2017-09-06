#include <string>
#include <vector>
#include "../../cell/include/cell.h"

class App{
    private:
        int width, height;
        std::string name;
        Cell*** cells, ***buffer;
        sf::Image image;

    public:
        App(std::string name, sf::Image& img);
        ~App();

        int countNeighbours(int x, int y);
        void run();
        void update();
        void printCells(sf::RenderWindow& window);
};
