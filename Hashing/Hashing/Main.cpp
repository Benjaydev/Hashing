#include <iostream>
#include <vector>
#include <string>
#include "HashTable.h"
#include "raylib.h"

const int TEXTURE_COUNT = 8;
HashTable<Texture2D> hashTable = HashTable<Texture2D>(TEXTURE_COUNT);
std::vector<unsigned int> displayTable;

void LoadTextureToTable(char* fileName) {
	unsigned int addedHash = hashTable.Add(fileName, LoadTextureFromImage(LoadImage(fileName)));
	std::cout << "Created Hash for '" << fileName << "': " << addedHash << std::endl;

	displayTable.push_back(addedHash);
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
		std::string nameHash = "HashedFileName: " + std::to_string(displayTable[0]);
		DrawText(nameHash.c_str(), 200, 100, 16, BLACK);
		std::string index = "TabeleIndex: " + std::to_string(displayTable[0] % TEXTURE_COUNT);
		DrawText(index.c_str(), 200, 80, 16, BLACK);

		DrawTexture(hashTable["Images/Ball2.png"], 100, 200, WHITE);
		nameHash = "HashedFileName: " + std::to_string(displayTable[1]);
		DrawText(nameHash.c_str(), 200, 200, 16, BLACK);
		index = "TabeleIndex: " + std::to_string(displayTable[1] % TEXTURE_COUNT);
		DrawText(index.c_str(), 200, 180, 16, BLACK);

		DrawTexture(hashTable["Images/Brick.png"], 100, 300, WHITE);
		nameHash = "HashedFileName: " + std::to_string(displayTable[2]);
		DrawText(nameHash.c_str(), 200, 300, 16, BLACK);
		index = "TabeleIndex: " + std::to_string(displayTable[2] % TEXTURE_COUNT);
		DrawText(index.c_str(), 200, 280, 16, BLACK);

		DrawTexture(hashTable["Images/CenterSegment.png"], 100, 400, WHITE);
		nameHash = "HashedFileName: " + std::to_string(displayTable[3]);
		DrawText(nameHash.c_str(), 200, 400, 16, BLACK);
		index = "TabeleIndex: " + std::to_string(displayTable[3] % TEXTURE_COUNT);
		DrawText(index.c_str(), 200, 380, 16, BLACK);


		DrawTexture(hashTable["Images/LeftEnd.png"], 500, 100, WHITE);
		nameHash = "HashedFileName: " + std::to_string(displayTable[4]);
		DrawText(nameHash.c_str(), 600, 100, 16, BLACK);
		index = "TabeleIndex: " + std::to_string(displayTable[4] % TEXTURE_COUNT);
		DrawText(index.c_str(), 600, 80, 16, BLACK);

		DrawTexture(hashTable["Images/Paddle.png"], 500, 200, WHITE);
		nameHash = "HashedFileName: " + std::to_string(displayTable[5]);
		DrawText(nameHash.c_str(), 600, 200, 16, BLACK);
		index = "TabeleIndex: " + std::to_string(displayTable[5] % TEXTURE_COUNT);
		DrawText(index.c_str(), 600, 180, 16, BLACK);

		DrawTexture(hashTable["Images/Powerup.png"], 500, 300, WHITE);
		nameHash = "HashedFileName: " + std::to_string(displayTable[6]);
		DrawText(nameHash.c_str(), 600, 300, 16, BLACK);
		index = "TabeleIndex: " + std::to_string(displayTable[6] % TEXTURE_COUNT);
		DrawText(index.c_str(), 600, 280, 16, BLACK);

		DrawTexture(hashTable["Images/RightEnd.png"], 500, 400, WHITE);
		nameHash = "HashedFileName: " + std::to_string(displayTable[7]);
		DrawText(nameHash.c_str(), 600, 400, 16, BLACK);
		index = "TabeleIndex: " + std::to_string(displayTable[7] % TEXTURE_COUNT);
		DrawText(index.c_str(), 600, 380, 16, BLACK);

		EndDrawing();
	}
	
	CloseWindow();
}

