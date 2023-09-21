#include "mechanics.c"
#include <raylib.h>

void DrawActors(Game_State *game_state) {
    for (int i = 0; i<game_state->actor_count; i++) {
        Actor cur_actor = *(game_state->actors[i]);
        DrawTexture(cur_actor.texture,cur_actor.x,cur_actor.y,WHITE);
    }
}

void DrawFloor() {
    DrawRectangle(0,get_floor_height(), GetScreenWidth(), get_floor_height(),  BLUE);
}
void DrawRefreshCam(Game_State *game_state) {
    Actor *Player = game_state->actors[game_state->player_index];
    Camera2D *Camera = game_state->camera;
    
    Camera->offset = (Vector2){GetScreenWidth()/2.0f, (int)GetScreenHeight()/2.0f};
    Camera->target = (Vector2){Player->x + Player->width/2.0f, Player->y + Player->height / 2.0f};
    Camera->rotation = 0.0f;
    Camera->zoom = 1.0f;
}

void DrawScene(Game_State *game_state) {
    DrawActors(game_state);
    DrawFloor();
    DrawRefreshCam(game_state);
}
