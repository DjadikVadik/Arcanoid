#include "Game.h"

void Game::initial()
{
	st.initial();
	level.create(st);
	racket.initial(st);
	ball.initial(st);
}

void Game::show()
{
	COORD game;
	game.X = 0;
	game.Y = 0;
	SetConsoleCursorPosition(st.h, game);

	for (int i = 0; i < st.hight; i++) {
		for (int j = 0; j < st.widht; j++) {
			if (st.arr[i][j] == st.wall) {
				SetConsoleTextAttribute(st.h, st.blue);
				std::cout << char(st.c_wall);
			}

			else if (st.arr[i][j] == st.racket) {
				SetConsoleTextAttribute(st.h, st.blue);
				std::cout << char(st.c_racket);
			}

			else if (st.arr[i][j] == st.ball) {
				SetConsoleTextAttribute(st.h, st.yellow);
				std::cout << char(st.c_ball);
			}

			else if (st.arr[i][j] == st.let) {
				SetConsoleTextAttribute(st.h, st.red);
				std::cout << char(st.c_let);
			}

			else std::cout << " ";
		}
		if (i != st.hight - 1) std::cout << "\n";
	}
}

void Game::move_racet()
{
	while (!st.game_over) racket.move(st);
}

void Game::move_ball()
{
	while (!st.game_over) {
		ball.move_ball(st);
		if (st.coins == 0) {
			initial();
			show();
		}
	}
}
