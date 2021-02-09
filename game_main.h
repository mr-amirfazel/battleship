#ifndef GAME_MAIN_H_INCLUDED
#define GAME_MAIN_H_INCLUDED
#define max 11
int map_player1[max][max];
    int map_player2[max][max];
struct shoot
{
    int row;
    int col;
};
typedef struct shoot shoot;
int indicator1=1;
    shoot* player1_shots=(shoot*)malloc(indicator1*sizeof(shoot));
int indicator2=1;
    shoot* player2_shots=(shoot*)malloc(indicator2*sizeof(shoot));
void game();
void player1_turn();
void player2_turn();
void map_initializer(int map[max][max]);
void game()
{
    //player1 has the map of map_player1
    //player one plays on map_player1 but he tries to eliminate the map2
    //so every decision on map_player1 should be checked on map2
    //map_player1 ==== map2 but hidden


    //player2 has the map of map_player2
    //player two plays on map_player2 but he tries to eliminate the map1
    //so every decision on map_player2 should be checked on map1
    //map_player2 ==== map1 but hidden


    map_initializer(map_player1);
    map_initializer(map_player2);
    printf("\nwe are currently in game with 2 available users.\n");
   while(true)
    {
        printf("player1 turn:\n");
        player1_turn();
        printf("player2 turn:\n");
        player2_turn();

    }


}

void map_initializer(int map[max][max])
{
     int n=1,t=1;

   for(int i=0;i<max;i++)
   {

       for(int j=0;j<max;j++)
       {
            if((i==0)&&j==0)
                {
                    map[i][j]=0;
                  printf("\t");
                }
            else if(i==0)
            {
                map_2[i][j]=t;
                t++;
                printf("%d\t",map[i][j]);
            }
            else if(j==0)
            {
                map[i][j]=n;
                n++;
                printf("%d\t",map[i][j]);
            }
            else
            {
                map[i][j]=79;
                printf("%c\t",map[i][j]);

            }

       }
       printf("\n");


   }
}
void player1_turn()
{

   printf("enter the coordination of attack starting by 1)row number\t2)column number:\n");
   int row,col;
   scanf("%d%d",&row,&col);
   if(indicator1>1)
   {
       player1_shots=(shoot*)realloc(player1_shots,indicator1*sizeof(shoot));
   }
   for(int j=0;j<(sizeof(player1_shots)/sizeof(shoot);j++))
   {
       if((player1_shots[j].row==row)&&(player1_shots[j].col==col))
       {
            printf("this coordinate was entered before,please try again:\n");
            player1_turn();
       }

   }
   if(map_2[row][col]==83)
   {
       indicator1++;
       if((map_2[row][col-1]==83)||(map_2[row][col+1]==83)||(map_2[row-1][col]==83)||(map_2[row+1][col]==83))
       {
           map_player1[row][col]=69;
       }
       else
       {
           if((map_2[row][col-1]==87)&&(map_2[row][col+1]==87)&&(map_2[row-1][col]==87)&&(map_2[row+1][col]==87))
           {
               map_player1[row][col]=67;
               map_player1[row][col-1]=87;
               map_player1[row][col+1]=87;
               map_player1[row-1][col]=87;
               map_player1[row+1][col]=87;
           }
       }
       printf("\n you made one right shot. you get a bonus:\n");
       player1_turn();
   }
   else
    {
        indicator1++;
        map_player1[row][col]=87;
    }
}
void player2_turn()
{
    printf("enter the coordination of attack starting by 1)row number\t2)column number:\n");
   int row,col;
   scanf("%d%d",&row,&col);
   if(indicator2>1)
   {
       player2_shots=(shoot*)realloc(player2_shots,indicator2*sizeof(shoot));
   }
   for(int j=0;j<(sizeof(player2_shots)/sizeof(shoot);j++))
   {
       if((player2_shots[j].row==row)&&(player2_shots[j].col==col))
       {
            printf("this coordinate was entered before,please try again:\n");
            player2_turn();
       }

   }
   if(map[row][col]==83)
   {
       indicator2++;
       if((map[row][col-1]==83)||(map[row][col+1]==83)||(map[row-1][col]==83)||(map[row+1][col]==83))
       {
           map_player1[row][col]=69;
       }
       else
       {
           if((map[row][col-1]==87)&&(map[row][col+1]==87)&&(map[row-1][col]==87)&&(map[row+1][col]==87))
           {
               map_player2[row][col]=67;
               map_player2[row][col-1]=87;
               map_player2[row][col+1]=87;
               map_player2[row-1][col]=87;
               map_player2[row+1][col]=87;
           }
       }
       printf("\n you made one right shot. you get a bonus:\n");
       player2_turn();
   }
   else
    {
        indicator2++;
        map_player2[row][col]=87;
    }
}
#endif // GAME_MAIN_H_INCLUDED
