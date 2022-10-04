#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
int x, y, fruit_x, fruit_y, score;
const int width = 20;
const int height = 20;
bool gameOver;
enum direction
{
    STOP = 0,
    RIGHT,
    LEFT,
    UP,
    DOWN
} dir;
void createFruit()
{
    fruit_x = 1 + (rand() % (height - 2)); // so that it does not coincides with wall
    fruit_y = 1 + (rand() % (width - 2));
}
void printRules()
{
    system("cls");
    cout << "\t\t----PacMan GAME----\n";
    cout << "\n\n\t\t";
    cout << "F -> Fruit \n\t\tEat fruits to increase score\n\t\t";
    cout << "O -> PacMan \n\t\t";
    cout << "Use Arrow keys to control Snake\n\n\t\t ";
    cout << "press any key to continue....";
    char c = _getch(); // to wait for a key to be pressed
}
void setup()
{
    printRules();
    score = 0;
    dir = STOP;
    gameOver = false;
    x = 1;
    y = 1;
    createFruit();
}
void draw()
{
    system("cls");
    cout << "\n\n\n";
    for (int i = 0; i < height; i++)
    {
        cout << "\t\t";
        for (int j = 0; j < width; j++)
        {
            if (i == x && j == y)
                cout << "O ";
            else if (i == fruit_x && j == fruit_y)
                cout << "F ";
            else if (i == 0 || i == height - 1)
                cout << "# ";
            else if (j == 0 || j == width - 1)
                cout << "# ";
            else
                cout << "  ";
        }
        cout << endl;
    }
    cout << "\n\n";
    cout << "\t\t Score -> " << score;
}
void input()
{
    if (_kbhit()) // to check if a key has been pressed on keyboard
    {
        switch (_getch())
        {
        case 75:
            dir = LEFT;
            break;
        case 77:
            dir = RIGHT;
            break;
        case 80:
            dir = DOWN;
            break;
        case 72:
            dir = UP;
            break;
        }
    }
}
void logic()
{
    switch (dir)
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
    // if snake touches wall , then -> gameover
    if (x == 0 || y == 0 || x == height - 1 || y == width - 1)
        gameOver = true;
    // if snake eats fruit
    if (x == fruit_x && y == fruit_y)
    {
        score += 10;
        createFruit();
    }
}
void end()
{
    system("cls");
    cout << "\n\n\n";
    cout << "\t\tGAME OVER !!!! \n\t\t Your Score -> " << score;
    cout << "\n\t\t Wanna play again ? (y/n)  ";
    char c = _getch();
    // restart game if player press y , end game if player press n
    // if player enters some other key , ask again
    while (c != 'y' && c != 'n' && c != 'N' && c != 'Y')
        c = _getch();
    if (c == 'y' || c == 'Y')
        setup();
}
int main()
{
    setup();
    while (!gameOver)
    {
        draw();
        input();
        logic();
        if (gameOver)
            end();
    }
    return 0;
}
