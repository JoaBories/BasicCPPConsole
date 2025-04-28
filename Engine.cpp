#include "Engine.h"
#include <iostream>
#include <random>

using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

using std::to_string;

using std::cout;
using std::endl;
using std::cin;

int Engine::RandInt(int min, int max)
{
	static random_device rd;
	static mt19937 gen(rd());

	uniform_int_distribution<> distr(min, max);
	return distr(gen);
}

void Engine::RandEnemyPokemon()
{
	int randomPokemon = RandInt(1, 3);
	switch (randomPokemon)
	{
	case 1:
		mEnemyPokemon = AllPokemons::Get()->GetPokemonCopy("pidgey");
		break;

	case 2:
		mEnemyPokemon = AllPokemons::Get()->GetPokemonCopy("caterpie");
		break;

	case 3:
		mEnemyPokemon = AllPokemons::Get()->GetPokemonCopy("rattata");
		break;
	}
}

void Engine::DisplayPokemon(Pokemon pokemon, float x, float y, float scale, bool fight) const
{
	Texture pokemonTexture = AllPokemons::Get()->GetPokemonTexture(pokemon.GetName());
	// Display the Pokemon's texture at the specified coordinates
	float xCentered = x - (pokemonTexture.width / 2) * scale;
	float yCentered = y - (pokemonTexture.height / 2) * scale;

	DrawTextureEx(pokemonTexture, Vector2{ xCentered, yCentered }, 0, scale, WHITE);

	// Display the Pokemon's name below the texture
	DrawTextCentered(pokemon.GetName().c_str(), x, yCentered + pokemonTexture.height * scale + 5, 20, WHITE);

	if (fight)
	{
		string hpText = "HP: " + to_string(pokemon.GetHp()) + " / " + to_string(pokemon.GetMaxHp());
		DrawTextCentered(hpText.c_str(), x, yCentered + pokemonTexture.height * scale + 5, 20, WHITE);
	}
}

void Engine::DrawTextCentered(const char* text, int x, int y, int fontSize, Color color) const
{
	int textWidth = MeasureText(text, fontSize);
	int xCentered = x - (textWidth / 2);
	xCentered = xCentered < 0 ? 0 : xCentered;
	xCentered = xCentered > mScreenSize.x ? mScreenSize.x : xCentered;
	y = y < 0 ? 0 : y;
	y = y > mScreenSize.y ? mScreenSize.y : y;

	DrawText(text, xCentered, y, fontSize, color);
}

Engine::Engine() :
mPlayerInventory{ Inventory() },
mGameState{ GameStates::Null },
mScreenSize { 0, 0 }
{
	
}

Engine::Engine(float screenWidth, float screenHeight) :
mPlayerInventory{ Inventory() },
mGameState{ GameStates::Null },
mScreenSize{ screenWidth, screenHeight }
{
}

Engine::~Engine()
{
}

void Engine::Init()
{
	AllPokemons::Get()->LoadAllTextures();
}

void Engine::Update()
{
	switch (mGameState)
	{
	case Null:
		break;

	case StarterChoice:
		if (IsKeyPressed(KEY_ONE))
		{
			mPlayerPokemon = AllPokemons::Get()->GetPokemonCopy("bulbasaur");
			RandEnemyPokemon();
			mGameState = GameStates::BeginBattle;
		}
		else if (IsKeyPressed(KEY_TWO))
		{
			mPlayerPokemon = AllPokemons::Get()->GetPokemonCopy("charmander");
			RandEnemyPokemon();
			mGameState = GameStates::BeginBattle;
		}
		else if (IsKeyPressed(KEY_THREE))
		{
			mPlayerPokemon = AllPokemons::Get()->GetPokemonCopy("squirtle");
			RandEnemyPokemon();
			mGameState = GameStates::BeginBattle;
		}
		break;

	case BeginBattle:
		if (IsKeyPressed(KEY_ENTER))
		{
			mGameState = GameStates::ActionChoice;
		}
		break;

	case ActionChoice:
		if (IsKeyPressed(KEY_ONE))
		{
			mGameState = GameStates::AbilityChoice;
		}
		else if (IsKeyPressed(KEY_TWO))
		{
			mGameState = GameStates::ConfirmHeal;
		}
		break;
	}
}

void Engine::Draw()
{
	float topScreenPos = mScreenSize.y / 4;
	float middleScreenPos = mScreenSize.y / 2;
	float bottomScreenPos = mScreenSize.y / 4 * 3;


	switch (mGameState)
	{
	case Null:
		
		break;

	case StarterChoice:

		DisplayPokemon(AllPokemons::Get()->GetPokemonCopy("bulbasaur"), mScreenSize.x / 5, topScreenPos, 4, false);
		DisplayPokemon(AllPokemons::Get()->GetPokemonCopy("charmander"), mScreenSize.x / 2, topScreenPos, 4, false);
		DisplayPokemon(AllPokemons::Get()->GetPokemonCopy("squirtle"), mScreenSize.x / 5 * 4, topScreenPos, 4, false);

		DrawTextCentered("Choose your starter Pokemon", mScreenSize.x / 2, middleScreenPos, 20, WHITE);

		DrawTextCentered("1", mScreenSize.x / 5, bottomScreenPos, 40, WHITE);
		DrawTextCentered("2", mScreenSize.x / 2, bottomScreenPos, 40, WHITE);
		DrawTextCentered("3", mScreenSize.x / 5 * 4, bottomScreenPos, 40, WHITE);
		break;

	case BeginBattle:
		DisplayPokemon(mEnemyPokemon, mScreenSize.x / 2, topScreenPos, 4, false);

		DrawTextCentered(("A wild " + mEnemyPokemon.GetName() + " appeared").c_str(), mScreenSize.x / 2, middleScreenPos, 20, WHITE);

		DrawTextCentered("Press Enter to continue", mScreenSize.x / 2, bottomScreenPos, 20, WHITE);
		break;

	case ActionChoice:
		DrawTextCentered("Choose an action", mScreenSize.x / 2, middleScreenPos, 20, WHITE);
		DrawTextCentered("1 Attack", mScreenSize.x / 4, bottomScreenPos, 20, WHITE);
		DrawTextCentered("2 Heal", mScreenSize.x / 4 * 3, bottomScreenPos, 20, WHITE);
		break;
	}
}

void Engine::Start()
{
	mGameState = GameStates::StarterChoice;
}
