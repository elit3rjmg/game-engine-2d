#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"

typedef struct Enemy {
	Vector2 position;
	float speed;
	int size;

} Enemy;

void InitEnemy(Enemy *enemy);
void UpdateEnemy(Enemy *enemy, Vector2 playerPos);
void DrawEnemy(Enemy *enemy, Vector2 cameraOffset);
bool EnemyCollidesWithPlayer(Enemy *enemy, Vector2 playerPos, int playerSize);

#endif