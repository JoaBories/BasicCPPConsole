#include "Engine.h"
#include <iostream>
#include <random>

using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

using std::cout;
using std::endl;
using std::cin;

void Engine::ClearConsole()
{
	system("cls");
}

void Engine::Jumpline()
{
	cout << endl;
}

void Engine::WaitEnter()
{
	cout << endl << "Press Enter to continue..." << endl;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cin.get();

	ClearConsole();
}

int Engine::AskForInput(int maxInput)
{
	int input = 0;
	while (true)
	{
		std::cin >> input;

		if (std::cin.fail() || input < 1 || input > maxInput)
		{
			std::cin.clear(); // clear the error flag
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
			std::cout << "Invalid input. Try again." << std::endl;
		}
		else
		{
			return input; // valid input
		}
	}
}

int Engine::RandInt(int min, int max)
{
	static random_device rd;
	static mt19937 gen(rd());

	uniform_int_distribution<> distr(min, max);
	return distr(gen);
}

void Engine::StartBattle()
{
	int randomPokemon = RandInt(1, 3);
	switch (randomPokemon)
	{
	case 1:
		mEnemyPokemon = AllPokemons::Get()->GetPokemonCopy("Pidgey");
		break;

	case 2:
		mEnemyPokemon = AllPokemons::Get()->GetPokemonCopy("Caterpie");
		break;

	case 3:
		mEnemyPokemon = AllPokemons::Get()->GetPokemonCopy("Rattata");
		break;
	}

	cout << "A wild " << mEnemyPokemon.GetName() << " appeared!";

	WaitEnter();

	BattleLoop();
}

void Engine::BattleLoop()
{
	while (mPlayerPokemon.isAlive() && mEnemyPokemon.isAlive())
	{
		ClearConsole();
		cout << "Your Pokemon: ";
		mPlayerPokemon.DisplayShort();
		cout << "Enemy Pokemon: ";
		mEnemyPokemon.DisplayShort();

		cout << "Choose your action:" << endl;
		cout << "1. Attack" << endl;
		cout << "2. Heal" << endl;

		int action = AskForInput(2);

		switch (action)
		{
		case 1:
		{
			cout << "Choose your ability:" << endl;
			cout << "1. ";
			mPlayerPokemon.GetAbilityPtrByIndex(0)->DisplayShort();
			Jumpline();
			cout << "2. ";
			mPlayerPokemon.GetAbilityPtrByIndex(1)->DisplayShort();
			Jumpline();

			int abilityIndex = AskForInput(2) - 1;
			int enemyAbilityIndex = RandInt(0, 1);

			int weak = 0;

			if (mPlayerPokemon.GetSpeed() >= mEnemyPokemon.GetSpeed())
			{
				weak = mPlayerPokemon.Attack(abilityIndex, &mEnemyPokemon, RandInt(0,100));
				cout << mPlayerPokemon.GetName() << " used " << mPlayerPokemon.GetAbilityPtrByIndex(abilityIndex)->GetName() << "!" << endl;
				switch (weak)
				{
				case 0:
					cout << "It failed" << endl;
					break;

				case 2:
					cout << "It's effective!" << endl;
					break;

				case 4:
					cout << "It's super effective..." << endl;
					break;
				}
				Jumpline();

				if (mEnemyPokemon.isAlive())
				{
					weak = mEnemyPokemon.Attack(enemyAbilityIndex, &mPlayerPokemon, RandInt(0, 100));
					cout << mEnemyPokemon.GetName() << " used " << mEnemyPokemon.GetAbilityPtrByIndex(enemyAbilityIndex)->GetName() << "!" << endl;
					switch (weak)
					{
					case 0:
						cout << "It failed" << endl;
						break;

					case 2:
						cout << "It's effective!" << endl;
						break;

					case 4:
						cout << "It's super effective..." << endl;
						break;
					}
				}

			}
			else
			{
				weak = mEnemyPokemon.Attack(enemyAbilityIndex, &mPlayerPokemon, RandInt(0, 100));
				cout << mEnemyPokemon.GetName() << " used " << mEnemyPokemon.GetAbilityPtrByIndex(enemyAbilityIndex)->GetName() << "!" << endl;
				switch (weak)
				{
				case 0:
					cout << "It failed" << endl;
					break;

				case 2:
					cout << "It's effective!" << endl;
					break;

				case 4:
					cout << "It's super effective..." << endl;
					break;
				}

				Jumpline();

				if (mEnemyPokemon.isAlive())
				{
					weak = mPlayerPokemon.Attack(abilityIndex, &mEnemyPokemon, RandInt(0, 100));
					cout << mPlayerPokemon.GetName() << " used " << mPlayerPokemon.GetAbilityPtrByIndex(abilityIndex)->GetName() << "!" << endl;
					switch (weak)
					{
					case 0:
						cout << "It failed" << endl;
						break;

					case 2:
						cout << "It's effective!" << endl;
						break;

					case 4:
						cout << "It's super effective..." << endl;
						break;
					}
				}
			}

			break;
		}

		case 2:
		{
			mPlayerInventory.RemoveItemFromInventory("Potion");
			mPlayerPokemon.HealMe(AllItems::Get()->GetHealPtr("Potion"));

			cout << "You used a Potion, you have" << mPlayerInventory.GetItemNumberInInventory("Potion") << endl;
			
			int enemyAbilityIndex = RandInt(0, 1);

			int weak = mEnemyPokemon.Attack(enemyAbilityIndex, &mPlayerPokemon, RandInt(0, 100));
			cout << mEnemyPokemon.GetName() << " used " << mEnemyPokemon.GetAbilityPtrByIndex(enemyAbilityIndex)->GetName() << "!" << endl;
			switch (weak)
			{
			case 0:
				cout << "It failed" << endl;
				break;

			case 2:
				cout << "It's effective!" << endl;
				break;

			case 4:
				cout << "It's super effective..." << endl;
				break;
			}

			Jumpline();

			break;
		}


		}

		if (!mPlayerPokemon.isAlive())
		{
			LooseBattle();
			return;
		}
		else if (!mEnemyPokemon.isAlive())
		{
			StartBattle();
			return;
		}

		WaitEnter();
	}

	return;
}

void Engine::LooseBattle()
{
	cout << "You lost the battle!" << endl;
	return;
}

Engine::Engine() :
mPlayerInventory{ Inventory() }
{
	cout << "Welcome to the Pokemon Battle!" << endl;
	cout << "Please select your Pokemon:" << endl;
	cout << "1. ";
	AllPokemons::Get()->GetPokemonPtr("Charmander")->DisplayShort();
	cout << "2. ";
	AllPokemons::Get()->GetPokemonPtr("Squirtle")->DisplayShort();
	cout << "3. ";
	AllPokemons::Get()->GetPokemonPtr("Bulbasaur")->DisplayShort();

	switch (AskForInput(3))
	{
	case 1:
		mPlayerPokemon = AllPokemons::Get()->GetPokemonCopy("Charmander");
		break;

	case 2:
		mPlayerPokemon = AllPokemons::Get()->GetPokemonCopy("Squirtle");
		break;

	case 3:
		mPlayerPokemon = AllPokemons::Get()->GetPokemonCopy("Bulbasaur");
		break;

	}
	ClearConsole();
	cout << "You have selected: ";
	mPlayerPokemon.DisplayLarge();

	WaitEnter();

	StartBattle();
}

Engine::~Engine()
{
}
