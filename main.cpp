#include "raylib.h"
#include <iostream>
#include <vector>

#include "Engine.h"

void Init();
void DeInit();
void UpdateDraw();

Texture LoadTextureFromSource(const char *source);

int main() {   
    
    Init();

    while (!WindowShouldClose()) {  
   
        UpdateDraw();
        
    }

    DeInit();

    return 0;
}

void Init()
{
    InitWindow(720, 720, "PokeRaylib");
    SetTargetFPS(60);

    AllPokeTypes i1 = AllPokeTypes();  //Instance initialisation
    AllAbilities i2 = AllAbilities();
    AllItems i3 = AllItems();
    AllPokemons i4 = AllPokemons();

    Engine engine;
}

void UpdateDraw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    EndDrawing();
}

void DeInit()
{
    CloseWindow();

}

Texture LoadTextureFromSource(const char *source)
{
    Image img = LoadImage(source);
    Texture text = LoadTextureFromImage(img);

    UnloadImage(img);

    return text;
}
