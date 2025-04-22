#ifndef PLAYER_H
#define PLAYER_H

typedef struct Player {
	Vector2 position;
	float speed;

} Player;

void InitPlayer(Player *player);
void UpdatePlayer(Player *player);
void DrawPlayer(Player *player);

#endif