# Tetris - The Game

## Prerequisites

Before running the game, ensure the following requirements are met:

1. **MinGW Installation**
   - Install MinGW and set up the environment variables.
   - Verify that `g++` is installed by running:
     ```sh
     g++ --version
     ```
   - [Watch this YouTube tutorial to set up MinGW](https://youtu.be/-KayVZq1a58?si=NKJwpjIGgTZvhU07)

2. **Raylib Installation**
   - Download and install Raylib. The setup file is provided on Google Drive.
   - [Google Drive link](https://drive.google.com/drive/folders/11l_80P5bKV4J8jj5k3wIHviuVNj2fsgC?usp=sharing)

## Running the Game

Follow these steps to build and run the game:

1. **Open the project in VS Code**
2. **Check if the g++ compiler is installed**
   ```sh
   g++ --version
   ```
3. **Navigate to the build folder**
   ```sh
   cd build
   ```
4. **Compile and run the game**
   ```sh
   mingw32-make
   ```
5. **Enjoy the game!**

---

## Game Instructions & Rules

1. Earn **1 point** each time a block successfully moves down to the bottom.
2. Earn **100 points** for completing a single row.
3. Earn **300 points** for clearing two rows simultaneously.
4. Earn **500 points** for clearing three rows simultaneously.
5. **Controls:**
   - Use the **Left Arrow Key** to move the block left.
   - Use the **Right Arrow Key** to move the block right.
   - Use the **Down Arrow Key** to speed up the block’s descent.
   - Use the **Up Arrow Key** to rotate the block.
6. The game ends when blocks reach the top of the screen.
7. **Restarting the game:**
   - Press **any key** after a game over to restart.
---

Enjoy the game and aim for the highest score! 🚀
