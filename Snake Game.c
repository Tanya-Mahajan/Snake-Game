#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
  
int i,j,k,e,length = 20, breadth = 20;
int gameover, score;
int x, y, targetx, targety, flag;
int endX[50],endY[50];
char name[20];
int count=0;

int login1(void)
{
  system("cls");
  system("color 6");
  char pass[10],password[10]="18july";
  printf("\n\n\t\t\t\t!!!!  Welcome to Snake Game  !!!!");
  printf("\n\n\n\t\t\tEnter Player Name: ");
  scanf("%s",name);
  printf("\n\t\t\tEnter the PIN Code:");
  scanf("%s", &pass);
  if (strcmp(pass,password)==0)
    {
      printf("\n\nPIN Matched!\nLOADING");
        for(e=0;e<=6;e++)
        {
            fordelay(100000000);
            printf(".");
        }
        system("cls");
      set_target();
    }
  else
    {
      printf("Invalid\n Try Again");
      login1();
    }
  return 0;
}

void fordelay(int j)
{   int e,k;
    for(e=0;e<j;e++)
         k=e;
}

void set_target()
{
    gameover = 0;
  
    x = length / 2;
    y = breadth / 2;
label1:
    targetx = rand() % 20;
    if (targetx == 0)
        goto label1;
label2:
    targety = rand() % 20;
    if (targety == 0)
        goto label2;
    score = 0;
}
  
void draw_boundary()
{
    system("cls");
    for (i = 0; i < length; i++) {
        for (j = 0; j < breadth; j++) {
            if (i == 0 || i == breadth - 1 || j == 0 || j == length - 1) {
                printf("#");
            }
            else {
                if (i == x && j == y)
                    printf("S");
                else if (i == targetx && j == targety)
                    printf("*");
                else
                     { 
                    int ch=0;
                    for(k=0;k<count;k++)
                    {
                        if(i==endX[k] && j==endY[k])
                        {
                            printf("o");
                            ch=1;
                        }
                    }
                    if(ch==0)
                      printf(" ");
                }
                    
            }
        }
        printf("\n");
    }
  
    printf("\n%s score = %d",name,score);
    printf("\n");
    printf("press X to quit the game");
}
  
void input()
{
    if (kbhit()) {
        switch (getch()) {
        case 75:
            flag = 1;
            break;
        case 80:
            flag = 2;
            break;
        case 77:
            flag = 3;
            break;
        case 72:
            flag = 4;
            break;
        case 'x':
            gameover = 1;
            break;
        }
    }
}
  
void logic()
{
	int i;
    int prevx=endX[0];
    int prevy=endY[0];
    int prev2x,prev2y;
    endX[0]=x;
    endY[0]=y;
    
    for(i=1;i<count;i++)
    {
        prev2x=endX[i];
        prev2y=endY[i];
        endX[i]=prevx;
        endY[i]=prevy;
        prevx=prev2x;
        prevy=prev2y;
    }
    switch (flag) {
    case 1:
        y--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y++;
        break;
    case 4:
        x--;
        break;
    default:
        break;
    }
  
    if (x < 0 || x > length || y < 0 || y > breadth)
        gameover = 1;
    for(i=0;i<count;i++)
     {
        if(x==endX[i]  && y==endY[i])
           gameover=1;
     }

    if (x == targetx && y == targety) {
    label3:
        targetx = rand() % 20;
        if (targetx == 0)
            goto label3;
  
    label4:
        targety = rand() % 20;
        if (targety == 0)
            goto label4;
        score += 10;
        count++;
    }
}
  
void main()
{
    int m, n;
    login1();
  
    while (!gameover) {
  
        draw_boundary();
        input();
        logic();
        for(m=0;m<2500;m++){
            for(n=0;n<10000;n++){
             }
        }
        for(m=0;m<1000;m++){
            for(n=0;n<10000;n++){
             }
        }
    }
}

