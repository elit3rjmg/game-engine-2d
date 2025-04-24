#ifndef PLAYER_H
#define PLAYER_H

#include "../data/direction.h"

typedef struct Player {
    Vector2 position;
    Vector2 cameraOffset;
    float speed;
    int size;
    Texture2D textures[8]; // One for each direction
    Direction direction;
} Player;

void InitPlayer(Player *player);
void UpdatePlayer(Player *player);
void DrawPlayer(Player *player);
void UnloadPlayer(Player *player);

#endif