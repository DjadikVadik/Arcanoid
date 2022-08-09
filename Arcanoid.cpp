#include <thread>
#include "Game.h"

int main()
{
	Game game;
	game.initial();
	game.show();


	std::thread T([&game]() { game.move_racet(); });
	T.detach();

	game.move_ball();
}

