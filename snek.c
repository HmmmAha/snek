#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
int n;



void resetGrid();
void moveSnake();
void apple();
void snakeLogic();
void clearGrid();
void putSnake();

void snakeLogic(int grid[n][n], int n, int move)    //move: 1 = up, 2 = right, 3 = down, 4 = left
{
    
}

void moveSnake(int grid[n][n], int n)
{
    if (kbhit())
    {
        switch (tolower(getch()))
        {
            case 'w':
                snakeLogic(grid, n, 1);
                break;

            case 'd':
                snakeLogic(grid, n, 2);
                break;

            case 's':
                snakeLogic(grid, n, 3);
                break;
            
            case 'a':
                snakeLogic(grid, n, 4);
                break;
        }
    }
}


void resetGrid(int grid[n][n], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            grid[i][j] = 0;
        }
    }
}


void putSnake(int n)
{
    srand(time(0));

    int i = rand() % n;
    int j = rand() % n;
}


void printGrid(int grid[n][n], int n)
{
    putSnake(n);
    while (1)
    {
        moveSnake(grid, n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
        Sleep(500);
        system("cls");
    }
}


int main()
{
    int n = 5;
    int grid[n][n];
    char request;
    do
    {
        resetGrid(grid, n);

        printGrid(grid, n);

    } while (request == 'y' || request == 'Y');
    return 0;
}



