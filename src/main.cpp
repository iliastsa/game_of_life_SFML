#include <iostream>
#include <SFML/Graphics.hpp>
#include "./app/include/app.h"
using namespace std;

int main() {
    App app(100, 100, "Hello world!");
    app.run();

    return 0;
}
