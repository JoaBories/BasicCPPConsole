#include "Trainer.h"

using std::cin;

int main()
{
    AllPokeTypes i1 = AllPokeTypes();  //Instance initialisation
    AllAbilities i2 = AllAbilities();
    AllItems i3 = AllItems();
	AllPokemons i4 = AllPokemons();

    Pokemon charmander = AllPokemons::Get()->GetPokemonCopy("Charmander");
    Pokemon bulbasaur = AllPokemons::Get()->GetPokemonCopy("Bulbasaur");

    charmander.Display(true);
    bulbasaur.Display(true);
    charmander.Attack(charmander.GetAbilityPtrByIndex(0), &bulbasaur);
    bulbasaur.Display(true);
    bulbasaur.HealMe(AllItems::Get()->GetHealPtr("Potion"));
    bulbasaur.Display(true);

    string temp;
    cin >> temp;

    return 0;
}
