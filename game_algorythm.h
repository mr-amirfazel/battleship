#ifndef GAME_ALGORYTHM_H_INCLUDED
#define GAME_ALGORYTHM_H_INCLUDED
#define max 11
int ship_num=1;
 int map[max][max];
struct ship{
    int len;
    int index;
    int indicator;
    int row;
    int col;
    struct ship* next;

};
typedef struct ship ship;
ship* head1;
ship* head2;
ship* head3;
ship* head4;
ship* head5;
ship* head6;
ship* head7;
ship* head8;
ship* head9;
ship* head10;
void show_initial_map();
void game_inst();
void collector();
void show_map();
void map_set(int state,int row,int col,int len);
void link_maker(int state,int row,int col,int len);
void Insert1(int i,int number,int len,int row,int col);
void Insert2(int i,int number,int len,int row,int col);
void Insert3(int i,int number,int len,int row,int col);
void Insert4(int i,int number,int len,int row,int col);
void Insert5(int i,int number,int len,int row,int col);
void Insert6(int i,int number,int len,int row,int col);
void Insert7(int i,int number,int len,int row,int col);
void Insert8(int i,int number,int len,int row,int col);
void Insert9(int i,int number,int len,int row,int col);
void Insert10(int i,int number,int len,int row,int col);
int ships_position_condition_check();
int search_ship(int row,int col);
void ship_set()
{
    head1=NULL;
    head2=NULL;
    head3=NULL;
    head4=NULL;
    head5=NULL;
    head6=NULL;
    head7=NULL;
    head8=NULL;
    head9=NULL;
    head10=NULL;
     printf("This is your main map:\n\n");
     show_initial_map();
     game_inst();
     collector();


}


