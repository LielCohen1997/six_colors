#ifdef _DEBUG
#pragma comment ( lib , "sfml-main-d.lib" )
#pragma comment ( lib , "sfml-system-d.lib" )
#pragma comment ( lib , "sfml-window-d.lib" )
#pragma comment ( lib , "sfml-graphics-d.lib" )
#elif defined (NDEBUG)
#pragma comment ( lib , "sfml-main.lib" )
#pragma comment ( lib , "sfml-system.lib" )
#pragma comment ( lib , "sfml-window.lib" )
#pragma comment ( lib , "sfml-graphics.lib" )
#else
#error "Unrecognized configuration!"
#endif

#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <iostream> 
#include "GameController.h"
#include <ctime>
#include <cstdlib>

#define SIZE 600
//--------------------------
int main()
{
	srand((unsigned)time(NULL));
	GameController game;
	game.run();
	return EXIT_SUCCESS;
}