#include "../data/enemy.h"
#include "../data/direction.h"
#include "raymath.h"

void InitEnemy(Enemy *enemy) {

    enemy->position = (Vector2){100,100};
    enemy->speed = 100.0f;
    enemy->size = 30;
    enemy->textures[DIR_NORTH] = LoadTexture("assets/termite_n.png");
    enemy->textures[DIR_NORTHWEST] = LoadTexture("assets/termite_wn.png");
    enemy->textures[DIR_NORTHEAST] = LoadTexture("assets/termite_ne.png");
    enemy->textures[DIR_EAST] = LoadTexture("assets/termite_e.png");
    enemy->textures[DIR_SOUTHEAST] = LoadTexture("assets/termite_es.png");
    enemy->textures[DIR_SOUTH] = LoadTexture("assets/termite_s.png");
    enemy->textures[DIR_SOUTHWEST] = LoadTexture("assets/termite_sw.png");
    enemy->textures[DIR_WEST] = LoadTexture("assets/termite_w.png");

}

void UpdateEnemy(Enemy *enemy, Vector2 playerpos) {
    Vector2 toPlayer = Vector2Subtract(playerpos, enemy->position);

    float x = toPlayer.x;
    float y = toPlayer.y;

    if (fabsf(x) > fabsf(y)) {
        if (x > 0) enemy->direction = DIR_EAST;
        else enemy->direction = DIR_WEST;
    } else {
        if (y > 0) enemy->direction = DIR_SOUTH;
        else enemy->direction = DIR_NORTH;
    }

    if (fabsf(x) > 10 && fabsf(y) > 10) {
        if (x > 0 && y > 0) enemy->direction = DIR_SOUTHEAST;
        else if (x < 0 && y > 0) enemy->direction = DIR_SOUTHWEST;
        else if (x > 0 && y < 0) enemy->direction = DIR_NORTHEAST;
        else if (x < 0 && y < 0) enemy->direction = DIR_NORTHWEST;
    }

    Vector2 direction = Vector2Normalize(toPlayer);
    enemy->position = Vector2Add(enemy->position, Vector2Scale(direction, enemy->speed * GetFrameTime()));
}


void DrawEnemy(Enemy *enemy, Vector2 cameraOffset) {
    float scale = 0.05f;
    Texture2D tex = enemy->textures[enemy->direction];

    Vector2 screenPos = {
        (enemy->position.x - cameraOffset.x) + (GetScreenWidth() / 2) - (tex.width * scale) / 2.0f,
        (enemy->position.y - cameraOffset.y) + (GetScreenHeight() / 2) - (tex.height * scale) / 2.0f
    };

    DrawTextureEx(tex, screenPos, 0.0f, scale, WHITE);
}

bool EnemyCollidesWithPlayer(Enemy *enemy, Vector2 playerPos, int playerSize) {
    float distance = Vector2Distance(enemy->position, playerPos);
    return distance < (enemy->size / 2 + playerSize / 2);
}

void UnloadEnemy(Enemy *enemy) {
    for (int i = 0; i < 8; i++) {
        UnloadTexture(enemy->textures[i]);
    }
}