void show_initial_map()
{

   int n=1,t=1;

   for(int i=0;i<max;i++)
   {

       for(int j=0;j<max;j++)
       {
            if((i==0)&&j==0)
                {map[i][j]=0;
                  printf("\t");
                }
            else if(i==0)
            {
                map[i][j]=t;
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
                map[i][j]=87;
                printf("%c\t",map[i][j]);

            }

       }
       printf("\n");


   }
}
void game_inst()
{
    printf("you have 1 ship of size 5, 2 ships of size 3,3 ships of size 2, and 4 ships of size 1");
    printf("\n you are also able to put your ships in vertical or horizental order only");
    printf("\n there should be at least 1 block distance between 2 blocks");
    printf("\n what you enter should have this format :");
    printf("\n the state(V or H)\tnumber of row\tnumber of column:\n");
}
void collector()
{
    //first ship 5x1
    printf("enter info for ship with length of 5x1\n\n");
    printf("1)Horizontal\n2)Vertical ::\n");
    int state;
    int row,col,len;
    len=5;
    scanf("%d",&state);
    scanf("%d",&row);
    scanf("%d",&col);
    map_set(state,row,col,len);
    for(int i=1;i<=len;i++)
    {
        Insert1(i,ship_num,len,row,col);
        if(state==1)
            col++;
        else
            row++;
    }
    if(ships_position_condition_check()==0)
    {
       printf("You disobeyed the laws. start over");
       ship_set();
    }

    ship_num++;
    //2nd ship: 3x1
    printf("enter info for ship with length of 3x1:\n\n");
    printf("1)Horizontal\n2)Vertical ::\n");
    scanf("%d%d%d",&state,&row,&col);
    len=3;
    map_set(state,row,col,len);
    for(int i=1;i<=len;i++)
    {
       Insert2(i,ship_num,len,row,col);
        if(state==1)
            col++;
        else
            row++;
    }
    if(ships_position_condition_check()==0)
    {
       printf("You disobeyed the laws. start over");
       ship_set();
    }
    ship_num++;
    //3rd ship: 3x1
    printf("enter info for ship with length of 3x1:\n\n");
    printf("1)Horizontal\n2)Vertical ::\n");
    scanf("%d%d%d",&state,&row,&col);
    len=3;
    map_set(state,row,col,len);
     for(int i=1;i<=len;i++)
    {
        Insert3(i,ship_num,len,row,col);
        if(state==1)
            col++;
        else
            row++;
    }
    if(ships_position_condition_check()==0)
    {
       printf("You disobeyed the laws. start over");
       ship_set();
    }
    ship_num++;
    //4th ship: 2x1
    printf("enter info for ship with length of 2x1:\n\n");
    printf("1)Horizontal\n2)Vertical ::\n");
    scanf("%d%d%d",&state,&row,&col);
    len=2;
    map_set(state,row,col,len);
     for(int i=1;i<=len;i++)
    {
       Insert4(i,ship_num,len,row,col);
        if(state==1)
            col++;
        else
            row++;
    }
    if(ships_position_condition_check()==0)
    {
       printf("You disobeyed the laws. start over");
       ship_set();
    }
    ship_num++;
    //5th ship: 2x1
    printf("enter info for ship with length of 2x1:\n\n");
    printf("1)Horizontal\n2)Vertical ::\n");
    scanf("%d%d%d",&state,&row,&col);
    len=2;
    map_set(state,row,col,len);
     for(int i=1;i<=len;i++)
    {
       Insert5(i,ship_num,len,row,col);
        if(state==1)
            col++;
        else
            row++;
    }
    if(ships_position_condition_check()==0)
    {
       printf("You disobeyed the laws. start over");
       ship_set();
    }
    ship_num++;
    //6th ship: 2x1
    printf("enter info for ship with length of 2x1:\n\n");
    printf("1)Horizontal\n2)Vertical ::\n");
    scanf("%d%d%d",&state,&row,&col);
    len=2;
    map_set(state,row,col,len);
     for(int i=1;i<=len;i++)
    {
        Insert6(i,ship_num,len,row,col);
        if(state==1)
            col++;
        else
            row++;
    }
    if(ships_position_condition_check()==0)
    {
       printf("You disobeyed the laws. start over");
       ship_set();
    }
    ship_num++;
   //7th ship: 2x1
    printf("enter info for ship with length of 4x1:\n\n");
    printf("1)Horizontal\n2)Vertical ::\n");
    scanf("%d%d%d",&state,&row,&col);
    len=1;
    map_set(state,row,col,len);
     for(int i=1;i<=len;i++)
    {
        Insert7(i,ship_num,len,row,col);
        if(state==1)
            col++;
        else
            row++;
    }
    if(ships_position_condition_check()==0)
    {
       printf("You disobeyed the laws. start over");
       ship_set();
    }
    ship_num++;
    //8th ship: 2x1
    printf("enter info for ship with length of 4x1:\n\n");
    printf("1)Horizontal\n2)Vertical ::\n");
    scanf("%d%d%d",&state,&row,&col);
    len=1;
    map_set(state,row,col,len);
     for(int i=1;i<=len;i++)
    {
       Insert8(i,ship_num,len,row,col);
        if(state==1)
            col++;
        else
            row++;
    }
    if(ships_position_condition_check()==0)
    {
       printf("You disobeyed the laws. start over");
       ship_set();
    }
    ship_num++;
    //9th ship: 2x1
    printf("enter info for ship with length of 4x1:\n\n");
    printf("1)Horizontal\n2)Vertical ::\n");
    scanf("%d%d%d",&state,&row,&col);
    len=1;
    map_set(state,row,col,len);
     for(int i=1;i<=len;i++)
    {
       Insert9(i,ship_num,len,row,col);
        if(state==1)
            col++;
        else
            row++;
    }
    if(ships_position_condition_check()==0)
    {
       printf("You disobeyed the laws. start over");
       ship_set();
    }
    ship_num++;
    //10th ship: 2x1
    printf("enter info for ship with length of 4x1:\n\n");
    printf("1)Horizontal\n2)Vertical ::\n");
    scanf("%d%d%d",&state,&row,&col);
    len=1;
    map_set(state,row,col,len);
     for(int i=1;i<=len;i++)
    {
        Insert10(i,ship_num,len,row,col);
        if(state==1)
            col++;
        else
            row++;
    }
    if(ships_position_condition_check()==0)
    {
       printf("You disobeyed the laws. start over");
       ship_set();
    }
    //ship_num++;

}
void map_set(int state,int row,int col,int len)
{
    //for that state is horizental
    if(state==1)
    {
        if((col+len)<=max)
        {
            for(int i=col;i<len+col;i++)
            {
                map[row][i]=83;

            }
            show_map();
        }
        else
        {
             printf("CANT FIT SHIP IN MAP!!!!!!! \a");
             ship_set();
        }


    }
    //for that state is vertical
    else if(state==2)
    {
        if((row+len)<=max)
        {
            for(int i=row;i<len+row;i++)
            {
                map[i][col]=83;
            }
            show_map();
        }
          else
        {
             printf("CANT FIT SHIP IN MAP!!!!!!! \a");
             ship_set();
        }
    }
}
void show_map()
{
    for(int i=0;i<max;i++)
   {

       for(int j=0;j<max;j++)
       {
            if((i==0)&&j==0)
                {
                    //map[i][j]=0;
                  printf("\t");
                }
            else if(i==0)
            {
                //map[i][j]=t;
                //t++;
                printf("%d\t",map[i][j]);
            }
            else if(j==0)
            {
               // map[i][j]=n;
               // n++;
                printf("%d\t",map[i][j]);
            }
            else
            {
               // map[i][j]=87;
                printf("%c\t",map[i][j]);

            }

       }
       printf("\n");


   }
}
//the proper func to make linked list for ship of size 5x1
void Insert1(int i,int num,int len,int row,int col)
{
    ship* temp=(ship *)malloc(sizeof(struct ship));
     ship* temp2=(ship *)malloc(sizeof(struct ship));
     //ship* temp=&map[row][col];

   temp->index=i;
    temp->indicator=num;
    temp->len=len;
    temp->row=row;
    temp->col=col;
    temp->next=NULL;

    if(head1==NULL)
    {
        head1=temp;
    }

    else
    {
        temp2=head1;
        while(temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        temp2->next=temp;

    }
}
//the proper func to make linked list for 1st ship of size 3x1
void Insert2(int i,int number,int len,int row,int col)
{
    ship* temp=(ship *)malloc(sizeof(struct ship));
    ship* temp2=(ship *)malloc(sizeof(struct ship));

   temp->index=i;
    temp->indicator=number;
    temp->len=len;
    temp->next=NULL;
    temp2=head2;
    if(head2==NULL)
    {
        head2=temp;
    }
    else
    {

        while(temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        temp2->next=temp;

    }
}
//the proper func to make linked list for 2nd ship of size 3x1
void Insert3(int i,int number,int len,int row,int col)
{
    ship* temp=(ship *)malloc(sizeof(struct ship));
    ship* temp2=(ship *)malloc(sizeof(struct ship));

   temp->index=i;
    temp->indicator=number;
    temp->len=len;
    temp->next=NULL;
    temp2=head3;
    if(head3==NULL)
    {
        head3=temp;
    }
    else
    {

        while(temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        temp2->next=temp;

    }
}
//the proper func to make linked list for 1st ship of size 2x1
void Insert4(int i,int number,int len,int row,int col)
{
    ship* temp=(ship *)malloc(sizeof(struct ship));
    ship* temp2=(ship *)malloc(sizeof(struct ship));

   temp->index=i;
    temp->indicator=number;
    temp->len=len;
    temp->next=NULL;
    temp2=head4;
    if(head4==NULL)
    {
        head4=temp;
    }
    else
    {

        while(temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        temp2->next=temp;

    }
}
//the proper func to make linked list for 2nd ship of size 2x1
void Insert5(int i,int number,int len,int row,int col)
{
    ship* temp=(ship *)malloc(sizeof(struct ship));
    ship* temp2=(ship *)malloc(sizeof(struct ship));

   temp->index=i;
    temp->indicator=number;
    temp->len=len;
    temp->next=NULL;
    temp2=head5;
    if(head5==NULL)
    {
        head5=temp;
    }
    else
    {

        while(temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        temp2->next=temp;

    }
}

//the proper func to make linked list for 3rd ship of size 2x1
void Insert6(int i,int number,int len,int row,int col)
{
    ship* temp=(ship *)malloc(sizeof(struct ship));
    ship* temp2=(ship *)malloc(sizeof(struct ship));

   temp->index=i;
    temp->indicator=number;
    temp->len=len;
    temp->next=NULL;
    temp2=head6;
    if(head6==NULL)
    {
        head6=temp;
    }
    else
    {

        while(temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        temp2->next=temp;

    }
}

//the proper func to make linked list for 1st ship of size 4x1
void Insert7(int i,int number,int len,int row,int col)
{
    ship* temp=(ship *)malloc(sizeof(struct ship));
    ship* temp2=(ship *)malloc(sizeof(struct ship));

   temp->index=i;
    temp->indicator=number;
    temp->len=len;
    temp->next=NULL;
    temp2=head7;
    if(head7==NULL)
    {
        head7=temp;
    }
    else
    {

        while(temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        temp2->next=temp;

    }
}

//the proper func to make linked list for 2nd ship of size 4x1
void Insert8(int i,int number,int len,int row,int col)
{
    ship* temp=(ship *)malloc(sizeof(struct ship));
    ship* temp2=(ship *)malloc(sizeof(struct ship));

   temp->index=i;
    temp->indicator=number;
    temp->len=len;
    temp->next=NULL;
    temp2=head8;
    if(head8==NULL)
    {
        head8=temp;
    }
    else
    {

        while(temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        temp2->next=temp;

    }
}

//the proper func to make linked list for 3rd ship of size 4x1
void Insert9(int i,int number,int len,int row,int col)
{
    ship* temp=(ship *)malloc(sizeof(struct ship));
    ship* temp2=(ship *)malloc(sizeof(struct ship));

   temp->index=i;
    temp->indicator=number;
    temp->len=len;
    temp->next=NULL;
    temp2=head9;
    if(head9==NULL)
    {
        head9=temp;
    }
    else
    {

        while(temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        temp2->next=temp;

    }
}

//the proper func to make linked list for 4th ship of size 4x1
void Insert10(int i,int number,int len,int row,int col)
{
    ship* temp=(ship *)malloc(sizeof(struct ship));
    ship* temp2=(ship *)malloc(sizeof(struct ship));

   temp->index=i;
    temp->indicator=number;
    temp->len=len;
    temp->next=NULL;
    temp2=head10;
    if(head10==NULL)
    {
        head10=temp;
    }
    else
    {

        while(temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        temp2->next=temp;

    }
}
int ships_position_condition_check()
{
    int flag=1;
    //return 1 for being same ships
    //return 0 for being different ships
    for(int i=0;i<max;i++)
    {
        for(int j=0;j<max;j++)
        {

            if(map[i][j]==83)
            {
                if(map[i-1][j]==83)
                {
                   if(search_ship(i,j)!=search_ship(i-1,j))
                        return 0;

                }
                if(map[i+1][j]==83)
                {
                    if(search_ship(i,j)!=search_ship(i+1,j))
                        return 0;

                }
                if(map[i][j-1]==83)
                {
                    if(search_ship(i,j)!=search_ship(i,j-1))
                        return 0;
                }
                if(map[i][j+1]==83)
                {
                    if(search_ship(i,j)!=search_ship(i,j+1))
                        return 0;
                }
            }

        }
    }
    return 1;
}
int search_ship(int row,int col)
{
    ship* temp;
    temp=head1;
    while(temp!=NULL)
    {
        if((temp->row=row)&&(temp->col=col))
            return temp->indicator;
        temp=temp->next;
    }
    temp=head2;
    while(temp!=NULL)
    {
        if((temp->row=row)&&(temp->col=col))
            return temp->indicator;
        temp=temp->next;
    }
    temp=head3;
    while(temp!=NULL)
    {
        if((temp->row=row)&&(temp->col=col))
            return temp->indicator;
        temp=temp->next;
    }
    temp=head4;
    while(temp!=NULL)
    {
        if((temp->row=row)&&(temp->col=col))
            return temp->indicator;
        temp=temp->next;
    }
    temp=head5;
    while(temp!=NULL)
    {
        if((temp->row=row)&&(temp->col=col))
            return temp->indicator;
        temp=temp->next;
    }
    temp=head6;
    while(temp!=NULL)
    {
        if((temp->row=row)&&(temp->col=col))
            return temp->indicator;
        temp=temp->next;
    }
    temp=head7;
    while(temp!=NULL)
    {
        if((temp->row=row)&&(temp->col=col))
            return temp->indicator;
        temp=temp->next;
    }

    temp=head8;
    while(temp!=NULL)
    {
        if((temp->row=row)&&(temp->col=col))
            return temp->indicator;
        temp=temp->next;
    }
    temp=head9;
    while(temp!=NULL)
    {
        if((temp->row=row)&&(temp->col=col))
            return temp->indicator;
        temp=temp->next;
    }
    temp=head10;
    while(temp!=NULL)
    {
        if((temp->row=row)&&(temp->col=col))
            return temp->indicator;
        temp=temp->next;
    }

}
#endif // GAME_ALGORYTHM_H_INCLUDED
