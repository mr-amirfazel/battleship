#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "menu_funcs.h"
#include "game_algorythm.h"
#include "game_main.h"
void display_message();
void display_message()
{

    printf("what you are searching for is not available in this version of game"
           "\n check them out in next updates :)\n you will be redirected to menu");
    Menu();
    menu_collect();
}
void Menu()
{
    printf("1. Play with a Friend\n2. Play with a bot\n3.Load game\n4.Load last game\n5. setting\n6. Score Board\n7. Exit\n");
}


void Play_with_a_friend()
{
    //First player:
    printf("First player:\n             1.choose user:\n");
    printf("\t1.choose from available users\n\t2.new users");
    int user_decide;
    scanf("%d",&user_decide);
    //place to add adequate function
    // to show users list or add new user
    //to the binary file database
    switch(user_decide)
    {
        case 1:

            show_user();
            break;

        case 2:
            add_user();
            break;


    }


    printf("2.put ships\n\t1.Auto\n2.Manual");
    int ship_dec;
    scanf("%d",&ship_dec);
    //functions to lead the user to the map ordering
    switch(ship_dec)
    {
        case 1:
            //havent activated yet
            break;

        case 2:
            ship_set();
            break;
    }



    //Second player:
    printf("Second player:\n\t1.choose user\n");
    printf("\t1.choose from available users\n2.new users");
    int user2_decide;
    scanf("%d",&user2_decide);
    //place to add adequate function
    // to show users list or add new user
    //to the binary file database
    switch(user2_decide)
    {
        case 1:

            show_user();
            break;
        case 2:
            add_user();
            break;
    }
    printf("2.put ships\n\t1.Auto\n2.Manual");
    int ship2_dec;
    scanf("%d",&ship2_dec);
    //functions to lead the user to the map ordering
    switch(ship2_dec)
    {
        case 1:
            //havent activated yet
            break;

        case 2:

            ship2_set();
            break;

    }

    game();

}


void Play_with_Bot()
{
//single player mode
//here we go again :|
    play_with_adolf();
}

void Load_game()
{
    display_message();
}
void Load_last_game()
{
    display_message();
}

void Settings()
{
    display_message();
//    printf("1.ships\n2.map size\n3.theme");
//    int setting_choice;
//    scanf("%d",&setting_choice);
    //add functions for every setting options
}
void Score_Board()
{
    display_message();
}
int Exit()
{
    finish_game();
    return 0;
}

void intro()
{
    printf("\t\t welcome dear user to\t\t\n");
    printf("\t  the legend of Sea Battle\t\n\n\t\n");
}

int Menu_dec(int* x)
{
    int i=*x;
    switch(i)
    {
        case 1:
        {
            Play_with_a_friend();
            break;
        }

        case 2:
        {
            Play_with_Bot();
            break;
        }

        case 3:
        {
            Load_game();
            break;
        }

        case 4:
        {
            Load_last_game();
            break;
        }

        case 5:
        {
            Settings();
            break;
        }

        case 6:
        {
            Score_Board();
            break;
        }

        case 7:
            Exit();
            //break;
    }

}
void menu_collect()
{
    int x;
    scanf("%d",&x);
    Menu_dec(&x);
}
int main()
{
    intro();
    Menu();
    menu_collect();
    return 0;
}


