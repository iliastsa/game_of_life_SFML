# Game of Life w/ SFML
C++ implementation of Conway's Game of Life, using SFML
![Glider Gun demo](https://github.com/iliastsa/game_of_life_SFML/blob/master/demos/Glider_Gun_demo.gif "Glider Gun demonstration")

# Dependencies
The only external dependency this project has is SFML, which you can find [here](https://www.sfml-dev.org/).
I suggest installing the library in the default directory, to avoid any issues with its detection from CMake.

# Getting it to work
To download and compile the project, run the following commands:
```
$ git clone https://github.com/iliastsa/game_of_life_SFML.git
$ cd game_of_life_SFML
$ mkdir build
$ cd build
$ cmake ..
$ make
```
The executable will be created in the build directory. To execute, simply run `./game_of_life <path_to_png_seed>`.

You can provide your own Black/White png seed(suggested size 20-40) or play around with the ones provided inside the example folder.
