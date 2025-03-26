#include "Trainer.h"

int main()
{
    AllPokeTypes i1 = AllPokeTypes();
    AllAbilities i2 = AllAbilities();
    AllItems i3 = AllItems();

    Pokemon volcanion = Pokemon("Volcanion", 80, 120, 105, 70, new Types[2]{ Types::Fire, Types::Water }, new string[4]{"Flame Burst", "Withdraw", "", ""});
    volcanion.Display();

    return 0;
}
