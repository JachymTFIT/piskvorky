#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void radek0()
{
  int i;
  printf("-|");
  int cisilko;
    for(i = 0; i<9; i++)
    {
        cisilko = i + 1;
        printf("-%d--", cisilko);
    }
    cisilko++;
    printf("-%d|-", cisilko);
    printf("\n");
}

void radek1()
{
    int i;
    printf(" ");
    for(i = 0; i<10; i++)
    {
        printf("|---");
    }
    printf("|\n");

}

bool bugTest(int i)
{
    int i2 = i + 1;
    int i3 = i + 2;
    if(i == 9 || i == 19 || i == 29 || i == 39 || i == 49 || i == 59 || i == 69 || i == 79 || i == 89)
    {
        return false;
    }

    if(i2 == 9 || i2 == 19 || i2 == 29 || i2 == 39 || i2 == 49 || i2 == 59 || i2 == 69 || i2 == 79 || i2 == 89)
    {
        return false;
    }

    if(i3 == 9 || i3 == 19 || i3 == 29 || i3 == 39 || i3 == 49 || i3 == 59 || i3 == 69 || i3 == 79 || i3 == 89)
    {
        return false;
    }

    else
    {
        return true;
    }
}



int main()
{
    int i;
    int j;
    int drawPolicko = 0;
    int change;
    char hraciPole[100];
    for(i = 0; i<100; i++)
    {
        hraciPole[i] = ' ';
    }
    int won = 0;
    int hrac = 1;
    int Xwon = 0;
    int Owon = 0;
    while(won!=1)

    {

        //zacatek draw
        drawPolicko = 0;
        radek0();
        for(j = 0; j < 10; j++)
        {
            printf("%d|", j);
            for(i = 0; i <10; i++)
            {
                printf(" %c |", hraciPole[drawPolicko]);
                drawPolicko++;
            }
            printf("\n");
            if(j!=9)
            {
                radek1();
            }
        }
        radek0();
        printf("\n");
        //konec draw

        if(hrac % 2 != 0)
        {
            printf("hrac X vybira pole: ");
            scanf("%d", &change);
            change--;
            if(hraciPole[change] == ' ' && change <101 && change >= 0)
            {

                hraciPole[change] = 'X';
                hrac++;
            }
        }
        else{
            printf("hrac O vybira pole: ");
            scanf("%d", &change);
            change--;
            if(hraciPole[change] == ' ' && change < 101 && change >= 0)
            {

                hraciPole[change] = 'O';
                hrac++;
            }

        }
        //win condition start
        for(i = 0; i < 100; i++)
        {
            if(hraciPole[i] == 'X' && hraciPole[i + 10] == 'X' && hraciPole[i + 20] == 'X' && hraciPole[i + 30] == 'X')
            {
                won = 1;
                Xwon = 1;
            }
            if(hraciPole[i] == 'O' && hraciPole[i + 10] == 'O' && hraciPole[i + 20] == 'O' && hraciPole[i + 30] == 'O')
            {
                won = 1;
                Owon = 1;
            }

            if(hraciPole[i] == 'X' && hraciPole[i + 1] == 'X' && hraciPole[i + 2] == 'X' && hraciPole[i + 3] == 'X')
            {
                if(bugTest(i))
                {
                    won = 1;
                    Xwon = 1;
                }
            }
            if(hraciPole[i] == 'O' && hraciPole[i + 1] == 'O' && hraciPole[i + 2] == 'O' && hraciPole[i + 3] == 'O')
            {
                if(bugTest(i))
                {
                    won = 1;
                    Owon = 1;
                }
            }
            if(hraciPole[i] == 'X' && hraciPole[i + 11] == 'X' && hraciPole[i + 22] == 'X' && hraciPole[i + 33] == 'X')
            {
                won = 1;
                Xwon = 1;
            }
            if(hraciPole[i] == 'O' && hraciPole[i + 11] == 'O' && hraciPole[i + 22] == 'O' && hraciPole[i + 33] == 'O')
            {
                won = 1;
                Owon = 1;
            }
            if(hraciPole[i] == 'X' && hraciPole[i - 9] == 'X' && hraciPole[i - 18] == 'X' && hraciPole[i - 27] == 'X')
            {
                won = 1;
                Xwon = 1;
            }
            if(hraciPole[i] == 'O' && hraciPole[i - 9] == 'O' && hraciPole[i - 18] == 'O' && hraciPole[i - 27] == 'O')
            {
                won = 1;
                Owon = 1;
            }
        }
        //win condition end























    }

    //final draw start
    drawPolicko = 0;
        radek0();
        for(j = 0; j < 10; j++)
        {
            printf(" |");
            for(i = 0; i <10; i++)
            {
                printf(" %c |", hraciPole[drawPolicko]);
                drawPolicko++;
            }
            printf("\n");
            if(j!=9)
            {
                radek1();
            }
        }
        radek0();
        printf("\n");
    //final draw end

    if(Xwon == 1)
    {
        printf("X vyhral");
    }
    if(Owon == 1)
    {
        printf("O vyhral");
    }
    getch();











    return 0;
}








