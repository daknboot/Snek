#include "defs.h"
#include "raylib.h"
#include "snake.h"

void HandleInputs(Snake *snake, Food *food, GameContext game)
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

	if (IsKeyDown(KEY_F) || IsKeyPressed(KEY_F)) {
		SpawnFood(food, *snake, game);
	}

	if (IsKeyDown(KEY_SPACE) || IsKeyPressed(KEY_SPACE)) {
		snake->bot = true;
	}
}
