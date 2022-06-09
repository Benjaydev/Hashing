#include <iostream>
#include "HashTable.h"
#include "raylib.h"

HashTable<Texture2D> hashTable = HashTable<Texture2D>(8);

void LoadTextureToTable(char* fileName) {
	hashTable.Add(fileName, LoadTextureFromImage(LoadImage(fileName)));
}

int main()
{
	InitWindow(900, 600, "Hash table test");

	// Load the textures and store them in the hash table
	LoadTextureToTable((char*)"Images/Ball.png");
	LoadTextureToTable((char*)"Images/Ball2.png");
	LoadTextureToTable((char*)"Images/Brick.png");
	LoadTextureToTable((char*)"Images/CenterSegment.png");
	LoadTextureToTable((char*)"Images/LeftEnd.png");
	LoadTextureToTable((char*)"Images/Paddle.png");
	LoadTextureToTable((char*)"Images/Powerup.png");
	LoadTextureToTable((char*)"Images/RightEnd.png");
	

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(WHITE);

		DrawFPS(0, 0);

		// Draw each texture from the hash table
		DrawTexture(hashTable["Images/Ball.png"], 100, 100, WHITE);
		DrawTexture(hashTable["Images/Ball2.png"], 200, 100, WHITE);
		DrawTexture(hashTable["Images/Brick.png"], 300, 100, WHITE);
		DrawTexture(hashTable["Images/CenterSegment.png"], 400, 100, WHITE);
		DrawTexture(hashTable["Images/LeftEnd.png"], 500, 100, WHITE);
		DrawTexture(hashTable["Images/Paddle.png"], 600, 100, WHITE);
		DrawTexture(hashTable["Images/Powerup.png"], 700, 100, WHITE);
		DrawTexture(hashTable["Images/RightEnd.png"], 800, 100, WHITE);

		EndDrawing();
	}
	
	CloseWindow();
}

