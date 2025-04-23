#ifndef PLAYER_H
#define PLAYER_H

typedef enum {
    DIR_NORTH, DIR_NORTHWEST, DIR_NORTHEAST, DIR_EAST,
    DIR_SOUTHEAST, DIR_SOUTH, DIR_SOUTHWEST,
    DIR_WEST
} Direction;

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