#include "Setings.h"

void Setings::initial()
{
	for (int i = 0; i < hight; i++)
		for (int j = 0; j < widht; j++) {
			if (i == 0 || j == 0 || j == 1 || j == widht - 1 || j == widht - 2)
				arr[i][j] = wall;
			else arr[i][j] = space;
		}
	inf.bVisible = false;
	inf.dwSize = 100;
	SetConsoleCursorInfo(h, &inf);
	start = false;
	game_over = false;
}
