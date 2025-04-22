#include "raylib.h"
#include "player.h"

void InitPlayer(Player *player) {
	player->position = (Vector2){100,100};
	player->speed = 200.0f;
}

void UpdatePlayer(Player *player) {
	if (IsKeyDown(KEY_RIGHT)) player->position.x += player->speed * GetFrameTime();
	if (IsKeyDown(KEY_LEFT)) player->position.x -= player->speed * GetFrameTime();
	if (IsKeyDown(KEY_UP)) player->position.y -= player->speed * GetFrameTime();
	if (IsKeyDown(KEY_DOWN)) player->position.y += player->speed * GetFrameTime();
}

void DrawPlayer(Player *player) {
	DrawRectangle(player->position.x, player->position.y, 40, 40, BLUE);
}