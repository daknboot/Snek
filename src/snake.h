#ifndef SNAKE_H
#define SNAKE_H

#include "defs.h"
#include <raylib.h>

Snake CreateSnake(int id, Color color);
Food CreateFood(int id, Color color);
void MoveTail(Snake *snake);
int MoveSnake(Snake *snake);
void SpawnFood(Food *food);
void EatFood(Snake *snake, Food *food);
void GrowSnake(Snake *snake, int amount);
void RespawnSnake(Snake *snake);

#endif