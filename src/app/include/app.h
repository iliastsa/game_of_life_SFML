#include <string>
#include <vector>
#include "../../cell/include/cell.h"

class App{
    private:
        int width, height;
        std::string name;
        Cell*** cells;

    public:
        App(int width, int height, std::string name);
        ~App();

        void run();
        void update();
};
