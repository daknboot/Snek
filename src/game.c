#include "defs.h"
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

GameContext CreateGameCtx(int width, int height, int cellSize)
{
	InitWindow(width, height, "Snek");
	SetTargetFPS(12);
	SetRandomSeed(69420);
	Font f = LoadFont("assets/fonts/0xProto-Bold.ttf");

	GameContext game = { width, height, width / cellSize, height / cellSize,
		cellSize, 1.0f, f };

	return game;
}

void ProcessArgs(int argc, char **argv, GameContext *game)
{ //		0	  1			2
	// ./snake [speed] [cell_size]
	if (argc == 1)
		return;

	if (argc > 3) {
		puts("Error: Incorrect command line arguments");
		exit(EXIT_FAILURE);
		return;
	}

	char *endptr;
	float speed = strtod(argv[1], &endptr);

	if (speed < 0)
		speed *= -1;
	SetTargetFPS(12 * speed);

	if (argc > 2) {
		int cellSize = strtol(argv[2], &endptr, 10);
		if (cellSize < 0)
			cellSize *= -1;
		game->cellSize = cellSize;
		game->cols = game->width / cellSize;
		game->rows = game->height / cellSize;
	}
}
