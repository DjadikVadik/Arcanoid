#pragma once
#ifndef Game123
#define Game123
#include <iostream>
#include <Windows.h>
#include "Racket.h"
#include "Ball.h"
#include "Levels.h"

class Game {

	Setings st;
	Racket racket;
	Ball ball;
	Level_3 level;

public:
	void initial();
	void show();
	void move_racet();
	void move_ball();
};


#endif // !Game123






