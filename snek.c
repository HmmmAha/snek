#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
int tile[15][15] = {0};
int moveUpdate = 0;
int score = 1;

int snake_i, snake_j;
int apple_i, apple_j;


void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


int snakeLogic(int n)    //move: 1 = up, 2 = right, 3 = down, 4 = left
{
    switch (moveUpdate)
    {
        case 1: // Move up
            snake_i--;
            break;
        case 2: // Move right
            snake_j++;
            break;
        case 3: // Move down
            snake_i++;
            break;
        case 4: // Move left
            snake_j--;
            break;
    }

    if (tile[snake_i][snake_j] > 0)
        return -1;

    tile[snake_i][snake_j] = score;


    if (snake_i == apple_i && snake_j == apple_j)
    {
        ++score;
        return 1;
    }


    if (snake_i == 0 || snake_i == n-1 || snake_j == 0 || snake_j == n-1)
        return -1;
    
    return 0;
}


void moveSnake(int n)
{
    if (kbhit())
    {
        switch (tolower(getch()))
        {
            case 'w':
                if (moveUpdate == 3)
                    break;
                moveUpdate = 1;
                break;

            case 'd':
                if (moveUpdate == 4)
                    break;
                moveUpdate = 2; 
                break;

            case 's':
                if (moveUpdate == 1)
                    break;
                moveUpdate = 3;
                break;
            
            case 'a':
                if (moveUpdate == 2)
                    break;
                moveUpdate = 4;
                break;
        }
    }
}


void resetGrid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tile[i][j] = 0;
        }
    }
}


void putSnake(int n)
{
    int i, j;
    do
    {
        i = (rand() % (n-2));
        j = (rand() % (n-2));
    } while (i == 1 || i == n-2 || i == 0 || i == n-1 || j == 1 || j == n-2 || j == 0 || j == n-1);     //snake cannot be on any extremities of grid

    tile[i][j] = 1;

    snake_i = i;
    snake_j = j;
}


void printGrid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Frame/border
            if (i == 0 || i == n-1)
            {
                if (j == n-1)
                {
                    printf("-", tile[i][j]);
                    continue;
                }
                printf("--", tile[i][j]);
                continue;
            }
            else if (j == 0 || j == n-1)
            {
                printf("| ", tile[i][j]);
                continue;
            }

            // UI
            if (tile[i][j] == -1)
            {
                setColor(4);
                printf("* ");
            }
            else if (i == snake_i && j == snake_j)
            {
                setColor(2);
                switch (moveUpdate)
                {
                    case 0:
                        printf("O ");
                        break;
                    case 1:
                        printf("^ ");
                        break;

                    case 2:
                        printf("> ");
                        break;

                    case 3:
                        printf("v ");
                        break;

                    case 4:
                        printf("< ");
                        break;
                }
            }
            else if (tile[i][j] < score && tile[i][j] > 0)
            {
                setColor(2);
                printf("o ");
            }
            else if (tile[i][j] == 0)
            {
                setColor(7);
                printf("  ");
            }

            setColor(7);    //Reset color

            if (tile[i][j] > 0)
                --tile[i][j];       //Mimick snake's tail
        }
        printf("\n");
    }
}


void apple(int n)
{
    int i, j;
    do
    {
        i = (rand() % (n-2));
        j = (rand() % (n-2));
    } while (i == 0 || i == n-1 || j == 0 || j == n-1 || tile[i][j]);     //apple can be on grid's edges

    tile[i][j] = -1;

    apple_i = i;
    apple_j = j;
}


void gridLogic(int n)
{
    system("cls");
    moveUpdate = 0;
    score = 1;
    putSnake(n);
    apple(n);
    printGrid(n);
    printf("Press (w/a/s/d) to start.\n");
    while (moveUpdate == 0)
    {
        moveSnake(n);
    }
    system("cls");
    while (1)
    {
        moveSnake(n);
        if (snake_i == apple_i && snake_j == apple_j)
            apple(n);

        int ret = snakeLogic(n);

        if (ret == 1)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (tile[i][j] > 0)
                        tile[i][j]++;
                }
            }
        }
        else if (ret == -1)
        {
            break;
        }
        
        

        printGrid(n);
        printf("Score: %d\n", score-1);
        Sleep(200);
        system("cls");
    }

    printf("You died!\n");
}

int main()
{
    srand(time(0));

    int n = 15;

    printf("this is just a test\n");
    
    char request;
    do
    {
        resetGrid(n);

        gridLogic(n);

        printf("Do you want to play again? (y/n)\n");

        request = getch();
        if (tolower(request) == 'n')
            break;
    } while (tolower(request) == 'y');
    return 0;
}
