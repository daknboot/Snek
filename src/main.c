#include "bot.h"
#include "defs.h"
#include "draw.h"
#include "game.h"
#include "input.h"
#include "raylib.h"
#include "snake.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
	GameContext ctx = CreateGameCtx(1400, 1000, 40);
	ProcessArgs(argc, argv, &ctx);

	Food Apple = CreateFood(0, RED, ctx);
	Snake Player1 = CreateSnake(0, GREEN, ctx);

	while (!WindowShouldClose()) {

		StartDrawing();
		HandleInputs(&Player1, &Apple, ctx);

		MoveSnake(&Player1, ctx);
		SnakeBot(&Player1, Apple, ctx);
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
