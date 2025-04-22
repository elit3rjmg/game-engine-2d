#include "raylib.h"
#include "../data/player.h"

void InitPlayer(Player *player) {
	player->position.x = GetScreenWidth()/2.0f;
	player->position.y = GetScreenHeight()/2.0f;
	player->speed = 200.0f;
	player->size = 40;
}

void UpdatePlayer(Player *player) {
	if (IsKeyDown(KEY_RIGHT)) player->position.x += player->speed * GetFrameTime();
	if (IsKeyDown(KEY_LEFT)) player->position.x -= player->speed * GetFrameTime();
	if (IsKeyDown(KEY_UP)) player->position.y -= player->speed * GetFrameTime();
	if (IsKeyDown(KEY_DOWN)) player->position.y += player->speed * GetFrameTime();

	int size = player->size;

	if (player->position.x < size / 2) player->position.x = size / 2;
	if (player->position.y < size / 2) player->position.y = size / 2;
	if (player->position.x > GetScreenWidth() - size / 2) player->position.x = GetScreenWidth() - size / 2;
	if (player->position.y > GetScreenHeight() - size / 2) player->position.y = GetScreenHeight() - size / 2;


}

void DrawPlayer(Player *player) {
	int size = player->size;
	DrawRectangle(player->position.x - size / 2, player->position.y - size / 2, size, size, BLUE);
}
