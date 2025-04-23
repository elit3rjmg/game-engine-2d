#include "raylib.h"
#include "../data/player.h"

void InitPlayer(Player *player) {

	player->position.x = GetScreenWidth()/2.0f;
	player->position.y = GetScreenHeight()/2.0f;
    player->speed = 200;
    player->size = 32;
    player->textures[DIR_NORTH] = LoadTexture("assets/ant_n.png");
    player->textures[DIR_NORTHWEST] = LoadTexture("assets/ant_wn.png");
	player->textures[DIR_NORTHEAST] = LoadTexture("assets/ant_ne.png");
	player->textures[DIR_EAST] = LoadTexture("assets/ant_e.png");
	player->textures[DIR_SOUTHEAST] = LoadTexture("assets/ant_es.png");
	player->textures[DIR_SOUTH] = LoadTexture("assets/ant_s.png");
	player->textures[DIR_SOUTHWEST] = LoadTexture("assets/ant_sw.png");
	player->textures[DIR_WEST] = LoadTexture("assets/ant_w.png");

	player->direction = DIR_NORTH; 
}

void UpdatePlayer(Player *player) {

	bool up = IsKeyDown(KEY_W);
	bool down = IsKeyDown(KEY_S);
	bool left = IsKeyDown(KEY_A);
	bool right = IsKeyDown(KEY_D);

	if (up && left) player->direction = DIR_NORTHWEST;
	else if (up && right) player->direction = DIR_NORTHEAST;
	else if (down && right) player->direction = DIR_SOUTHEAST;
	else if (down && left) player->direction = DIR_SOUTHWEST;
	else if (up) player->direction = DIR_NORTH;
	else if (down) player->direction = DIR_SOUTH;
	else if (left) player->direction = DIR_WEST;
	else if (right) player->direction = DIR_EAST;

	float dt = GetFrameTime();
	if (up) player->position.y -= player->speed * dt;
	if (down) player->position.y += player->speed * dt;
	if (left) player->position.x -= player->speed * dt;
	if (right) player->position.x += player->speed * dt;
}

void DrawPlayer(Player *player) {
    float scale = 0.25f;
    Texture2D tex = player->textures[player->direction];

    Vector2 position = {
        GetScreenWidth() / 2.0f - (tex.width * scale) / 2.0f,
        GetScreenHeight() / 2.0f - (tex.height * scale) / 2.0f
    };

    DrawTextureEx(tex, position, 0.0f, scale, WHITE);
}

void UnloadPlayer(Player *player) {

    for (int i = 0; i < 7; i++) {
    	UnloadTexture(player->textures[i]);
	}

}