#pragma once
#ifndef Ball123
#define Ball123
#include <iostream>
#include <Windows.h>
#include "Setings.h"

class Ball
{
	COORD ball;

public:

	void initial(Setings& st);
	void move_ball(Setings& st);
};

#endif // !Ball123



