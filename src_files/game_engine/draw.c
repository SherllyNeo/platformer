#include "mechanics.c"
#include <raylib.h>

void DrawActors(Game_State *game_state) {
    for (int i = 0; i<game_state->actor_count; i++) {
        Actor cur_actor = *(game_state->actors[i]);
        if (cur_actor.action == WALKING_RIGHT) {
            DrawTexture(cur_actor.texture,cur_actor.x,cur_actor.y,WHITE);
        }
        else if (cur_actor.action == WALKING_RIGHT) {
            DrawTexture(cur_actor.texture,cur_actor.x,cur_actor.y,WHITE);
        }
        else {
            DrawTexture(cur_actor.texture,cur_actor.x,cur_actor.y,WHITE);
        }
    }
}

void DrawFloor() {
    DrawRectangle(0,get_floor_height(), GetScreenWidth()*5, get_floor_height(),  BLUE);
}
void DrawRefreshCam(Game_State *game_state) {
    Actor *Player = game_state->actors[game_state->player_index];
    Camera2D *Camera = game_state->camera;
    Camera->offset = (Vector2){GetScreenWidth()/2.0f, (int)GetScreenHeight()/2.0f};
    Camera->rotation = 0.0f;
    Camera->zoom = 0.5f;

    /* middle -> Camera->target = (Vector2){Player->x + Player->width / 2.0f, Player->y + Player->height / 2.0f}; */
    /*
                Player X - should be screen width / 3 when looking forward
         |           |               |    
         |           |               |
         |           |               |
                Player X - should be  screen width 2 / 3 when looking backwards
         |             |            |    
         |             |            |
         |             |            |
     */

    int X = Player->x + (Player->width / 2.0f);
    float delta = 9.0f;
    if (Player->looking_direction) {
        if ((Camera->target.x)>=(X - GetScreenWidth()/3.0f)) {
            game_state->camera_smoothing -= delta;
        }
    }
    else {
        if ((Camera->target.x)<=(X + GetScreenWidth()/3.0f)) {
            game_state->camera_smoothing += delta;
        }
    }
    Camera->target = (Vector2){game_state->camera_smoothing, Player->y + Player->height / 2.0f};


}

void DrawScene(Game_State *game_state) {
    DrawRefreshCam(game_state);
    DrawActors(game_state);
    DrawFloor();
}
