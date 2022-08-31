
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <stdlib.h>
#include <string>	//I didnt use it in this module, But I have trained myslef to implement it whenever possible
#include <windows.h>  //I used it to expereince the getHandle functionss on windows
#include <conio.h>	//event handling for the keyboard
#include <time.h>
#include <vector>
#include <chrono>
#include <thread>

class Game
{
    public:
        Game();
        //the game init function!
        void game();

    private:
        typedef struct SnakePiece
        {
            int x, y;
        } SnakePiece;
        //the game's variables
        bool gameOver;	//A boolean to stop the game loop
        static const int width = 20; //Determining the width of the game (By columns on the console)
        static const int height = 20; //Determining the height of the game (By columns on the console)
        int x, y, fruitX, fruitY;	//The snake's head possition
        char dir;	//The keyboard event handler which will grab the keyboard letter
        std::vector<SnakePiece> snake;
        int tempX, tempY; //temperory holders for the value of each piece in the snake  (used in the logic funtion)
        int oldX = x; //temperory holder for the value of each piece in the snake (used in the logic funtion)
        int oldY = y; //temperory holder for the value of each piece in the snake (used in the logic funtion)
        char buff[height * width + 1];

        //just setting up the game ! (launching it and setting the main variables)
        void setup();
        //Drawing the assets on the console by using "couts"
        void draw();
        //Event handling function
        void input() ;
        // Game logic
        void logic() ;


};

#endif // GAME_H
