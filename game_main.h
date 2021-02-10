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
void map_initializer(int playground[max][max]);


// hoosh masnooii part :)
void play_with_adolf();
void ai_begining();
void choose_user();
void user_map();
void collect_info_and_modify_users_map(int users_map[max][max]);
void user_map_set(int state,int row,int col, int len,int playground[max][max]);
void user_insert(int i,int number,int row,int col,int len);
void user_ship_position_check(int state,int row,int col,int len,int playground[max][max]);
ship* user_head;


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

void map_initializer(int playground[max][max])
{
     int n=1,t=1;

   for(int i=0;i<max;i++)
   {

       for(int j=0;j<max;j++)
       {
            if((i==0)&&j==0)
                {
                    playground[i][j]=0;
                }
            else if(i==0)
            {
                playground[i][j]=t;
                t++;
            }
            else if(j==0)
            {
                playground[i][j]=n;
                n++;
            }
            else
            {
                playground[i][j]=79;
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
//hoosh masnooii
//case 2 :|
void play_with_adolf()
{
    user_head=NULL;
    ai_begining();
    choose_user();
    user_map();

}
void ai_begining()
{
     printf("\n\n\tWelcome to single player mode!!!!\t");
    Sleep(2500);
    printf("\n\tIm Adolf and we are gonna be components today!!!\t\n\n");
    Sleep(2500);
    printf("\tMy mission is to terminate as many as USSR ships. whats yours?\t");
    Sleep(2000);
    printf("\n\tyou know... im just kidding its AI humor");
    Sleep(2000);
    printf("\n\tor maybe not humor...");
    Sleep(300);
    system("cls");
    Beep(700,100);
    Sleep(5);
    Beep(900,100);
    Sleep(5);
    Beep(700,100);
    Sleep(5);
    Beep(900,100);
    Sleep(5);
    Beep(700,100);
    Sleep(5);
    Beep(900,100);
    Beep(400,700);
    Sleep(5);
    Beep(900,100);
    Sleep(5);
    Beep(700,100);
    Sleep(5);
    Beep(900,100);
    Sleep(5);
    Beep(700,100);
    Sleep(5);
    Beep(900,100);Beep(700,100);
    Sleep(5);
    Beep(900,100);
    Sleep(5);
    Beep(700,100);
    Sleep(5);
    Beep(900,100);
    Sleep(5);
    Beep(700,100);
    Sleep(5);
    Beep(900,100);Beep(700,100);
    Sleep(5);
    Beep(900,100);
    Sleep(5);
    Beep(700,100);
    Sleep(5);
    Beep(900,100);
    Sleep(5);
    Beep(700,100);
    Sleep(5);
    Beep(900,100);Beep(700,100);
    Sleep(5);
    Beep(900,100);
    Sleep(5);
    Beep(700,100);
    Sleep(5);
    Beep(900,100);
    Sleep(5);
    Beep(700,100);
    Sleep(5);
    Beep(900,100);
    printf("\n\n HEAR that soldier...we are currently at war . good luck\n");
}
void choose_user()
{
     printf("\nplayer:\n\t1.choose user\n");
    printf("\t1.choose from available users\n2.new users");
    int user_dec;
    scanf("%d",&user_dec);
     switch(user_dec)
    {
    case 1:
        show_user();
        break;
    case 2:
        add_user();
        break;
    }
}
void user_map()
{
    int user_vs_bot_map[max][max];
    map_initializer(user_vs_bot_map);
    printf("this is your raw map:\n\n");
    display_game_map(user_vs_bot_map);
    collect_info_and_modify_users_map(user_vs_bot_map);

}
void collect_info_and_modify_users_map(int users_map[max][max])
{
    int users_ship_number=1;

    //first ship 5x1
    printf("enter info for ship with length of 5x1\n\n");
    printf("1)Horizontal\n2)Vertical ::\n");
    int state;
    int row,col,len;
    len=5;
    scanf("%d",&state);
    scanf("%d",&row);
    scanf("%d",&col);
    user_map_set(state,row,col,len,users_map);
    for(int i=1;i<=len;i++)
    {
        user_insert(i,users_ship_number,len,row,col);
        if(state==1)
            col++;
        else
            row++;
    }
    users_ship_number++;
    //2nd ship: 3x1
    printf("enter info for ship with length of 3x1:\n\n");
    printf("1)Horizontal\n2)Vertical ::\n");
    scanf("%d%d%d",&state,&row,&col);
    len=3;
    if(user_ship_position_check(state,row,col,len,users_map)==0)
    {
       printf("You disobeyed the laws. start over");
       collect_info_and_modify_users_map(users_map);
    }
    user_map_set(state,row,col,len,users_map);

    for(int i=1;i<=len;i++)
    {
        user_insert(i,users_ship_number,len,row,col);
        if(state==1)
            col++;
        else
            row++;
    }
    users_ship_number++;
    //3rd ship: 3x1
    printf("enter info for ship with length of 3x1:\n\n");
    printf("1)Horizontal\n2)Vertical ::\n");
    scanf("%d%d%d",&state,&row,&col);
    len=3;
    if(user_ship_position_check(state,row,col,len,users_map)==0)
    {
       printf("You disobeyed the laws. start over");
         collect_info_and_modify_users_map(users_map);
    }
   user_map_set(state,row,col,len,users_map);

    for(int i=1;i<=len;i++)
    {
        user_insert(i, users_ship_number,len,row,col);
        if(state==1)
            col++;
        else
            row++;
    }
     users_ship_number++;
    //4th ship: 2x1
    printf("enter info for ship with length of 2x1:\n\n");
    printf("1)Horizontal\n2)Vertical ::\n");
    scanf("%d%d%d",&state,&row,&col);
    len=2;
    if(user_ship_position_check(state,row,col,len,users_map)==0)
    {
       printf("You disobeyed the laws. start over");
         collect_info_and_modify_users_map(users_map);
    }
   user_map_set(state,row,col,len,users_map);

    for(int i=1;i<=len;i++)
    {
       user_insert(i, users_ship_number,len,row,col);
        if(state==1)
            col++;
        else
            row++;
    }
     users_ship_number++;
    //5th ship: 2x1
    printf("enter info for ship with length of 2x1:\n\n");
    printf("1)Horizontal\n2)Vertical ::\n");
    scanf("%d%d%d",&state,&row,&col);
    len=2;
    if(user_ship_position_check(state,row,col,len,users_map)==0)
    {
       printf("You disobeyed the laws. start over");
        collect_info_and_modify_users_map(users_map);
    }
    user_map_set(state,row,col,len,users_map);

    for(int i=1;i<=len;i++)
    {
        user_insert(i, users_ship_number,len,row,col);
        if(state==1)
            col++;
        else
            row++;
    }
    users_ship_number++;
    //6th ship: 2x1
    printf("enter info for ship with length of 2x1:\n\n");
    printf("1)Horizontal\n2)Vertical ::\n");
    scanf("%d%d%d",&state,&row,&col);
    len=2;
    if(user_ship_position_check(state,row,col,len,users_map)==0)
    {
       printf("You disobeyed the laws. start over");
         collect_info_and_modify_users_map(users_map);
    }
    user_map_set(state,row,col,len,users_map);

    for(int i=1;i<=len;i++)
    {
        user_insert(i, users_ship_number,len,row,col);
        if(state==1)
            col++;
        else
            row++;
    }
     users_ship_number++;
   //7th ship: 2x1
    printf("enter info for ship with length of 4x1:\n\n");
    printf("1)Horizontal\n2)Vertical ::\n");
    scanf("%d%d%d",&state,&row,&col);
    len=1;
     if(user_ship_position_check(state,row,col,len,users_map)==0)
    {
       printf("You disobeyed the laws. start over");
         collect_info_and_modify_users_map(users_map);
    }
    user_map_set(state,row,col,len,users_map);

    for(int i=1;i<=len;i++)
    {
        user_insert(i, users_ship_number,len,row,col);
        if(state==1)
            col++;
        else
            row++;
    }
     users_ship_number++;
    //8th ship: 2x1
    printf("enter info for ship with length of 4x1:\n\n");
    printf("1)Horizontal\n2)Vertical ::\n");
    scanf("%d%d%d",&state,&row,&col);
    len=1;
     if(user_ship_position_check(state,row,col,len,users_map)==0)
    {
       printf("You disobeyed the laws. start over");
         collect_info_and_modify_users_map(users_map);
    }
   user_map_set(state,row,col,len,users_map);

    for(int i=1;i<=len;i++)
    {
        user_insert(i,users_ship_number,len,row,col);
        if(state==1)
            col++;
        else
            row++;
    }
     users_ship_number++;
    //9th ship: 2x1
    printf("enter info for ship with length of 4x1:\n\n");
    printf("1)Horizontal\n2)Vertical ::\n");
    scanf("%d%d%d",&state,&row,&col);
    len=1;
     if(user_ship_position_check(state,row,col,len,users_map)==0)
    {
       printf("You disobeyed the laws. start over");
         collect_info_and_modify_users_map(users_map);
    }
    user_map_set(state,row,col,len,users_map);

    for(int i=1;i<=len;i++)
    {
        user_insert(i,users_ship_number,len,row,col);
        if(state==1)
            col++;
        else
            row++;
    }
     users_ship_number++;
    //10th ship: 2x1
    printf("enter info for ship with length of 4x1:\n\n");
    printf("1)Horizontal\n2)Vertical ::\n");
    scanf("%d%d%d",&state,&row,&col);
    len=1;
    if(user_ship_position_check(state,row,col,len,users_map)==0)
    {
       printf("You disobeyed the laws. start over");
       collect_info_and_modify_users_map(users_map);
    }
    user_map_set(state,row,col,len,users_map);

    for(int i=1;i<=len;i++)
    {
        user_insert(i, users_ship_number,len,row,col);
        if(state==1)
            col++;
        else
            row++;
    }
    //ship2_num++;
}

void user_map_set(int state,int row,int col, int len,int playground[max][max])
{
    //for that state is horizental
    if(state==1)
    {
        if((col+len)<=max)
        {
            for(int i=col;i<len+col;i++)
            {
                playground[row][i]=83;

            }
            display_game_map(playground);
        }
        else
        {
             printf("CANT FIT SHIP IN MAP!!!!!!! \a");
             collect_info_and_modify_users_map(playground)
        }


    }
    //for that state is vertical
    else if(state==2)
    {
        if((row+len)<=max)
        {
            for(int i=row;i<len+row;i++)
            {
                playground[i][col]=83;
            }
            display_game_map(playground);
        }
          else
        {
             printf("CANT FIT SHIP IN MAP!!!!!!! \a");
           collect_info_and_modify_users_map(playground);
        }
    }
}
void user_insert(int i,int number,int row,int col,int len)
{
    ship* temp=(ship *)malloc(sizeof(struct ship));
     ship* temp2=(ship *)malloc(sizeof(struct ship));

   temp->index=i;
    temp->indicator=num;
    temp->len=len;
    temp->row=row;
    temp->col=col;
    temp->next=NULL;

    if(user_head==NULL)
    {
        user_head=temp;
    }

    else
    {
        temp2=user_head;
        while(temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        temp2->next=temp;

    }
}
void user_ship_position_check(int state,int row,int col,int len,int playground[max][max])
{
    if(state==1)
    {
        if(len==3)
        {
            if((playground[row-1][col]==83)||(playground[row+1][col]==83)||(playground[row][col-1]==83)||(playground[row-1][col+1]==83)||(playground[row+1][col+1]==83)||(playground[row][col+3]==83)||(playground[row-1][col+2]==83)||(playground[row+1][col+2]==83))
            return 0;
        }
        if(len==2)
        {
            if((playground[row][col-1]==83)||(playground[row-1][col]==83)||(playground[row+1][col]==83)||(playground[row][col+2]==83)||(playground[row-1][col+1]==83)||(playground[row+1][col+1]==83))
                return 0;
        }
        if(len==1)
        {
            if((playground[row][col+1]==83)||(playground[row][col-1]==83)||(playground[row-1][col]==83)||(playground[row+1][col]==83))
                return 0;
        }
        return 1;
    }
    else if(state==2)
    {
        if(len==3)
        {
            if((playground[row-1][col]==83)||(playground[row][col-1]==83)||(playground[row][col+1]==83)||(playground[row+1][col-1]==83)||(playground[row+1][col+1]==83)||(playground[row+2][col-1]==83)||(playground[row+2][col+1]==83)||(playground[row+3][col]==83))
                return 0;
        }
        if(len==2)
        {
            if((playground[row-1][col]==83)||(playground[row][col-1]==83)||(playground[row][col+1]==83)||(playground[row+1][col-1]==83)||(playground[row+1][col+1]==83)||(playground[row+2][col]==83))
                return 0;
        }
        if(len==1)
        {
             if((playground[row][col+1]==83)||(playground[row][col-1]==83)||(playground[row-1][col]==83)||(playground[row+1][col]==83))
                return 0;
        }
        return 1;

    }
}
#endif // GAME_MAIN_H_INCLUDED
