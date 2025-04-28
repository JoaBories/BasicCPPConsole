#pragma once
#include "AllPokemons.h"
#include "Pokemon.h"
#include "Inventory.h"

enum GameStates
{
	Null,
	StarterChoice,
	BeginBattle,
	ActionChoice,
	AbilityChoice,
	ConfirmHeal,
};


class Engine
{
private:
	Pokemon mPlayerPokemon;
	Pokemon mEnemyPokemon;

	Inventory mPlayerInventory;

	GameStates mGameState;

	Vector2 mScreenSize;

	int RandInt(int min ,int max);
	void RandEnemyPokemon();

	void DisplayPokemon(Pokemon pokemon, float x, float y, float scale, bool fight) const;
	void DrawTextCentered(const char* text, int x, int y, int fontSize, Color color) const;

public:
	Engine();
	Engine(float screenWidth, float screenHeight);
	~Engine();

	void Init();

	void Update();
	void Draw();
	void Start();
};	

