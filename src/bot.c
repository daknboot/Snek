#include "bot.h"
#include "defs.h"
#include <stdlib.h>

void SnakeBot(Snake *snake, Food food, GameContext game)
{
	if (!snake->bot)
		return;

	Direction prefDir = snake->dir;

	if (food.x != snake->x[0]) {
		prefDir = food.x > snake->x[0] ? RIGHT : LEFT;
	} else if (food.y != snake->y[0]) {
		prefDir = food.y > snake->y[0] ? DOWN : UP;
	}

	if (SafeMove(*snake, prefDir, game)) {
		snake->dir = prefDir;
		return;
	}

	Direction dirs[] = { UP, DOWN, LEFT, RIGHT };

	Direction bestDir = snake->dir;
	float lowestDist = 9999999;
	bool foundSafeDir = false;

	for (int i = 0; i < 4; i++) {
		if (SafeMove(*snake, dirs[i], game)) {

			float dist = DistanceToFood(*snake, dirs[i], food, game);

			if (dist < lowestDist) {
				lowestDist = dist;
				bestDir = dirs[i];
				foundSafeDir = true;
			}
		}
	}

	if (foundSafeDir)
		snake->dir = bestDir;
}

float DistanceToFood(Snake snake, Direction dir, Food food, GameContext game)
{
	Vec2i nextCell = CellCoords(snake, dir, game);
	return Vec2iDistance(nextCell, (Vec2i) { food.x, food.y });
}

bool SafeMove(Snake snake, Direction dir, GameContext game)
{
	Vec2i nextCell = CellCoords(snake, dir, game);

	if (nextCell.x < 0 || nextCell.x > game.width - game.cellSize
		|| nextCell.y < 0 || nextCell.y > game.height - game.cellSize) {
		return false;
	}

	for (int i = 0; i < snake.length; i++) {
		if (nextCell.x == snake.x[i] && nextCell.y == snake.y[i]) {
			return false;
		}
	}

	return true;
}

Vec2i CellCoords(Snake snake, Direction dir, GameContext game)
{
	Vec2i nextCell = { snake.x[0], snake.y[0] };

	switch (dir) {
	case UP:
		nextCell.y = snake.y[0] - game.cellSize;
		break;
	case DOWN:
		nextCell.y = snake.y[0] + game.cellSize;
		break;
	case LEFT:
		nextCell.x = snake.x[0] - game.cellSize;
		break;
	case RIGHT:
		nextCell.x = snake.x[0] + game.cellSize;
		break;
	}
	return nextCell;
}

float Vec2iDistance(Vec2i a, Vec2i b)
{
	return abs(a.x - b.x) + abs(a.y - b.y);
}
