#include "draw.h"
#include "defs.h"
#include <raylib.h>

void DrawGridLines(GameContext game)
{
	for (int x = 0; x < game.cols; x++) {
		DrawLine(
			x * game.cellSize, 0, x * game.cellSize, game.height, DARKGRAY);
	}

	for (int y = 0; y < game.rows; y++) {
		DrawLine(0, y * game.cellSize, game.width, y * game.cellSize, DARKGRAY);
	}
}

void DrawSnake(Snake snake, GameContext game)
{
	for (int i = 0; i < snake.length; i++) {
		DrawRectangle(
			snake.x[i], snake.y[i], game.cellSize, game.cellSize, snake.color);
	}
}

void DrawFood(Food food, GameContext game)
{
	DrawRectangle(food.x, food.y, game.cellSize, game.cellSize, food.color);
}

void DrawScore(Snake player1, GameContext game)
{
	const char *score = TextFormat("%d", player1.length - 1);
	int textWidth = MeasureText(score, 64);

	Vector2 pos = { ((float)game.width - textWidth) / 2, 1 * game.cellSize };
	Vector2 shadowPos = { pos.x + 4, pos.y + 2 };

	DrawTextEx(game.font, score, shadowPos, 68, 6, BLACK);
	DrawTextEx(game.font, score, pos, 64, 8, player1.color);
}
