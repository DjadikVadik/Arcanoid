#pragma once
#ifndef Levels123
#define Levels123
#include "Setings.h"

class Levels {
public:
	virtual void create(Setings& st) = 0;
};


class Level_1 : public Levels {
public:
	void create(Setings& st) override {
		for (int i = 0; i < st.hight; i++)
			for (int j = 0; j < st.widht; j++)
				if (i > 5 && i < 11 && j > 20 && j < st.widht - 20) {
					st.arr[i][j] = st.let;
					st.coins++;
				}

		st.racket_length = 35;
		st.speed = 50;
	}
};

class Level_2 : public Levels {
public:
	void create(Setings& st) override {
		for (int i = 0; i < st.hight; i++)
			for (int j = 0; j < st.widht; j++)
				if (i > 15 && i < 21 && j > 20 && j < st.widht - 20) {
					st.arr[i][j] = st.let;
					st.coins++;
				}

		st.racket_length = 35;
		st.speed = 50;
	}
};

class Level_3 : public Levels {
public:
	void create(Setings& st) override {
		for (int i = 0; i < st.hight; i++)
			for (int j = 0; j < st.widht; j++)
				if (i > 5 && i < 11 && (j > 10 && j < 30 || j > 50 && j < 70)) {
					st.arr[i][j] = st.let;
					st.coins++;
				}

		st.racket_length = 35;
		st.speed = 50;
	}
};

class Level_4 : public Levels {
public:
	void create(Setings& st) override {
		for (int i = 0; i < st.hight; i++)
			for (int j = 0; j < st.widht; j++)
				if ((i > 5 && i < 11 || i > 15 && i < 21) && (j > 10 && j < 30 || j > 50 && j < 70)) {
					st.arr[i][j] = st.let;
					st.coins++;
				}

		st.racket_length = 35;
		st.speed = 50;
	}
};

#endif // !Levels123

