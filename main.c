#include <raylib.h>
#include "raymath.h"
#include "data/player.h"
#include "data/enemy.h"
#define RAYGUI_IMPLEMENTATION
#include "gui/raygui.h"

typedef enum { GAME_RUNNING, GAME_OVER } GameState;

int main(void){

	InitWindow(800, 600, "game-engine");

	Player player;
	Enemy enemy;
	GameState state = GAME_RUNNING;
	Vector2 cameraOffset;

	InitPlayer(&player);
	InitEnemy(&enemy);
	cameraOffset = player.position;

	bool debugMode = false;
	//float playerSpeedSlider = player.speed;

	SetTargetFPS(60); //yea i can't afford RTX 5090

	while (!WindowShouldClose())
	{
		if (IsKeyPressed(KEY_TAB)) 
		{
			debugMode = !debugMode;
		}

		if (state == GAME_RUNNING) {

            UpdatePlayer(&player);
            UpdateEnemy(&enemy, player.position);

            cameraOffset = player.position; 

            if (EnemyCollidesWithPlayer(&enemy, player.position, player.size)) {
                state = GAME_OVER;
            }
        }

		BeginDrawing();
		ClearBackground(RAYWHITE);

		if (state == GAME_RUNNING) {

            DrawPlayer(&player);
            DrawEnemy(&enemy, cameraOffset);

        } else if (state == GAME_OVER) {
            DrawText("GAME OVER", 310, 200, 40, RED);

            if (GuiButton((Rectangle){ 300, 300, 200, 40 }, "Retry")) {
                InitPlayer(&player);
                InitEnemy(&enemy);
                state = GAME_RUNNING;
            }

            if (GuiButton((Rectangle){ 300, 350, 200, 40 }, "Quit")) {
                break;
            }
        }

        int tileSize = 100;

		for (int x = -tileSize; x < GetScreenWidth() + tileSize; x += tileSize) {
		    for (int y = -tileSize; y < GetScreenHeight() + tileSize; y += tileSize) {
		        int worldX = x + ((int)cameraOffset.x % tileSize) - tileSize;
		        int worldY = y + ((int)cameraOffset.y % tileSize) - tileSize;

		        DrawRectangleLines(worldX, worldY, tileSize, tileSize, LIGHTGRAY);
		    }
		}

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