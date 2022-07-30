// Number guessing game
#include <iostream>
using namespace std;
void printRules()
{
    cout << "\t******  WELCOME TO NUMBER GUESSING GAME  ******" << endl;
    cout << "\t\t\t\t-Made by Dhruv Mahajan" << endl;
    cout << "  Rules of the game are as follows :- \n";
    cout << "# You have 100 coins \n";
    cout << "# Guess a number between 1 to 9 \n";
    cout << "# If you guessed correctly you will get 10 times your bet \n";
    cout << "# Otherwise, coins you bet will be lost \n";
    cout << "# Accumulate 1000 coins to win the game \n";
    cout << "# The game will be over, If you lose all your coins \n";
    printf("GOOD LUCK %c",1);
}
int main()
{
    int coins = 100, bet, actual_num, player_choice;
    char c = 'n';
    printRules();
    while (coins > 0)
    {
        cout << "\n*Coins Left: " << coins << "*" << endl;
        while (1)
        {
            cout << "Enter the amount you want to bet: ";
            cin >> bet;
            if (bet > coins)
            {
                cout << "\nINSUFFICIENT COIN BALANCE!!!\n";
            }
            else
                break;
        }
        coins -= bet;
        while (1)
        {
            cout << "Guess a number and enter it: ";
            cin >> player_choice;
            if (player_choice < 1 || player_choice > 9)
                cout << "\nPlease enter a number between 1 to 9 !!!!\n"
                     << endl;
            else
                break;
        }
        actual_num = ((rand() % 10) + 1);
        if (actual_num == player_choice)
        {
            cout << "Congratulations!! You guessed the correct number" << endl;
            coins += bet * 10;
        }
        else
        {
            cout << "Sorry, You guessed the wrong number\nThe actual number was " << actual_num << endl;
            cout << "You lost " << bet << " coins" << endl;
        }
        if (coins <= 0)
        {
            cout << "\n*Coins Left: " << coins << "*" << endl;
            cout << endl
                 << "\t\tGAME OVER !!!";
            cout << "\nDo you want to play again?(Y/N) :";
            cin >> c;
            if (c == 'Y' || c == 'y')
                coins = 100;
            else
                break;
        }
        if (coins >= 1000)
        {
            cout << "\n*Coins Left: " << coins << "*" << endl;
            cout << "\n\t\tCongratulations!!! YOU WON THE GAME" << endl;
            cout << "\nDo you want to play again?(Y/N) :";
            cin >> c;
            if (c == 'Y' || c == 'y')
                coins = 100;
            else
                break;
        }
    }
    return 0;
}