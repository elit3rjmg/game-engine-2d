#include "../data/enemy.h"
#include "raymath.h"

void InitEnemy(Enemy *enemy) {

    enemy->position = (Vector2){100,100};
    enemy->speed = 100.0f;
    enemy->size = 30;

}

void UpdateEnemy(Enemy *enemy, Vector2 playerpos){

    Vector2 direction = Vector2Subtract(playerpos, enemy->position);
    direction = Vector2Normalize(direction);
    enemy->position = Vector2Add(enemy->position, Vector2Scale(direction, enemy->speed * GetFrameTime()));
}

void DrawEnemy(Enemy *enemy){
    DrawRectangle(enemy->position.x - enemy->size / 2,
        enemy->position.y - enemy->size / 2,
        enemy->size, enemy->size, RED);
}

bool EnemyCollidesWithPlayer(Enemy *enemy, Vector2 playerPos, int playerSize) {
    float distance = Vector2Distance(enemy->position, playerPos);
    return distance < (enemy->size / 2 + playerSize / 2);
}