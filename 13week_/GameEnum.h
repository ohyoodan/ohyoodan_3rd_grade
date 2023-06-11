#pragma once


enum state {
	Title,
	Game,
	Rank,
	Exit,
};


typedef struct {
	bool Up;
	bool Down;
	bool Left;
	bool Right;
	bool Enter;
	bool ESC;
} Button_state;

static const int BUFFER_WIDTH = 80;
static const int BUFFER_HEIGHT = 20;
static const int BUFFER_DEPTH = 5;