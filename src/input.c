#include "defs.h"
#include <raylib.h>
#include <stdio.h>

void ProcessArgs(int argc, char **argv)
{ //		0	  1			2
	// ./snake [speed] [cell_size]
	if (argc > 3) {
		puts("Error: Incorrect command line arguments");
	}
}

void HandleInputs(Snake *snake)
{
	if (IsKeyDown(KEY_W) || IsKeyPressed(KEY_W)) {
		if (snake->dir != DOWN)
			snake->dir = UP;
	}

	if (IsKeyDown(KEY_A) || IsKeyPressed(KEY_A)) {
		if (snake->dir != RIGHT)
			snake->dir = LEFT;
	}

	if (IsKeyDown(KEY_S) || IsKeyPressed(KEY_S)) {
		if (snake->dir != UP)
			snake->dir = DOWN;
	}

	if (IsKeyDown(KEY_D) || IsKeyPressed(KEY_D)) {
		if (snake->dir != LEFT)
			snake->dir = RIGHT;
	}
}
