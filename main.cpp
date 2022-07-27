#include <iostream>
#include "Game.h"

int main()
{
	Game game;

	while (game.m_playing)
	{
		game.start_menu();
	}

	std::cin.get();
	return 0;
}