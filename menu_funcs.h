//
// Created by ASUS on ۱۱/۰۲/۲۰۲۱.
//

#ifndef PAYANTERM_MENU_FUNCS_H
#define PAYANTERM_MENU_FUNCS_H

struct user
{
    char name[20];
};
typedef struct user user;
FILE *fp;
FILE *fsize;
void add_user()
{


    fp=fopen("users.bin","a+b");
    user new_user;
    scanf("%s",new_user.name);
//    /int n=strlen(new_name);
//    int i=n;
    fwrite(new_user.name,sizeof(user),1,fp);
    fclose(fp);

}
void show_user()
{
    fp=fopen("users.bin","a+b");
    // fsize=fopen("name_sizes.bin","r+b");
    int i=1;
    char name[100];
    if(feof(fp))
    {
        printf("no available users.start over");

    }
   while(!feof(fp))
   {
       printf("\ni)\n");
       char name[20];
       fread(name,sizeof(user),1,fp);
       printf("%s",name);
   }


    fclose(fp);


}
void finish_game()
{
    printf("\n see you soon comrade\n");
}
#endif //PAYANTERM_MENU_FUNCS_H
