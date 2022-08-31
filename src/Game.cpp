#include "Game.h"

Game::Game(){
}

void Game::game(){
            setup();
            double a = 1.0 / 20.0;
            while (!gameOver) {
                std::this_thread::sleep_for(std::chrono::milliseconds((int)a * 15000));
                system("CLS"); //clearing the console
                //std::thread a = new std::thread(draw());
                draw();
                input();
                logic();
            }
            std::cout << "gameIsOver !" << std::endl;
            snake.clear();
            dir = NULL;
}


void Game::setup()
{
            gameOver = false;
            x = width / 2;
            y = height / 2;
            srand(time(NULL));
            fruitX = rand() % (width - 2) + 2;
            fruitY = rand() % (height - 2) + 2;
            while (fruitX == x && fruitY == y) {
                srand(time(NULL));
                fruitX = rand() % (width - 2) + 2;
                fruitY = rand() % (height - 2) + 2;
            }
            snake.push_back({x,y});
}



void Game::draw(){
            int counter = 0;
            for (int i = 1; i <= height; i++) {
                for (int j = 1; j <= width; j++)
                {
                    if ( j == 1 || i == 1) {
                        buff[counter] = '#';
                        counter++;
                        //std::cout << "#";
                    }
                    else {
                        int f = 0;
                        while ( f < snake.size() && !( snake[f].x == j && snake[f].y == i) ) {
                            f++;
                        }
                        if ( f < snake.size()) {
                            buff[counter] = '0';
                            counter++;
                            //std::cout << "0";
                        }
                        else if (i == fruitY && j == fruitX) {
                            buff[counter] = 'F';
                            counter++;
                            //std::cout << "F";
                        }
                        else if(j == width || i == height) {
                            buff[counter] = '#';
                            counter++;
                            //std::cout << "#";
                        }
                        else if (j != width || i != height) {
                            buff[counter] = ' ';
                            counter++;
                            //std::cout << " ";
                        }
                    }
                }
                buff[counter] = '\n';
                counter++;
                //std::cout << std::endl;
                //std::cout.flush();
            }
            //buff[width * height ] = '\0';
            std::cout << buff << std::endl;
            std::cout.flush();
            std::cout << "Scores: " << snake.size() * 10 << std::endl;
}


void Game::input(){
                if (_kbhit()) { //_kbhit (keyboard hit which waits for a keyboard button to be pressed)
                switch (_getch()) { //_getch : is simmilar to getchar in "C", It will grab the keyboard button that was pressed
                case 'a':
                    (dir == NULL || dir != 'd' ) ? dir = 'a': dir = 'd';
                    break;
                case 'w':
                    (dir == NULL || dir != 's') ? dir = 'w' : dir = 's';
                    break;
                case 'd':
                    (dir == NULL || dir != 'a') ? dir = 'd' : dir = 'a';
                    break;
                case 's':
                    (dir == NULL || dir != 'w' ) ? dir = 's' : dir = 'w';
                    break;
                default:
                    break;
                }
            }
}


void Game::logic(){

            oldX = snake[0].x;
            oldY = snake[0].y;

            switch (dir) {
            case 'a':
                snake[0].x--;
                break;
            case 'w':
                snake[0].y--;
                break;
            case 'd':
                snake[0].x++;
                break;
            case 's':
                snake[0].y++;
                break;
            default:
                break;
            }
            //Moving the rest of the snake algorithm
            for (int i = 1; i < snake.size(); i++) {
                tempX = snake[i].x;
                tempY = snake[i].y;
                snake[i].x = oldX;
                snake[i].y = oldY;
                oldX = tempX;
                oldY = tempY;
            }

            //the Eating fruit logic
            if ( (snake[0].x == fruitX) && (snake[0].y == fruitY) ) {
                snake.push_back({ oldX, oldY});
                srand(time(NULL));
                fruitX = rand() % (width - 2) + 2;
                fruitY = rand() % (height - 2) + 2;
            }

            //collision with the wall
            if (snake[0].x == 1 || snake[0].y == 1 || snake[0].x == width || snake[0].y == height) {
                gameOver = true;
            }

            //colission with the snake body!
            for (int i = 1; i < snake.size(); i++) {
                if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
                    gameOver = true;
                }
            }
}






