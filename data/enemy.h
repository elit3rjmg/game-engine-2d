#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include "../data/direction.h"

typedef struct Enemy {
	Vector2 position;
	float speed;
	int size;
	Texture2D textures[8];
	Direction direction;

} Enemy;

void InitEnemy(Enemy *enemy);
void UpdateEnemy(Enemy *enemy, Vector2 playerPos);
void DrawEnemy(Enemy *enemy, Vector2 cameraOffset);
void UnloadEnemy(Enemy *enemy);
bool EnemyCollidesWithPlayer(Enemy *enemy, Vector2 playerPos, int playerSize);

#endif