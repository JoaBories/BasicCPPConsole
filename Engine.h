#pragma once
#include "AllPokemons.h"
#include "Pokemon.h"
#include "Inventory.h"

class Engine
{
private:
	Pokemon mPlayerPokemon;
	Pokemon mEnemyPokemon;

	Inventory mPlayerInventory;

	void ClearConsole();
	void Jumpline();
	void WaitEnter();
	int AskForInput(int maxInput);
	int RandInt(int min ,int max);
	void StartBattle();
	void BattleLoop();
	void LooseBattle();

public:
	Engine();
	~Engine();
};	

