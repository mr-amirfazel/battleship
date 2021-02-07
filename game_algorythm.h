#ifndef GAME_ALGORYTHM_H_INCLUDED
#define GAME_ALGORYTHM_H_INCLUDED
#define max 11
 int map[max][max];
struct ship{
    int len;
    int number;
    struct node *next_part;

};
typedef struct node ship;
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
    link_maker(state,row,col,len);
    //2nd ship: 3x1
    printf("enter info for ship with length of 3x1:\n\n");
    printf("1)Horizontal\n2)Vertical ::\n");
    scanf("%d%d%d",&state,&row,&col);
    len=3;
    map_set(state,row,col,len);
    link_maker(state,row,col,len);
    //3rd ship: 3x1
    printf("enter info for ship with length of 3x1:\n\n");
    printf("1)Horizontal\n2)Vertical ::\n");
    scanf("%d%d%d",&state,&row,&col);
    len=3;
    map_set(state,row,col,len);
    link_maker(state,row,col,len);
    //4th ship: 2x1
    printf("enter info for ship with length of 3x1:\n\n");
    printf("1)Horizontal\n2)Vertical ::\n");
    scanf("%d%d%d",&state,&row,&col);
    len=2;
    map_set(state,row,col,len);
    link_maker(state,row,col,len);
    //5th ship: 2x1
    printf("enter info for ship with length of 3x1:\n\n");
    printf("1)Horizontal\n2)Vertical ::\n");
    scanf("%d%d%d",&state,&row,&col);
    len=2;
    map_set(state,row,col,len);
    link_maker(state,row,col,len);
    //6th ship: 2x1
    printf("enter info for ship with length of 3x1:\n\n");
    printf("1)Horizontal\n2)Vertical ::\n");
    scanf("%d%d%d",&state,&row,&col);
    len=2;
    map_set(state,row,col,len);
    link_maker(state,row,col,len);
   //7th ship: 2x1
    printf("enter info for ship with length of 3x1:\n\n");
    printf("1)Horizontal\n2)Vertical ::\n");
    scanf("%d%d%d",&state,&row,&col);
    len=1;
    map_set(state,row,col,len);
    link_maker(state,row,col,len);
    //8th ship: 2x1
    printf("enter info for ship with length of 3x1:\n\n");
    printf("1)Horizontal\n2)Vertical ::\n");
    scanf("%d%d%d",&state,&row,&col);
    len=1;
    map_set(state,row,col,len);
    link_maker(state,row,col,len);
    //9th ship: 2x1
    printf("enter info for ship with length of 3x1:\n\n");
    printf("1)Horizontal\n2)Vertical ::\n");
    scanf("%d%d%d",&state,&row,&col);
    len=1;
    map_set(state,row,col,len);
    link_maker(state,row,col,len);
    //10th ship: 2x1
    printf("enter info for ship with length of 3x1:\n\n");
    printf("1)Horizontal\n2)Vertical ::\n");
    scanf("%d%d%d",&state,&row,&col);
    len=1;
    map_set(state,row,col,len);
    link_maker(state,row,col,len);

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
                map[row][i]='S';

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
    else
    {
        if((row+len)<=max)
        {
            for(int i=row;i<len+row;i++)
            {
                map[i][col]='S';
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
void link_maker(int state,int row,int col,int len)
{

}
#endif // GAME_ALGORYTHM_H_INCLUDED
