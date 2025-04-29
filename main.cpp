#include "raylib.h"
#include <iostream>
#include <vector>

#include "Engine.h"

void Init();
void DeInit();
void UpdateDraw();
void Update();
void Draw();

int screenWidth = 720;
int screenHeight = 720;

Texture LoadTextureFromSource(const char *source);

AllPokeTypes i1 = AllPokeTypes();  //Instance initialisation
AllAbilities i2 = AllAbilities();
AllItems i3 = AllItems();
AllPokemons i4 = AllPokemons();

Engine engine = Engine(screenWidth, screenHeight);

Music music;

int main() {   
    
    Init();
    
    while (!WindowShouldClose()) {  
   
        UpdateDraw();
        
		if (engine.ShouldExit()) {
			break;
		}
    }

    DeInit();

    return 0;
}

void Init()
{
    InitWindow(720, 720, "PokeRaylib");
    SetTargetFPS(60);

    music = LoadMusicStream("resources/sound/music.mp3");
    PlayMusicStream(music);

	engine.Init();
	engine.Start();
}

void UpdateDraw()
{
	Update();

    UpdateMusicStream(music);

    BeginDrawing();
	Draw();

    ClearBackground(BLACK);
    EndDrawing();
}

void Update()
{
	engine.Update();
}

void Draw()
{
	engine.Draw();
}

void DeInit()
{
    UnloadMusicStream(music);
    CloseWindow();

}

Texture LoadTextureFromSource(const char *source)
{
    Image img = LoadImage(source);
    Texture text = LoadTextureFromImage(img);

    UnloadImage(img);

    return text;
}
