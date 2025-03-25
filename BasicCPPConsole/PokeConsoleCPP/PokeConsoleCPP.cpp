#include "Trainer.h"
#include "Pokemon.h"

int main()
{
    Pokemon volcanion = Pokemon("Volcanion", 80, 120, 105, 70, new Types[2]{ Types::Fire, Types::Water }, new string[4]{"Flame Burst", "WithDraw", "", ""});
    /*volcanion.DisplayInfos();*/
    return 0;
}
