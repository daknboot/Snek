#include "defs.h"
#include "snake.h"
#include <raylib.h>

void HandleInputs(Snake *snake, GameContext game)
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

	if (IsKeyDown(KEY_R) || IsKeyPressed(KEY_R)) {
		GrowSnake(snake, 1, game);
	}
}
