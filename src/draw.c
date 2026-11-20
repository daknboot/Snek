#include "draw.h"
#include "defs.h"
#include <raylib.h>

void DrawGridLines()
{
	for (int x = 0; x < COLS; x++) {
		DrawLine(x * CELL_SIZE, 0, x * CELL_SIZE, HEIGHT, DARKGRAY);
	}

	for (int y = 0; y < ROWS; y++) {
		DrawLine(0, y * CELL_SIZE, WIDTH, y * CELL_SIZE, DARKGRAY);
	}
}

void DrawSnake(Snake snake)
{
	for (int i = 0; i < snake.length; i++) {
		DrawRectangle(
			snake.x[i], snake.y[i], CELL_SIZE, CELL_SIZE, snake.color);
	}
}

void DrawFood(Food food)
{
	DrawRectangle(food.x, food.y, CELL_SIZE, CELL_SIZE, food.color);
}
