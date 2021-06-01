#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

char ar[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char s1[20];
char s2[20];

void display()
{
    int i, j;
    for (i = 0; i < 3; i++)

    {
        printf("------------\n");
        for (j = 0; j < 3; j++)
        {
            printf(" %c |", ar[i][j]);
        }
        printf("\n");
    }
    printf("------------\n");
}

int check()
{
    int i, ar0[8] = {0}, arx[8] = {0};
    for (i = 0; i < 3; i++)
    {
        if (ar[0][i] == '0') // first row == 0
        {
            ar0[0]++;
        }
        if (ar[1][i] == '0') // second row == 0
        {
            ar0[1]++;
        }
        if (ar[2][i] == '0') // third row == 0
        {
            ar0[2]++;
        }

        if (ar[i][0] == '0') // first column == 0
        {
            ar0[3]++;
        }
        if (ar[i][1] == '0') // Second coiumn == 0
        {
            ar0[4]++;
        }
        if (ar[i][2] == '0') // third column == 0
        {
            ar0[5]++;
        }

        if (ar[i][i] == '0') // Primary Diagonal == 0
        {
            ar0[6]++;
        }

        if (ar[i][2 - i] == '0') // Secondary Diagonal == 0
        {
            ar0[7]++;
        }
    }
    for (i = 0; i < 3; i++)
    {
        if (ar[0][i] == 'x') // first row == x
        {
            arx[0]++;
        }
        if (ar[1][i] == 'x') // second row == x
        {
            arx[1]++;
        }
        if (ar[2][i] == 'x') // third row == x
        {
            arx[2]++;
        }

        if (ar[i][0] == 'x') // first column == x
        {
            arx[3]++;
        }
        if (ar[i][1] == 'x') // Second coiumn == x
        {
            arx[4]++;
        }
        if (ar[i][2] == 'x') // third column == x
        {
            arx[5]++;
        }

        if (ar[i][i] == 'x') // Primary Diagonal == x
        {
            arx[6]++;
        }

        if (ar[i][2 - i] == 'x') // Secondary Diagonal == x
        {
            arx[7]++;
        }
    }
    for (i = 0; i < 8; i++)
    {
        if (ar0[i] == 3)
        {
            return 10;
        }
    }
    for (i = 0; i < 8; i++)
    {
        if (arx[i] == 3)
        {
            return 20;
        }
    }
    return 30;
}

void instruction()
{
    printf("*********************** INSTRUCTION ***********************\n ");
    printf("\n");
    printf("Symbol for %s :: 0 \n", s1);
    printf("\n");
    printf("Symbol for %s :: x \n", s2);
    printf("\n");
}

void inputname()
{
    printf("\n");
    printf("Enter Player 1 Name = ");
    scanf("%s", &s1);
    printf("\n");
    printf("Enter Player 2 Name = ");
    scanf("%s", &s2);
    printf("\n");
}

int main()
{
    system("cls");
    inputname();
    int flag = 1;
    int pos, wn, draw = 0;
    char ch;
    while (1)
    {
        system("cls");
        printf("\n");
        instruction();
        printf("\n");
        printf("---------Tic Tac Toe---------\n");
        printf("\n");
        display();
        printf("\n");
        if (flag == 1)
        {
            printf("Enter the number b/w (1 to 9) for %s: ", s1);
        }
        else
        {
            printf("Enter the number b/w (1 to 9) for %s: ", s2);
        }
        scanf("%d", &pos);
        if (pos >= 1 && pos <= 9)
        {
            if (flag == 1) // for continuosly putting 0 and x

            {
                ch = '0';
                flag = 0;
            }
            else
            {
                ch = 'x';
                flag = 1;
            }
            if (pos >= 1 && pos <= 3)
            {
                if (ar[0][pos - 1] != '0' && ar[0][pos - 1] != 'x')
                {
                    ar[0][pos - 1] = ch;
                    draw++;
                }
                else
                {
                    printf("\nThis number is already here!! Choose anothe One: ");
                    if (ch == 'x')
                    {
                        flag = 0;
                    }
                    else
                    {
                        flag = 1;
                    }
                    getch();
                }
            }
            else if (pos >= 4 && pos <= 6)
            {
                if (ar[1][pos - 4] != '0' && ar[1][pos - 4] != 'x')
                {
                    ar[1][pos - 4] = ch;
                    draw++;
                }
                else
                {
                    printf("\nThis charcter is already here!! Choose anothe One: ");
                    if (ch == 'x')
                    {
                        flag = 0;
                    }
                    else
                    {
                        flag = 1;
                    }
                    getch();
                }
            }
            else if (pos >= 7 && pos <= 9)
            {
                if (ar[2][pos - 7] != '0' && ar[2][pos - 7] != 'x')
                {
                    ar[2][pos - 7] = ch;
                    draw++;
                }
                else
                {
                    printf("\nThis charcter is already here!! Choose anothe One: ");
                    if (ch == 'x')
                    {
                        flag = 0;
                    }
                    else
                    {
                        flag = 1;
                    }
                    getch();
                }
            }
            wn = check();
            if (wn == 10)
            {
                system("cls");
                display();
                printf("\nCongratulation, %s You Won The Game.\n ", s1);
                printf("\nSorry %s, Better Luck Next Time.\n", s2);
                printf("\n");
                getch();
            }

            if (wn == 20)
            {
                system("cls");
                display();
                printf("\nCongratulation, %s You Won The Game.\n", s2);
                printf("\nSorry %s, Better Luck Next Time.\n", s1);
                printf("\n");
                getch();
            }
            if (draw == 9 && wn == 30)
            {
                system("cls");
                display();
                printf("\nGame Draw\n");
                printf("\n");
                getch();
            }

            if (wn == 10 || wn == 20 || (wn == 30 && draw == 9))
            {
                printf("Do you want to play again ?\n Press y for YES\n Press n for NO\n");
                printf("\n");

                char ag;
                fflush(stdin);
                scanf("%c", &ag);
                if (ag == 'Y' || ag == 'y')
                {
                    flag = 1;
                    draw = 0;

                    int i;

                    for (i = 0; i < 3; i++)
                    {
                        ar[0][i] = i + 49;
                        ar[1][i] = i + 52;
                        ar[2][i] = i + 55;
                    }

                    printf("You Choose Yes\n");
                    printf("Press any key to continue...");
                    getch();
                    system("cls");
                    inputname();
                }
                else
                {
                    printf("-------Thanks For Playing-------\n");
                    getch();
                    break;
                }
            }
        }

        else
        {
            printf("Invaid Position: Enter a number b/w (1 to 9) \n");
            getch();
        }
    }

    getch();
    return 0;
}
