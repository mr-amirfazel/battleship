#ifndef GAME_MAIN_H_INCLUDED
#define GAME_MAIN_H_INCLUDED
#define max 11
int indicator1=1,indicator2=1;
int map_player1[max][max];
    int map_player2[max][max];
struct shoot
{
    int row;
    int col;
};
typedef struct shoot shoot;
shoot* player1_shots;
shoot* player2_shots;
void game();
void player1_turn();
void player2_turn();
//actually remove from linked list 1
void remove_from_map(int row,int col);
//actually remove from linked list 2
void remove_from_map_2(int row,int col);
//actually searches in link list #1
int search_in_map(int row,int col);
//actually searches in link list #2
int search_in_map_2(int row,int col);
void display_game_map(int playground[max][max]);
int end_of_game_condition_check();
int list1_check();
int list2_check();

void map_initializer(int map[max][max]);
void game()
{
    Sleep(3000);
    system("cls");
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
   while(end_of_game_condition_check())
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
                }
            else if(i==0)
            {
                map_2[i][j]=t;
                t++;
            }
            else if(j==0)
            {
                map[i][j]=n;
                n++;
            }
            else
            {
                map[i][j]=79;
            }

       }



   }
}
void player1_turn()
{
    Sleep(3000);
    system("cls");
    printf("\n this is your map at its last situation:\n\n");
    display_game_map(map_player1);
   printf("\n\nenter the coordination of attack starting by 1)row number\t2)column number:\n");
   int row,col;
   scanf("%d%d",&row,&col);
   if(indicator1==1)
   {
      player1_shots=(shoot*)malloc(indicator1*sizeof(shoot));
      player1_shots[indicator1-1].row=row;
      player1_shots[indicator1-1].col=col;
   }
   else
   {
        //to check for valid coordination
            for(int j=0;j<(sizeof(player1_shots)/sizeof(shoot));j++)
        {
                   if((player1_shots[j].row==row)&&(player1_shots[j].col==col))
                   {
                        printf("\nthis coordinate was entered before,please try again:\n");
                        player1_turn();
                   }

        }
         indicator1++;
        player1_shots=(shoot*)realloc(player1_shots,indicator1*sizeof(shoot));
        player1_shots[indicator1-1].row=row;
        player1_shots[indicator1-1].col=col;
   }

   //checking on map and removing from linked list
   if(map_2[row][col]==83)
   {
       remove_from_map_2(row,col);

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

       printf("\n \tyou made one right shot. you get a bonus:\t\n");
       player1_turn();
   }
   else
    {
        printf("\n\t SO Unlucky!!!!!   you only got water!!!!\t\n\n\n");
        map_player1[row][col]=87;
        display_game_map(map_player1);
        Sleep(3000);
        system("cls");
    }

}
void player2_turn()
{

    printf("\n this is your map at its last situation:\n\n");
    display_game_map(map_player2);
    printf("\n\nenter the coordination of attack starting by 1)row number\t2)column number:\n");
   int row,col;
   scanf("%d%d",&row,&col);
   if(indicator2==1)
   {
      player2_shots=(shoot*)malloc(indicator2*sizeof(shoot));
        player2_shots[indicator1-1].row=row;
        player2_shots[indicator1-1].col=col;
   }
   else
   {
               for(int j=0;j<(sizeof(player2_shots)/sizeof(shoot));j++)
           {
               if((player2_shots[j].row==row)&&(player2_shots[j].col==col))
               {
                    printf("this coordinate was entered before,please try again:\n");
                    player2_turn();
               }
           }
            indicator2++;
        player2_shots=(shoot*)realloc(player2_shots,indicator1*sizeof(shoot));
        player2_shots[indicator1-1].row=row;
        player2_shots[indicator1-1].col=col;
   }


   if(map[row][col]==83)
   {
       remove_from_map(row,col);
       if((map[row][col-1]==83)||(map[row][col+1]==83)||(map[row-1][col]==83)||(map[row+1][col]==83))
       {
           map_player2[row][col]=69;
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
        map_player2[row][col]=87;
    }
}
//player 2 decisions come here
//we should terminate a block of linked_list 1
//cause player2 tries to eliminate player1 map which is map
//and also empty the linked  list 1
// be ware that u should use head1
void remove_from_map(int row,int col)
{
   //search in first link list(player1 made list) :|
   int n=search_in_map(row,col);
   ship* temp=head1;
    if (n==1)
    {
    head1=temp->next;
    free(temp);
        return;
    }

    for(int j=0;j<n-2;j++)
    {
        temp=temp->next;
    }
   ship* temp2=temp->next;
    temp->next=temp2->next;
    free(temp2);
}
int search_in_map(int row,int col)
{
    int i=1;
    ship* temp;
    temp=head1;
    while(temp->next!=NULL)
    {
        if((temp->row==row)&&(temp->col==col))
        {
            break;
        }
        else
        {
            i++;
            temp=temp->next;
        }
    }
    return i;
}
//player 1 decisions come here
//we should terminate a block of linked_list 2
//cause player1 tries to eliminate player2 map which is map2
//and also empty the linked  list 2
// be ware that u should use head2
void remove_from_map_2(int row,int col)
{
    //search in second link list(player2 made list) :|
    int n=search_in_map_2(row,col);
    ship* temp=head2;
    if (n==1)
    {
    head2=temp->next;
    free(temp);
        return;
    }

    for(int j=0;j<n-2;j++)
    {
        temp=temp->next;
    }
   ship* temp2=temp->next;
    temp->next=temp2->next;
    free(temp2);
}
//the func to search in link list to and return the number of block
//that was hit so the remove function , can eliminate it
int search_in_map_2(int row,int col)
{
    int i=1;
    ship* temp;
    temp=head2;
    while(temp->next!=NULL)
    {
        if((temp->row==row)&&(temp->col==col))
        {
            break;
        }
        else
        {
            i++;
            temp=temp->next;
        }
    }
    return i;

}
void display_game_map(int playground[max][max])
{
    for(int i=0;i<max;i++)
   {

       for(int j=0;j<max;j++)
       {
            if((i==0)&&j==0)
                {
                  printf("\t");
                }
            else if(i==0)
            {
                printf("%d\t",playground[i][j]);
            }
            else if(j==0)
            {
                printf("%d\t",playground[i][j]);
            }
            else
            {
                printf("%c\t",playground[i][j]);

            }

       }
       printf("\n");


   }
}
int end_of_game_condition_check()
{
    if((list1_check())&&(list2_check()))
        return 1;
    else
        return 0;
}
int list1_check()
{
    ship* temp=head1;
    if(temp!=NULL)
        return 1;
    else
        return 0;
}
int list2_check()
{
    ship* temp=head2;
    if(temp!=NULL)
        return 1;
    else
        return 0;
}
#endif // GAME_MAIN_H_INCLUDED
