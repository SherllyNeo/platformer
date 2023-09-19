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

void DrawScene(Game_State *game_state) {
    DrawActors(game_state);
    DrawFloor();
}
