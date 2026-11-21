#ifndef SNAKE_H
#define SNAKE_H

#include "defs.h"
#include "raylib.h"

Snake CreateSnake(int id, Color color, GameContext game);
Food CreateFood(int id, Color color, GameContext game);
void MoveTail(Snake *snake);
void MoveSnake(Snake *snake, GameContext game);
void SpawnFood(Food *food, Snake snake, GameContext game);
void EatFood(Snake *snake, Food *food, GameContext game);
void GrowSnake(Snake *snake, int amount, GameContext game);
void RespawnSnake(Snake *snake, GameContext game);

#endif