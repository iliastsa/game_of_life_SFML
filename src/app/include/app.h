#include <string>

class App{
    private:
        int width, height;
        std::string name;

    public:
        App(int width, int height, std::string name);

        void run();
};
