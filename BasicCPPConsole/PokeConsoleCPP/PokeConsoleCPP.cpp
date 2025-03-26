#include "Trainer.h"

int main()
{
    AllPokeTypes i1 = AllPokeTypes();  //Instance initialisation
    AllAbilities i2 = AllAbilities();
    AllItems i3 = AllItems();

    Pokemon volcanion = Pokemon("Volcanion", 80, 120, 105, 70, new Types[2]{ Types::Fire, Types::Water }, new string[4]{"Flame Burst", "Withdraw", "", ""});
    Pokemon bulbasaur = Pokemon("Bulbasaur", 45, 57, 57, 45, new Types[2]{ Types::Plant, Types::Null }, new string[4]{"", "", "", ""});
    volcanion.Display(true);
    bulbasaur.Display(true);
    volcanion.Attack(volcanion.GetAbilityPtrByIndex(0), &bulbasaur);
    bulbasaur.Display(true);
    bulbasaur.HealMe(AllItems::Get()->GetHealPtr("Potion"));
    bulbasaur.Display(true);

    return 0;
}
