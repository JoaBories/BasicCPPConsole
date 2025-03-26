#include "Trainer.h"

int main()
{
    AllPokeTypes i1 = AllPokeTypes();  //Instance initialisation
    AllAbilities i2 = AllAbilities();
    AllItems i3 = AllItems();

    Pokemon volcanion = Pokemon("Volcanion", 80, 120, 105, 70, new Types[2]{ Types::Fire, Types::Water }, new string[4]{"Flame Burst", "Withdraw", "", ""});
    volcanion.Display();

    Trainer ash = Trainer();
    ash.Display();
    ash.inventory.AddItemToInventory("Pokeball", 5);
    ash.inventory.AddItemToInventory("Potion", 5);
    ash.Display();

    return 0;
}
