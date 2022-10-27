#include <iostream>
#include <conio.h>
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
#define height 15
#define width 15
int x, y, fruit_x, fruit_y, score;
int tailX[100], tailY[100], tailLength;
bool gameOver;
enum dir
{
    LEFT,
    RIGHT,
    UP,
    DOWN
} direction;
void createFruit()
{
    fruit_x = (rand() % (height - 4)) + 2;
    fruit_y = (rand() % (width - 4)) + 2;
}
void draw()
{
    system("cls");
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || j == 0 || j == width - 1 || i == height - 1)
                cout << "# ";
            else if (i == x && j == y)
                cout << "O ";
            else if (i == fruit_x && j == fruit_y)
                cout << "F ";
            else
            {
                bool printed = false;
                for (int p = 0; p < tailLength; p++)
                {
                    if (i == tailX[p] && j == tailY[p])
                    {
                        cout << "o ";
                        printed = true;
                        break;
                    }
                }
                if (!printed)
                    cout << "  ";
            }
        }
        cout << "\n";
    }
    cout << "\n\tSCORE -> " << score;
}
void logic()
{
    int prevX = x, prevY = y;
    for (int i = 0; i < tailLength; i++)
    {
        int tx = tailX[i], ty = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = tx;
        prevY = ty;
    }
    switch (direction)
    {
    case LEFT:
        y--;
        break;
    case RIGHT:
        y++;
        break;
    case UP:
        x--;
        break;
    case DOWN:
        x++;
        break;
    }
    for (int i = 0; i < tailLength; i++)
        if (x == tailX[i] && y == tailY[i])
            gameOver = true;
    if (x == fruit_x && y == fruit_y)
    {
        score += 10;
        tailLength++;
        createFruit();
    }
    if (x == height-1) x = 1; else if (x == 0) x = height - 2;
    if (y == 0) y = width - 2; else if (y == width-1) y = 1;
    // if (x <= 0 || x >= (height - 1) || y <= 0 || y >= (width - 1))
    //     gameOver = true;
}
void input()
{
    if (_kbhit())
    {
        char c = getch();
        switch (c)
        {
        case 72:
            direction = UP;
            break;
        case 80:
            direction = DOWN;
            break;
        case 75:
            direction = LEFT;
            break;
        case 77:
            direction = RIGHT;
            break;
        }
    }
}
void setup()
{
    // make sure there is no tail at beginning of game
    for (int i = 0; i < 100; i++)
    {
        tailX[i] = -1;
        tailY[i] = -1;
    }
    tailLength = 0;
    score = 0;
    gameOver = false;
    x = height / 2;
    y = width / 3;
    direction = RIGHT;
    createFruit();
}
void end()
{
    system("cls");
    cout << "\n\n\t GAME OVER ";
    cout << "\n\n\t YOUR SCORE -> " << score;
    cout << "\n\n\t Press y to play again or n to exit ";
    char c = getch();
    if (c == 'y' || c == 'Y')
    {
        gameOver = false;
        setup();
    }
    else if (c != 'n' && c != 'N')
        end();
}
int main()
{
    setup();
    while (!gameOver)
    {
        draw();
        Sleep(99);
        input();
        logic();
        if (gameOver)
            end();
    }
    return 0;
}