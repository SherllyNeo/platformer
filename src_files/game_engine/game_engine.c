#include <raylib.h>
#include "draw.c"
#include <stdlib.h>

void GameLoop() {
    Game_State game_state;
    Texture2D frog = LoadTexture("/home/sherlly/git/platformer/frog.png");

    Actor Player = {
    .x = GetScreenWidth() / 2,
    .y = GetScreenHeight() - 200,
    .x_speed = 5,
    .y_speed = 5,
    .width = 250,
    .height = 214,
    .health = 100,
    .mana = 100,
    .stamina = 100,
    .action = STANDING,
    .default_colour = GREEN,
    .texture = frog,
    .name = "Player1"
    };

    game_state.actors[0] = &Player;
    game_state.actor_count = 1;
    game_state.player_index = 0;
    game_state.stage = PLAYING;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BEIGE);
        DrawScene(&game_state);
        Listen_Input(&game_state);
        ApplyPhysics(&game_state);
        EndDrawing();
    }
}
