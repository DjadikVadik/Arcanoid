#pragma once
#ifndef Racket123
#define Racket123
#include <iostream>
#include <Windows.h>
#include "Setings.h"

class Racket
{
	COORD rac;
	int x;

public:

	void initial(Setings& st);
	void move(Setings& st);
};

#endif // !Racket123





