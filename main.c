#include <raylib.h>
#include "data/player.h"
#define RAYGUI_IMPLEMENTATION
#include "gui/raygui.h"

int main(void){

	InitWindow(800, 600, "game-engine");

	Player player;
	InitPlayer(&player);

	bool debugMode = false;
	float playerSpeedSlider = player.speed;

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		if (IsKeyPressed(KEY_TAB)) 
		{
			debugMode = !debugMode;
		}

		UpdatePlayer(&player);
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawPlayer(&player);

		if (debugMode) {

			GuiPanel((Rectangle){10,10,220,90}, "Debug");

			static float speed = 0.0f;
			speed = player.speed;

			GuiSliderBar((Rectangle){20,40,180,20}, "Speed\n", TextFormat("%.2f",speed), &speed, 0.0f, 1000.0f);

			player.speed = speed;
		}

		EndDrawing();
	}

	CloseWindow();

	return 0;
}