#include "Trainer.h"
#include "Pokemon.h"

int main()
{
    Pokemon volcanion = Pokemon("Volcanion", 80, 120, 105, Types::Fire, Types::Water);
    volcanion.DisplayInfos();
    return 0;
}
