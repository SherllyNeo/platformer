#include <raylib.h>
#include "draw.c"
#include <stdlib.h>

void GameLoop() {
    Game_State game_state;
    Texture2D frog = LoadTexture("/home/sherlly/git/platformer/frog.png");

    Actor Player = {
    .x = GetScreenWidth() / 2,
    .y = GetScreenHeight() - 200,
    .x_speed = 0,
    .y_speed = 5,
    .width = 250,
    .height = 214,
    .health = 100,
    .mana = 100,
    .stamina = 100,
    .action = STANDING,
    .type = PLAYER,
    .default_colour = GREEN,
    .texture = frog,
    .name = "Player1",
    .looking_direction = 0
    };

    Camera2D Camera;
    Camera.offset = (Vector2){GetScreenWidth()/2.0f, (int)GetScreenHeight()/2.0f};
    Camera.target = (Vector2){Player.x + Player.width/2.0f, Player.y + Player.height / 2.0f};
    Camera.rotation = 0.0f;
    Camera.zoom = 1.0f;

    game_state.actors[0] = &Player;
    game_state.actor_count = 1;
    game_state.player_index = 0;
    game_state.stage = PLAYING;
    game_state.camera = &Camera;
    game_state.camera_smoothing = Player.x + Player.width / 2.0f;



    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BEIGE);
        BeginMode2D(*game_state.camera);

        DrawScene(&game_state);
        Listen_Input(&game_state);
        ApplyPhysics(&game_state);
        EndMode2D();
        EndDrawing();
    }
}
