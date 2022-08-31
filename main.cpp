#include <iostream>
#include <stdlib.h>
#include <string>	//I didnt use it in this module, But I have trained myslef to implement it whenever possible
#include <windows.h>  //I used it to expereince the getHandle functionss on windows
#include <conio.h>	//event handling for the keyboard
#include <time.h>
#include <vector>
#include <chrono>
#include <thread>
#include "Game.h"

int main()
{
    Game g;
    char cont = 'Y';
	while (cont != 'N' && cont != 'n') {
		g.game();
		std::cout << "do You want to continue? (Y\N): ";
		std::cin >> cont;
	}

    return 0;
}
