#include "defs.h"
#include "draw.h"
#include "input.h"
#include "snake.h"
#include <raylib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	ProcessArgs(argc, argv);
	InitWindow(WIDTH, HEIGHT, "Snek");
	SetTargetFPS(12);
	SetRandomSeed(69420);

	Food Apple = CreateFood(0, RED);
	Snake Player1 = CreateSnake(0, GREEN);

	while (!WindowShouldClose()) {

		BeginDrawing();
		ClearBackground(BLACK);

		HandleInputs(&Player1);
		if (MoveSnake(&Player1) == 1)
			puts("You died!");
		EatFood(&Player1, &Apple);

		DrawSnake(Player1);
		DrawFood(Apple);
		DrawGridLines();

		EndDrawing();
	}

	CloseWindow();
	return 0;
}
