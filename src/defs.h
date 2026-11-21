#ifndef DEFS_H
#define DEFS_H

#include "raylib.h"

typedef struct {
	int x, y;
} Vec2i;

typedef enum {
	UP, DOWN, LEFT, RIGHT
} Direction;

typedef struct {
	int width, height;
	int cols, rows;
	int cellSize;
	float gameSpeed;
	Font font;
} GameContext;

typedef struct {
	int x, y, id, strength;
	Color color;
} Food;

typedef struct {
	int *x;
	int *y;
	int length, id;
	bool bot;
	Direction dir;
	Color color;
} Snake;

#endif