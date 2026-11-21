#ifndef DRAW_H
#define DRAW_H

#include "defs.h"
#include "raylib.h"

void StartDrawing();
void DrawGridLines(GameContext game);
void DrawSnake(Snake snake, GameContext game);
void DrawFood(Food food, GameContext game);
void DrawScore(Snake player1, GameContext game);

#endif