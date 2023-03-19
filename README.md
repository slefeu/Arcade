# {EPITECH} | Object Oriented Programming | Video Game | Arcade

## Arcade project:

- `Tools:`
    * Project made in `C++` version 20
    * Compiled with `CMake`, minimum version required : 3.6
    * a `justfile` is provided to compile it  

The purpose of the project was to recreate the behaviour of an arcade machine, letting the user choose at run-time which game to play among a predefined list. Like an arcade do in real life, our program had to let the user choose a game to play at run-time. The first requirement of the project was to create portable game and graphic librairies. We implemented :

* Two game libraries :
   * `Centipede`
   * `Nibbler`
* Three graphic librairies :
   * `SDL2`
   * `NCurses`
   * `SFML`

To be able to deal with the elements of our gaming plateform at run-time, each GUI were to be used as a shared library that will be loaded and used dynamically.

For further details about their implementation, you can click [here](./doc) to be redirected to our documentation.

## Usage:

- `How to start the program`:
    * `./arcade ./lib/library.so`\
    /!\ You have to choose from the folder `lib/` which graphic library you want to use\
    /!\ It must be located in the lib folder

- `Key bindings available while the program is running:`
    * `F4` use next graphic library
    * `F5`  use previous graphic library

- `Key bindings in game:`
    * `F1` to restart the game
    * `F2` go to next game
    * `F3` go to previous game
    * `F6` go back to the menu

## Highlights: 

- C++ game Core : [documentation](./doc/Core.md)
	* The gate between our graphic and game librairies

- HOW TO add a new game library : [documentation](./doc/IGame.md)
    * A tutorial if you want to implement a new game library that is compatible with our program.

- HOW TO add a new graphic library : [documentation](./doc/IWindow.md)
    * A tutorial if you want to implement a new graphic library that is compatible with our program.

- Implementation of a generic shape handler : [documentation](./doc/Shape.md)
    * This is used as a base for all our shapes handling inside our program.
    * All the methods used in graphic libraries to display an element in the screen take a class inheriting from this `Shape`class.


Project made with [Nicolas Lavigne](https://github.com/Nicolas-Bilj)
