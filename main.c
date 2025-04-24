#include <raylib.h>
#include "raymath.h"
#include "data/player.h"
#include "data/enemy.h"
#define RAYGUI_IMPLEMENTATION
#include "gui/raygui.h"

typedef enum { GAME_RUNNING, GAME_OVER } GameState;

int main(void){

	InitWindow(800, 600, "Ants VS Termites");

	Texture2D background = LoadTexture("assets/dirt.png");

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

		int bgTileSize = background.width;

		int offsetX = ((int)cameraOffset.x % bgTileSize + bgTileSize) % bgTileSize;
		int offsetY = ((int)cameraOffset.y % bgTileSize + bgTileSize) % bgTileSize;

		for (int x = -bgTileSize; x < GetScreenWidth() + bgTileSize; x += bgTileSize) {
		    for (int y = -bgTileSize; y < GetScreenHeight() + bgTileSize; y += bgTileSize) {
		        DrawTexture(background, x - offsetX, y - offsetY, WHITE);
		    }
		}

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

		if (debugMode) {
		    int panelX = 10;
		    int panelY = 10;
		    int panelWidth = 220;
		    int panelHeight = 100;

		    GuiPanel((Rectangle){panelX, panelY, panelWidth, panelHeight}, "Debug");

		    static float speed = 0.0f;
		    speed = player.speed;

		    DrawText("Speed", panelX + 10, panelY + 30, 10, GRAY);
		    DrawText(TextFormat("%.2f", speed), panelX + panelWidth - 60, panelY + 30, 10, GRAY);

		    GuiSliderBar(
		        (Rectangle){panelX + 10, panelY + 50, panelWidth - 20, 20},
		        NULL,
		        NULL,
		        &speed,
		        0.0f,
		        1000.0f
		    );

		    player.speed = speed;
		}

        EndDrawing();
	}

	UnloadPlayer(&player);
	UnloadEnemy(&enemy);
	UnloadTexture(background);

	CloseWindow();

	return 0;

}