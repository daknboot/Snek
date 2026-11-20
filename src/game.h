#ifndef GAME_H
#define GAME_H

#include "defs.h"

GameContext CreateGameCtx(int width, int height, int cellSize);
void ProcessArgs(int argc, char **argv, GameContext *game);

#endif
