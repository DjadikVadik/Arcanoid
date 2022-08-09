#include "Racket.h"

void Racket::initial(Setings& st)
{
	x = st.widht / 2 - st.racket_length / 2;
	for (int i = x; i < x + st.racket_length; i++)
		st.arr[st.hight - 1][i] = st.racket;

	rac.X = x;
	rac.Y = st.hight - 1;
}

void Racket::move(Setings& st)
{
	if (GetKeyState(VK_LEFT) < 0) {
		if (x > 2) {
			st.mtx.lock();
			x--;
			rac.X = x;
			st.arr[rac.Y][rac.X] = st.racket;
			SetConsoleCursorPosition(st.h, rac);
			SetConsoleTextAttribute(st.h, st.blue);
			std::cout << char(st.c_racket);

			rac.X = x + st.racket_length;
			st.arr[rac.Y][rac.X] = st.space;
			SetConsoleCursorPosition(st.h, rac);
			SetConsoleTextAttribute(st.h, 0);
			std::cout << " ";
			st.mtx.unlock();
		}
		if (!st.start) {
			st.directOX = st.left;
			st.directOY = st.up;
			st.start = true;
		}
	}

	else if (GetKeyState(VK_RIGHT) < 0) {
		if (x + st.racket_length < st.widht - 2) {
			st.mtx.lock();
			rac.X = x + st.racket_length;
			st.arr[rac.Y][rac.X] = st.racket;
			SetConsoleCursorPosition(st.h, rac);
			SetConsoleTextAttribute(st.h, st.blue);
			std::cout << char(st.c_racket);

			rac.X = x;
			st.arr[rac.Y][rac.X] = st.space;
			SetConsoleCursorPosition(st.h, rac);
			SetConsoleTextAttribute(st.h, 0);
			std::cout << " ";
			x++;	
			st.mtx.unlock();
		}
		if (!st.start) {
			st.directOX = st.right;
			st.directOY = st.up;
			st.start = true;
		}
	}

	else if (GetKeyState(VK_UP) < 0)
		if (!st.start) {
			st.directOX = st.neutral;
			st.directOY = st.up;
			st.start = true;
		}

	Sleep(1);
}
