#include <raylib.h>
#include "engine/player.h"

int main(void){

	InitWindow(800, 600, "game-engine");

	Player player;
	InitPlayer(&player);

	while (!WindowShouldClose())
	{
		UpdatePlayer(&player);
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawPlayer(&player);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}