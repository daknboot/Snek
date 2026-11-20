#include "snake.h"
#include "defs.h"
#include <raylib.h>
#include <stdlib.h>
#include <string.h>

Snake CreateSnake(int id, Color color, GameContext game)
{
	int *x = calloc(game.rows * game.cols, sizeof(int));
	int *y = calloc(game.rows * game.cols, sizeof(int));

	Snake snake = { x, y, 1, id, RIGHT, color };

	snake.x[0] = (game.cols / 2) * game.cellSize;
	snake.y[0] = (game.rows / 2) * game.cellSize;
	return snake;
}

Food CreateFood(int id, Color color, GameContext game)
{
	Food food = { 0, 0, id, 1, color };
	food.x = GetRandomValue(0, game.cols - 1) * game.cellSize;
	food.y = GetRandomValue(0, game.rows - 1) * game.cellSize;
	food.strength = GetRandomValue(1, 1);
	return food;
}

void EatFood(Snake *snake, Food *food, GameContext game)
{
	if (snake->id == food->id) {
		if (snake->x[0] == food->x && snake->y[0] == food->y) {
			GrowSnake(snake, food->strength, game);
			SpawnFood(food, game);
		}
	}
}

void GrowSnake(Snake *snake, int amount, GameContext game)
{
	int maxLen = game.cols * game.rows;
	int oldLen = snake->length;
	int newLen = oldLen + amount;
	if (newLen > maxLen)
		newLen = maxLen;

	for (int i = oldLen; i < newLen; i++) {
		snake->x[i] = snake->x[oldLen - 1];
		snake->y[i] = snake->y[oldLen - 1];
	}
	snake->length = newLen;
}

void MoveTail(Snake *snake)
{
	for (int i = snake->length - 1; i > 0; i--) {
		snake->x[i] = snake->x[i - 1];
		snake->y[i] = snake->y[i - 1];
	}
}

void SpawnFood(Food *food, GameContext game)
{
	food->x = GetRandomValue(0, game.cols - 1) * game.cellSize;
	food->y = GetRandomValue(0, game.rows - 1) * game.cellSize;
	food->strength = GetRandomValue(1, 1);
}

int MoveSnake(Snake *snake, GameContext game)
{
	MoveTail(snake);

	switch (snake->dir) {
	case UP:
		snake->y[0] -= game.cellSize;
		break;
	case DOWN:
		snake->y[0] += game.cellSize;
		break;
	case LEFT:
		snake->x[0] -= game.cellSize;
		break;
	case RIGHT:
		snake->x[0] += game.cellSize;
		break;
	}

	if (snake->x[0] < 0 || snake->x[0] >= game.width || snake->y[0] < 0
		|| snake->y[0] >= game.height) {
		RespawnSnake(snake, game);
		return 1;
	}

	for (int i = 1; i < snake->length; i++) {
		if (snake->x[0] == snake->x[i] && snake->y[0] == snake->y[i]) {
			RespawnSnake(snake, game);
			return 1;
		}
	}

	return 0;
}

void RespawnSnake(Snake *snake, GameContext game)
{
	snake->length = 1;
	memset(snake->x, 0, game.cols * game.rows);
	memset(snake->y, 0, game.cols * game.rows);

	snake->x[0] = (game.cols / 2) * game.cellSize;
	snake->y[0] = (game.rows / 2) * game.cellSize;
}
