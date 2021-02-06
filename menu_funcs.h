#ifndef MENU_FUNCS_H_INCLUDED
#define MENU_FUNCS_H_INCLUDED
FILE *fp;

void add_user()
{
    //printf("test");
    fp=fopen("users.bin","a+b");
    char new_name[100];
    //gets(new_name);
    scanf("%s",new_name);
    int n=strlen(new_name);
    fwrite(new_name,sizeof(char),n,fp);
    fclose(fp);

}
void show_user()
{
    fp=fopen("users.bin","a+b");


}

#endif // MENU_FUNCS_H_INCLUDED
