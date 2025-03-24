// BasicCPPConsole.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>

using std::cout;
using std::cin;
using std::endl;
using std::rand;
using std::string;
using std::vector;
using std::map;

#pragma region Function


void JumpLine() 
{
    cout << endl;
}

void DrawSeparator(string separator)
{
    cout << separator << endl;
}

int Sum(int *a, const size_t size) 
{
    int sum = 0;

    for (size_t i = 0; i < size; i++)
    {
        sum += a[i];
    }

    return sum;
}

int RollAbility() 
{
    const size_t numberOfRolls = 4;
    int rolls[numberOfRolls];
    int minimumRoll = 18;
    int minimumRollIndex = 0;

    for (size_t i = 0; i < 4; i++)
    {
        rolls[i] = ((rand() % 6) + 1) * 3;
        cout << rolls[i];
        if (rolls[i] < minimumRoll) 
        {
            minimumRoll = rolls[i];
            minimumRollIndex = i;
        }
    }
    JumpLine();

    rolls[minimumRollIndex] = 0;

    return Sum(rolls, numberOfRolls);
}

    
#pragma endregion

int main()
{
    srand(time(NULL));

    string narrator = "The Almighty";
    string separator = "\n---------------------------------------------\n";

#pragma region Intro

    cout << "Hello i am " << narrator << "! \nWhat's your name ?" << endl;
    string playerName;
    cin >> playerName;

    cout << "Glad to see you " << playerName << " ! " << endl;

#pragma endregion

#pragma region Abilities

    DrawSeparator(separator);

    cout << "Now your abilities :" << endl;

    map<string, int> abilities{
        {"strength", RollAbility()},
        {"dexterity", RollAbility()},
        {"constitution", RollAbility()},
        {"intelligence", RollAbility()}
    };

    cout << "   Strength : " << abilities["strenght"] << endl;
    cout << "   Dexterity : " << abilities["dexterity"] << endl;
    cout << "   Constitution : " << abilities["constitution"] << endl;
    cout << "   Intelligence : " << abilities["intelligence"] << endl;

    DrawSeparator(separator);
    JumpLine();

#pragma endregion
    
#pragma region Class

    if (abilities["strenght"] >= 12 || abilities["constitution"] >= 12) 
    {
        cout << "Consider to become a Warrior" << endl;
    }
    else if (abilities["intelligence"] <= 6) 
    {
        cout << "Consider to be a barabarian" << endl;
    }
    else
    {
        cout << "consider to be a bard" << endl;
    }

    JumpLine();

    cout << "So now what do you want to become ?\n 1 - Warrior \n 2 - Rogue \n 3 - Mage \n 4 - Barbarian" << endl;
    int playerClassChoice;
    cin >> playerClassChoice;

    switch (playerClassChoice)
    {
    case 1:
        cout << "So " << playerName << " the Warrior, Ok" << endl;
        break;
    case 2:
        cout << "So " << playerName << " the Rogue, Ok" << endl;
        break;
    case 3:
        cout << "So " << playerName << " the Mage, Ok" << endl;
        break;
    case 4:
        cout << "So " << playerName << " the Barbarian, Ok" << endl;
        break;
    default:
        cout << "You will be " << playerName << " the  bard" << endl;
        break;
    }

    DrawSeparator(separator);

#pragma endregion

#pragma region Bags

    string smallbag[5] = { "Sword", "Shield", "Bow" };
    vector<string> magicBag = { "Magic Hat", "Magic Wand", "Magic Cape" };

    cout << "You have 2 bags : a small one where you can put 5 items and a magic one where you can put how much you want but magics items." << endl << endl;

    cout << "In your small bag you have :" << endl;
    for (int i = 0; i < 5; i++) 
    {
        if (smallbag[i] != "")
        {
            cout << "\t -" << smallbag[i] << endl;
        }
    }

    JumpLine();

    cout << "In your magic bag you have :" << endl;
    for (string item : magicBag) 
    {
        cout << "\t -" << item << endl;
    }

#pragma endregion

#pragma region Begin of Adventure

    DrawSeparator(separator);

    cout << "Now you are good to go on adventure. Are you ready ? 1 - Yes / 2 - No" << endl;
    int playerAnswer;
    cin >> playerAnswer;

    while (playerAnswer != 1)
    {
        cout << "C'mon you can do it ! 1 - Yes / 2 - No" << endl;
        cin >> playerAnswer;
    }

    JumpLine();
    cout << "Now we go" << endl;

    do
    {
        cout << "Do you want a cookie before ? 1 - Yes / 2 - No" << endl;
        cin >> playerAnswer;
    } while (playerAnswer != 1);


#pragma endregion


    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
