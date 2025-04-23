#include "raylib.h"
#include "../data/player.h"

void InitPlayer(Player *player) {

	player->position.x = GetScreenWidth()/2.0f;
	player->position.y = GetScreenHeight()/2.0f;
	player->speed = 200.0f;
	player->size = 40;

}

void UpdatePlayer(Player *player) {

	if (IsKeyDown(KEY_W)) player->position.y -= player->speed * GetFrameTime();
	if (IsKeyDown(KEY_S)) player->position.y += player->speed * GetFrameTime();
	if (IsKeyDown(KEY_A)) player->position.x -= player->speed * GetFrameTime();
	if (IsKeyDown(KEY_D)) player->position.x += player->speed * GetFrameTime();

}

void DrawPlayer(Player *player) {
	DrawRectangle(GetScreenWidth() / 2 - player->size / 2,
                  GetScreenHeight() / 2 - player->size / 2,
                  player->size, player->size, BLUE);
}
