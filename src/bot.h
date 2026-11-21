#ifndef BOT_H
#define BOT_H

#include "defs.h"

void SnakeBot(Snake *snake, Food food, GameContext game);
bool SafeMove(Snake snake, Direction dir, GameContext game);
Direction *FindSafeDirs(Snake snake, GameContext game);
float DistanceToFood(Snake snake, Direction dir, Food food, GameContext game);
Vec2i CellCoords(Snake snake, Direction dir, GameContext game);
float Vec2iDistance(Vec2i a, Vec2i b);

#endif