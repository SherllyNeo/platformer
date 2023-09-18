#include "mechanics.c"
#include <raylib.h>

void DrawActors(Game_State *game_state) {
    for (int i = 0; i<game_state->actor_count; i++) {
        Actor cur_actor = *(game_state->actors[i]);
        DrawRectangle(cur_actor.x, cur_actor.y, cur_actor.width, cur_actor.height,  cur_actor.default_colour);
    }
}

void DrawFloor() {
    DrawRectangle(GetScreenWidth(),get_floor_height(), GetScreenWidth(), 100,  BLACK);
}

void DrawScene(Game_State *game_state) {
    DrawActors(game_state);
    DrawFloor();
}
