#pragma once


enum state {
	Title,
	Game,
	Rank,
	Exit,
};

typedef struct Cell {
	char character;
	int zIndex;
	int color;
	int backcolor;
} Cell;