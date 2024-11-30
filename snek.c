#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>

int grid[5][5] = {0};
void moveSnake();
void apple();
void snakeLogic();
void clearGrid();
void putSnake();


void putSnake()
{
    int MIN = 1;
    int MAX = 24;

    // srand()


}


void printGrid()
{
    while (1)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
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
    printGrid();
    return 0;
}



