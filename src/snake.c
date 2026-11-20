#include "snake.h"
#include "defs.h"
#include <raylib.h>

Snake CreateSnake(int id, Color color)
{
	Snake snake = { { 0 }, { 0 }, 1, id, RIGHT, color };
	snake.x[0] = (COLS / 2) * CELL_SIZE;
	snake.y[0] = (ROWS / 2) * CELL_SIZE;
	return snake;
}

Food CreateFood(int id, Color color)
{
	Food food = { 0, 0, id, 1, color };
	food.x = GetRandomValue(0, COLS - 1) * CELL_SIZE;
	food.y = GetRandomValue(0, ROWS - 1) * CELL_SIZE;
	food.strength = GetRandomValue(1, 1);
	return food;
}

void EatFood(Snake *snake, Food *food)
{
	if (snake->id == food->id) {
		if (snake->x[0] == food->x && snake->y[0] == food->y) {
			GrowSnake(snake, food->strength);
			SpawnFood(food);
		}
	}
}

void GrowSnake(Snake *snake, int amount)
{
	int maxLen = COLS * ROWS;
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

void SpawnFood(Food *food)
{
	food->x = GetRandomValue(0, COLS - 1) * CELL_SIZE;
	food->y = GetRandomValue(0, ROWS - 1) * CELL_SIZE;
	food->strength = GetRandomValue(1, 1);
}

int MoveSnake(Snake *snake)
{
	MoveTail(snake);

	switch (snake->dir) {
	case UP:
		snake->y[0] -= CELL_SIZE;
		break;
	case DOWN:
		snake->y[0] += CELL_SIZE;
		break;
	case LEFT:
		snake->x[0] -= CELL_SIZE;
		break;
	case RIGHT:
		snake->x[0] += CELL_SIZE;
		break;
	}

	if (snake->x[0] < 0 || snake->x[0] >= WIDTH || snake->y[0] < 0
		|| snake->y[0] >= HEIGHT) {
		RespawnSnake(snake);
		return 1;
	}

	for (int i = 1; i < snake->length; i++) {
		if (snake->x[0] == snake->x[i] && snake->y[0] == snake->y[i]) {
			RespawnSnake(snake);
			return 1;
		}
	}

	return 0;
}

void RespawnSnake(Snake *snake)
{
	snake->length = 1;
	snake->x[0] = (COLS / 2) * CELL_SIZE;
	snake->y[0] = (ROWS / 2) * CELL_SIZE;
}
