#include "Ball.h"

void Ball::initial(Setings& st)
{
	ball.Y = st.hight - 2;
	ball.X = st.widht / 2;
	st.arr[ball.Y][ball.X] = st.ball;
}

void Ball::move_ball(Setings& st)
{
	if (!st.start) return;
	
	st.mtx.lock();
	SetConsoleCursorPosition(st.h, ball);
	SetConsoleTextAttribute(st.h, 0);
	std::cout << " ";
	st.arr[ball.Y][ball.X] = st.space;
	st.mtx.unlock();

	if (st.directOX == st.left && st.directOY == st.up) {

		if (st.arr[ball.Y - 1][ball.X - 1] == st.space) {
			ball.Y--;
			ball.X--;
		}

		else if (st.arr[ball.Y - 1][ball.X - 1] == st.let) {
			ball.Y--;
			ball.X--;
			st.coins--;
			if (st.coins == 0) return;

			if (st.arr[ball.Y - 1][ball.X + 1] == st.space) st.directOX = st.right;
			else st.directOY = st.down;
		}

		else if (st.arr[ball.Y - 1][ball.X - 1] == st.wall) {
			if (st.arr[ball.Y - 1][ball.X + 1] == st.space) {
				st.directOX = st.right;
				ball.Y--;
				ball.X++;
			}
			else if (st.arr[ball.Y][ball.X - 1] == st.wall)
			{
				st.directOY = st.down;
				st.directOX = st.right;
				ball.Y++;
				ball.X++;
			}
			else {
				st.directOY = st.down;
				ball.Y++;
				ball.X--;
			}
		}

	}

	else if (st.directOX == st.right && st.directOY == st.up) {

		if (st.arr[ball.Y - 1][ball.X + 1] == st.space) {
			ball.Y--;
			ball.X++;
		}

		else if (st.arr[ball.Y - 1][ball.X + 1] == st.let) {
			ball.Y--;
			ball.X++;
			st.coins--;
			if (st.coins == 0) return;

			if (st.arr[ball.Y - 1][ball.X - 1] == st.space) st.directOX = st.left;
			else st.directOY = st.down;
		}

		else if (st.arr[ball.Y - 1][ball.X + 1] == st.wall) {
			if (st.arr[ball.Y - 1][ball.X - 1] == st.space) {
				st.directOX = st.left;
				ball.Y--;
				ball.X--;
			}
			else if (st.arr[ball.Y][ball.X + 1] == st.wall) {
				st.directOY = st.down;
				st.directOX = st.left;
				ball.Y++;
				ball.X--;
			}
			else {
				st.directOY = st.down;
				ball.Y++;
				ball.X++;
			}
		}
	}

	else if (st.directOX == st.left && st.directOY == st.down) {

		if (st.arr[ball.Y + 1][ball.X - 1] == st.space) {
			ball.Y++;
			ball.X--;

			if (ball.Y == st.hight - 1) st.game_over = true;
		}

		else if (st.arr[ball.Y + 1][ball.X - 1] == st.let) {
			ball.Y++;
			ball.X--;
			st.coins--;
			if (st.coins == 0) return;

			if (st.arr[ball.Y + 1][ball.X + 1] == st.space) st.directOX = st.right;
			else st.directOY = st.up;
		}

		else if (st.arr[ball.Y + 1][ball.X - 1] == st.wall) {
			if (st.arr[ball.Y + 1][ball.X + 1] == st.space) {
				st.directOX = st.right;
				ball.Y++;
				ball.X++;

				if (ball.Y == st.hight - 1) st.game_over = true;
			}
			else if (st.arr[ball.Y + 1][ball.X] == st.racket) {
				st.directOY = st.up;
				st.directOX = st.right;
				ball.Y--;
				ball.X++;
			}
			else {
				st.directOY = st.up;
				ball.Y--;
				ball.X--;
			}
		}

		else if (st.arr[ball.Y + 1][ball.X - 1] == st.racket) {
			st.directOY = st.up;

			if (GetKeyState(VK_RIGHT) < 0) {
				st.directOX = st.right;
				ball.Y--;
				ball.X++;
			}
			else if (GetKeyState(VK_LEFT) < 0 && st.arr[ball.Y - 1][ball.X - 2] != st.wall) {
				ball.Y--;
				ball.X -= 2;
			}
			else if (GetKeyState(VK_UP) < 0) {
				st.directOX = st.neutral;
				ball.Y--;
			}
			else {
				ball.Y--;
				ball.X--;
			}
		}
	}

	else if (st.directOX == st.right && st.directOY == st.down) {

		if (st.arr[ball.Y + 1][ball.X + 1] == st.space) {
			ball.Y++;
			ball.X++;

			if (ball.Y == st.hight - 1) st.game_over = true;
		}

		else if (st.arr[ball.Y + 1][ball.X + 1] == st.let) {
			ball.Y++;
			ball.X++;
			st.coins--;
			if (st.coins == 0) return;

			if (st.arr[ball.Y + 1][ball.X - 1] == st.space) st.directOX = st.left;
			else st.directOY = st.up;
		}

		else if (st.arr[ball.Y + 1][ball.X + 1] == st.wall) {
			if (st.arr[ball.Y + 1][ball.X - 1] == st.space) {
				st.directOX = st.left;
				ball.Y++;
				ball.X--;
				if (ball.Y == st.hight - 1) st.game_over = true;
			}
			else if (st.arr[ball.Y + 1][ball.X] == st.racket) {
				st.directOY = st.up;
				st.directOX = st.left;
				ball.Y--;
				ball.X--;
			}
			else {
				st.directOY = st.up;
				ball.Y--;
				ball.X++;
			}
		}

		else if (st.arr[ball.Y + 1][ball.X + 1] == st.racket) {
			st.directOY = st.up;

			if (GetKeyState(VK_LEFT) < 0) {
				st.directOX = st.left;
				ball.Y--;
				ball.X--;
			}
			else if (GetKeyState(VK_RIGHT) < 0 && st.arr[ball.Y - 1][ball.X + 2] != st.wall) {
				ball.Y--;
				ball.X += 2;
			}
			else if (GetKeyState(VK_UP) < 0) {
				st.directOX = st.neutral;
				ball.Y--;
			}
			else {
				ball.Y--;
				ball.X++;
			}
		}
	}

	else if (st.directOX == st.neutral && st.directOY == st.up) {
		if (st.arr[ball.Y - 1][ball.X] == st.space) ball.Y--;
		else if (st.arr[ball.Y - 1][ball.X] == st.let) {
			st.directOY = st.down;
			ball.Y--;
			st.coins--;
			if (st.coins == 0) return;
		}
		else if (st.arr[ball.Y - 1][ball.X] == st.wall) {
			st.directOY = st.down;
			ball.Y++;
		}
	}

	else if (st.directOX == st.neutral && st.directOY == st.down) {
		if (st.arr[ball.Y + 1][ball.X] == st.space) {
			ball.Y++;
			if (ball.Y == st.hight - 1) st.game_over = true;
		}
		else if (st.arr[ball.Y + 1][ball.X] == st.racket) {
			if (GetKeyState(VK_RIGHT) < 0 && st.arr[ball.Y - 1][ball.X + 1] != st.wall) {
				st.directOY = st.up;
				st.directOX = st.right;
				ball.Y--;
				ball.X++;
			}
			else if (GetKeyState(VK_LEFT) < 0 && st.arr[ball.Y - 1][ball.X - 1] != st.wall) {
				st.directOY = st.up;
				st.directOX = st.left;
				ball.Y--;
				ball.X--;
			}
			else {
				ball.Y--;
				st.directOY = st.up;
			}
		}
	}

	st.mtx.lock();
	SetConsoleCursorPosition(st.h, ball);
	SetConsoleTextAttribute(st.h, st.yellow);
	std::cout << char(st.c_ball);
	st.arr[ball.Y][ball.X] = st.ball;
	st.mtx.unlock();

	Sleep(st.speed);
}
