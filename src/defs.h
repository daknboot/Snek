#ifndef DEFS_H
#define DEFS_H

#include <raylib.h>

// #define WIDTH 1000
// #define HEIGHT 800

// #define CELL_SIZE 40
// #define COLS (WIDTH  / CELL_SIZE)
// #define ROWS (HEIGHT / CELL_SIZE)

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
	Direction dir;
	Color color;
} Snake;

#endif