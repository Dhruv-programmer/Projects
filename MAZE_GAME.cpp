#include <iostream>
#include <conio.h>
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
bool gameOver , bomb ;
int x, y;             // Position of player
int finishX, finishY; // Finishing point
const int row = 19, col = 19;
vector<string> maze =
    {
        {"###################",
         "#    ### #   #    #",
         "## #   #B  # #### #",
         "## ##      #      #",
         "#B  ############ ##",
         "###     #    #    #",
         "# #### ## #########",
         "# #    # ## #     #",
         "### #### #    # # #",
         "# #  #   #### # # #",
         "# ##    ##  # # # #",
         "#     ##    # # ###",
         "### #  # ## # #   #",
         "#   ## # #    ##  #",
         "#   B#   ####B# B #",
         "## # ####B    # # #",
         "#### #  #  B# #   #",
         "#          ##   ###",
         "###################"
         }};
void setup()
{
    gameOver = false;
    bomb = false;
    x = 1;
    y = 14;
    finishX = row - 2;
    finishY = 1;
}
void draw()
{
    system("cls");
    cout<<endl<<endl<<endl;
    for (int i = 0; i < row; i++)
    {
        cout<<"\t\t";
        for (int j = 0; j < col; j++)
        {
            if (i == x && j == y)
                cout << "O";
            else if (i == finishX && j == finishY)
                cout << "X";
            else if(maze[i][j] != ' ')
                cout<<maze[i][j];
            else
            {
                char a = 176;
                cout<<a;
            }
        }
        cout << endl;
    }
}
void logic()
{ 
    int ch = 0;
    switch (ch = getch())
    {
    case 72:
        if (maze[x - 1][y] != '#')
            x--;
        break;
    case 77:
        if (maze[x][y + 1] != '#')
            y++;
        break;
    case 80:
        if (maze[x + 1][y] != '#')
            x++;
        break;
    case 75:
        if (maze[x][y - 1] != '#')
            y--;
        break;
    }
    if (x == finishX && y == finishY)
        gameOver = true;
    if(maze[x][y] == 'B')
    {
        bomb = true;
        gameOver = true;
    }
}
int end()
{
    system("cls");
    char c;
    if(bomb == false)
        cout<<"CONGRATULATIONS!!!! YOU WON !!!\n";
    else
        cout<<"YOU STEPPED ON A BOMB!! GAME OVER!!\n";
    cout<<"Do you want to play again?(Y/N) ";
    c = _getch();
    if(c == 'y' || c== 'Y' )
    {
        setup();
        return 1;
    }
    else 
        return 0;

}
int main()
{
    int i;
    setup();
    while (1)
    {
        draw();
        if (gameOver || bomb)
            i = end();
        else
            logic();
        if( i == 0)
            return 0;
    }
}