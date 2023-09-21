#include <raylib.h>
#include <stdio.h>

#define GRAVITY 1
#define FRICTION 1


typedef enum {
    STANDING,
    WALKING_RIGHT,
    WALKING_LEFT,
    JUMPING
} Action;

typedef enum {
    PLAYER,
    ALLY,
    MOB,
    NEUTRAL,
    OBJECT
} Type;

typedef struct {
    char name[100];
    int x;
    int y;
    int x_speed;
    int y_speed;
    int width;
    int height;
    int health;
    int mana;
    int stamina;
    Action action;
    Type type;
    Texture2D texture;
    Color default_colour;
} Actor;


typedef enum {
    TITLE_SCREEN,
    PLAYING,
    CREDITS
} Game_Stage;

int get_floor_height() {
    return GetScreenHeight() - 50;
}

typedef struct {
    Game_Stage stage;
    Actor* actors[50];
    int actor_count;
    int player_index;
    Camera2D *camera;
} Game_State;

bool actor_on_ground(Actor player) {
    return (player.y + player.height) >= get_floor_height();
}

void Listen_Input(Game_State* game_state) {
    Actor *player = game_state->actors[game_state->player_index];

    if (actor_on_ground(*player)) {
        if (IsKeyDown(KEY_RIGHT)) {
            player->action = WALKING_RIGHT;
            player->x_speed = 10;
        }
        if (IsKeyDown(KEY_LEFT)) {
            player->action = WALKING_LEFT;
            player->x_speed = -10;
        }
        if (IsKeyPressed(KEY_UP) && (player->action != JUMPING)) {
            player->action = JUMPING;
            player->y_speed = -30;
        } 
    }
}


void ApplyPhysics(Game_State* game_state) {

        for (int i = 0; i<game_state->actor_count; i++) {
            Actor *cur_actor = game_state->actors[i];

            if (!actor_on_ground(*cur_actor)) {
                cur_actor->y_speed += GRAVITY;
            }
            if (actor_on_ground(*cur_actor)) {
                if (cur_actor->action == WALKING_LEFT) {
                    if (cur_actor->x_speed < 0) {
                        cur_actor->x_speed += FRICTION;
                    }
                }
                else if (cur_actor->action == WALKING_RIGHT) {
                    if (cur_actor->x_speed > 0) {
                        cur_actor->x_speed -= FRICTION;
                    }
                }
                else {
                }
            }
            if ((cur_actor->y + cur_actor->height) > get_floor_height()) {
                cur_actor->y = get_floor_height() - cur_actor->height;
            }
            if (!actor_on_ground(*cur_actor) || cur_actor->action == JUMPING) {
                cur_actor->y += cur_actor->y_speed;
                cur_actor->x += cur_actor->x_speed;
                if (actor_on_ground(*cur_actor)) {
                    cur_actor->y = get_floor_height();
                    cur_actor->action = STANDING;
                }
            }
            if (cur_actor->action == WALKING_LEFT || cur_actor->action == WALKING_RIGHT) {
                cur_actor->x += cur_actor->x_speed;
            }
        }

}

