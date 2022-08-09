#pragma once
#ifndef Setings123
#define Setings123
#include <mutex>
#include <Windows.h>

struct Setings {
	HANDLE h = GetStdHandle(-11);
	CONSOLE_CURSOR_INFO inf;
	enum color { blue = 9, yellow = 14, red = 12 };
	enum object { space, wall, racket, ball, let };
	enum symbol { c_wall = 219, c_racket = 219, c_ball = 15, c_let = 4 };
	enum direction { up, down, left, right, neutral };
	int directOX;
	int directOY;
	int racket_length;
	int speed;
	int coins = 0;

	std::mutex mtx;

	bool start;
	bool game_over;

	static const int hight = 30;
	static const int widht = 81;
	int arr[hight][widht];

	void initial(); 
};

#endif // !Setings123

