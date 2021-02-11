//
// Created by ASUS on ۱۱/۰۲/۲۰۲۱.
//

#ifndef PAYANTERM_MENU_FUNCS_H
#define PAYANTERM_MENU_FUNCS_H

FILE *fp;
FILE *fsize;
void add_user()
{


    fp=fopen("users.bin","a+b");
    char new_name[100];
    scanf("%s",new_name);
    int n=strlen(new_name);
    int i=n;
    fwrite(new_name,sizeof(char),n,fp);
    fclose(fp);

}
void show_user()
{
    fp=fopen("users.bin","a+b");
    // fsize=fopen("name_sizes.bin","r+b");
    int i=1;
    char name[100];
    // while()


    fclose(fp);


}
void finish_game()
{
    printf("\n see you soon comrade\n");
}
#endif //PAYANTERM_MENU_FUNCS_H
