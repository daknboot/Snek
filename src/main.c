#include "defs.h"
#include "draw.h"
#include "game.h"
#include "input.h"
#include "snake.h"
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	GameContext ctx = CreateGameCtx(1000, 800, 40);
	ProcessArgs(argc, argv, &ctx);

	Color Black = { 15, 15, 15, 255 };

	Food Apple = CreateFood(0, RED, ctx);
	Snake Player1 = CreateSnake(0, GREEN, ctx);

	while (!WindowShouldClose()) {

		BeginDrawing();
		ClearBackground(Black);

		HandleInputs(&Player1, ctx);
		if (MoveSnake(&Player1, ctx) == 1)
			puts("You died!");
		EatFood(&Player1, &Apple, ctx);

		DrawSnake(Player1, ctx);
		DrawFood(Apple, ctx);
		DrawGridLines(ctx);
		DrawScore(Player1, ctx);

		EndDrawing();
	}

	free(Player1.x);
	free(Player1.y);
	CloseWindow();
	return 0;
}
