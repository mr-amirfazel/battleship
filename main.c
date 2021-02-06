#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu_funcs.h"
#include "game_algorythm.h"
void Menu()
{
    printf("1. Play with a Friend\n2. Play with a bot\n3.Load game\n4.Load last game\n5. setting\n6. Score Board\n7. Exit\n");
}
void Menu_dec(int* x);
void Play_with_a_friend();
void Play_with_Bot();
void Load_game();
void Load_last_game();
void Settings();
void Score_Board();
void Exit();
int main()
{

//system(COLOR )
    Menu();
    int x;
    scanf("%d",&x);
    Menu_dec(&x);
    return 0;
}
Menu_dec(int* x)
{
    int i=*x;
    switch(i)
    {
    case 1:
        Play_with_a_friend();
    case 2:
        Play_with_Bot();
    case 3:
        Load_game();
    case 4:
        Load_last_game();
    case 5:
        Settings();
    case 6:
        Score_Board();
    case 7:
        Exit();
    }

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
    case 2:
        add_user();
    }


    printf("2.put ships\n\t1.Auto\n2.Manual");
    int ship_dec;
    scanf("%d",&ship_dec);
    //functions to lead the user to the map ordering




    //Second player:
    printf("Second player:\n\t1.choose user\n");
    printf("\t1.choose from available users\n2.new users");
    int user2_decide;
    scanf("%d",&user2_decide);
    //place to add adequate function
    // to show users list or add new user
    //to the binary file database



    printf("2.put ships\n\t1.Auto\n2.Manual");
    int ship2_dec;
    scanf("%d",&ship2_dec);
    //functions to lead the user to the map ordering



}
void Play_with_Bot()
{

}
void Load_game()
{

}
void Load_last_game()
{

}
void Settings()
{
    printf("1.ships\n2.map size\n3.theme");
    int setting_choice;
    scanf("%d",&setting_choice);
    //add functions for every setting options
}
void Score_Board()
{

}
void Exit()
{
    return 0;
}
