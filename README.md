
# 2048 Game in C++

This repository contains a console-based implementation of the popular 2048 game, developed using C++.

## Overview

2048 is a single-player sliding tile puzzle game. The objective is to slide numbered tiles on a grid to combine them to create a tile with the number 2048. Players can continue to play to achieve higher numbers.

## Features

- Grid Size: 4x4 board.
- Tile Merging: Tiles with the same number merge into one when they touch
- Random Tile Generation: After each move, a new tile (either 2 or 4) is added to an empty spot on the board.
- Game Over Detection: The game ends when no more moves are possible.
- Console-Based Interface: The game is played through the console with simple input commands.

## How to Play 
1. Start the Game: The game initializes with a 4x4 grid with two random tiles (2 or 4).
2. Input Moves:
* U: Move tiles up.
* D: Move tiles down.
* L: Move tiles left.
* R: Move tiles right.
3. Game Ends: The game ends when no moves are possible. The console will display "GAME ENDED !!!".

### Code Structure
1. main.cpp: Contains the main function and game loop.
2. Game2048 struct:
* board[4][4]: Represents the game board.
* swipe_right(int arr[]): Handles the logic for merging and moving tiles to the right.
* has_game_ended(): Checks if the game has ended.
random_populate(): Adds a random tile (2 or 4) to an empty spot on the board.
* init(): Initializes the game board.
* up(), down(), left(), right(): Functions to handle tile movements in respective directions.
* move_end(): Adds a new tile and checks if the game has ended.
* print_board(): Prints the current state of the board.

### Detailed Breakdown

1. #### Initialization:

* The init() function initializes the board with zeros and populates two random positions with either 2 or 4.

2. #### Movement:

* Each directional move (up, down, left, right) is handled by corresponding functions (up(), down(), left(), right()). These functions use the swipe_right() function to handle the merging and moving of tiles.

3. #### Game End:

* The game checks if no empty spots are available on the board using has_game_ended() and displays the game over message if true.
