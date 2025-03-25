#include "Trainer.h"

int main()
{
    Trainer player;
    player.DisplayInfos();
    player.AddItemToInventory(InventoryItems::Pokeball, 10);
    player.AddItemToInventory(InventoryItems::Potion, 5);
    player.RemoveItemFromInventory(InventoryItems::Pokeball, 11);
    player.DisplayInfos();

    return 0;
}
