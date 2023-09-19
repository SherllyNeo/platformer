#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include "config.h"
#include "game_engine/game_engine.h"


int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Bilo");
    SetTargetFPS(130);

    GameLoop();

    return EXIT_SUCCESS;
}
