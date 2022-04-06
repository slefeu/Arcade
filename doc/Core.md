# CORE MANAGEMENT

![structure](./assets/project_strucure.png)

The `Core` part of the project is, as shown in the below image, the gate between our graphic libraries and our game libraries.\
\

This class is contained in the `arcade` namespace, and is initialized inside the `Arcade` class.

The latter will parse the lib folder and the user arguments and create the `Core` class.

##Roles of the Core class

### Load the libraries

The game and graphic libraries are dynamic
It will open, close and load them in the program

### Handle events during execution

According to the player's actions, it will handle all events related to the program's execution.
Mouse events are set in our graphic libraries but not used
All events are triggered by key bindings in the program
You can check the list of keybindings availables in the `README` file at the root of the repository

### Handle the program loop

As the 'gate' of our program, the Core has the responsibility to handle the execution of the program, in its method `executeLoop()`.

It handles the different scenes of the program and the `menu` and `game` loops.

Scores are automatically updated and saved at the program's end and when the player goes back to the menu after a game. A Scoreboard system is also set up with the 5 top scores.

### Error handling

If a library is not loaded correctly, of if during the execution of the games there is an issue, the Core will throw a custom exception called `Error` inheriting from the `std::exception` class.
It will then stop the execution of the program in order to ensure the program's safety.