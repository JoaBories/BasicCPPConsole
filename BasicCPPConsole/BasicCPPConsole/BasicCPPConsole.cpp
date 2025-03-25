#include <iostream>
#include <vector>
#include <map>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::rand;
using std::string;
using std::vector;
using std::map;
using std::numeric_limits;
using std::streamsize;

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
    size_t minimumRollIndex = 0;

    for (size_t i = 0; i < 4; i++)
    {
        rolls[i] = ((rand() % 6) + 1) * 3;

        if (rolls[i] < minimumRoll) 
        {
            minimumRoll = rolls[i];
            minimumRollIndex = i;
        }
    }

    rolls[minimumRollIndex] = 0;

    return Sum(rolls, numberOfRolls);
}

void DisplayBagArray(string* bag, const size_t size) 
{
    for (size_t i = 0; i < size; i++)
    {
        if (bag[i] != "")
        {
            cout << "\t -" << bag[i] << endl;
        }
    }
}

void DisplayBagVector(vector<string> bag)
{
    for (string item : bag)
    {
        cout << "\t -" << item << endl;
    }
}

int AskForInt(string firstQ, string secondQ, int maxAnswer) //  1 - Yes / 2 - No : maxAnswer = 2
{
    int playerAnswer;

    cout << firstQ << endl;

    cin >> playerAnswer;
    if (!cin.good()) 
    {
        playerAnswer = 0;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (playerAnswer > maxAnswer || playerAnswer < 1)
    {
        cout << secondQ << endl;
        cin >> playerAnswer;

        if (!cin.good())
        {
            playerAnswer = 0;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return playerAnswer;
}

    
#pragma endregion

int main()
{

#pragma region Variables

    srand(time(NULL));

    string narrator = "The Almighty";
    string separator = "\n---------------------------------------------\n";

    string playerName;
    char playerClass;

    map<string, int> abilities{
        {"strength", RollAbility()},
        {"dexterity", RollAbility()},
        {"constitution", RollAbility()},
        {"intelligence", RollAbility()}
    };

    string smallbag[5] = { "Sword", "Shield", "Bow" };
    vector<string> magicBag = { "Magic Hat", "Magic Wand", "Magic Cape" };

    string playerAnswerStr;
    int playerAnswerInt;
    int tries = 0;

#pragma endregion

#pragma region Intro

    cout << "Hello i am " << narrator << "! \nWhat's your name ?" << endl;
    
    cin >> playerName;

    cout << "Glad to see you " << playerName << " ! " << endl;

#pragma endregion

#pragma region Abilities

    DrawSeparator(separator);

    cout << "Abilities :" << endl;

    cout << "   Strength : " << abilities["strength"] << endl;
    cout << "   Dexterity : " << abilities["dexterity"] << endl;
    cout << "   Constitution : " << abilities["constitution"] << endl;
    cout << "   Intelligence : " << abilities["intelligence"] << endl;

    DrawSeparator(separator);

#pragma endregion
    
#pragma region Class

    if ((abilities["strenght"] >= 30 && abilities["constitution"] >= 20) || (abilities["strenght"] >= 20 && abilities["constitution"] >= 30))
    {
        cout << "TIP : Consider to become a Warrior" << endl;
    }
    else if (abilities["intelligence"] <= 12)
    {
        cout << "TIP : Consider to be a Barbarian" << endl;
    }
    else if (abilities["intelligence"] >= 48)
    {
        cout << "TIP : consider to be a Mage" << endl;
    }
    else if (abilities["intelligence"] >= 20 && abilities["dexterity"] >= 42)
    {
        cout << "TIP : consider to be a Rogue" << endl;
    }

    JumpLine();

    playerAnswerInt = AskForInt("So now what do you want to become ?\n 1 - Warrior \n 2 - Archer \n 3 - Mage \n 4 - Barbarian", "Answer with 1, 2, 3 or 4", 4);

    switch (playerAnswerInt)
    {
    case 1:
        cout << "So " << playerName << " the Warrior, Ok" << endl;
        playerClass = 'W';
        break;
    case 2:
        cout << "So " << playerName << " the Archer, Ok" << endl;
        playerClass = 'A';
        break;
    case 3:
        cout << "So " << playerName << " the Mage, Ok" << endl;
        playerClass = 'M';
        break;
    case 4:
        cout << "So " << playerName << " the Barbarian, Ok" << endl;
        playerClass = 'B';
        break;
    default:
        cout << "That shouldn't happen" << endl;
        break;
    }

    DrawSeparator(separator);

#pragma endregion

#pragma region Bags

    cout << "You have 2 bags : a small one where you can put 5 items and a magic one where you can put how much you want but magics items." << endl << endl;

    cout << "For the beggining in your small bag you have :" << endl;
    DisplayBagArray(smallbag, 5);

    JumpLine();

    cout << "For the beggining in your magic bag you have :" << endl;
    DisplayBagVector(magicBag);
    

#pragma endregion

#pragma region Begin of Adventure

    DrawSeparator(separator);

    cout << "Now you are good to go on adventure. Are you ready ? 1 - Yes / 2 - No" << endl;

    cin >> playerAnswerInt;

    while (playerAnswerInt != 1)
    {
        cout << "C'mon you can do it ! 1 - Yes / 2 - No" << endl;
        cin >> playerAnswerInt;
    }

    JumpLine();
    
    tries = 0;

    if (AskForInt("And ... do you want a cookie before to go ? 1 - Yes / 2 - No", "Sure ? 1 - Yes / 2 - No", 2) == 1)
    {
        magicBag.push_back("Magic Cookie");
    }
    

    JumpLine();
    cout << "Now we can go. GOOD LUCK" << endl;


#pragma endregion

    return 0;
}
