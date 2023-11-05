#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED
typedef struct Manager {

char name[20];
char password[30];


}manage;

 int Login();
 int Login()
{
    system("color 71");
    manage l;

    fflush(stdin);

    printf("\n\t\t\t\Welcome to FIT HUB Manager Login Page\n");
    printf("\n\t\t\t______________________________________\n\n");

    printf("\t\tManager name: ");
    gets(l.name);
    printf("\n\t\tPlease enter password: ");
    gets(l.password);


    if(strcmp(l.name,"manager")==0)
    {
        if(strcmp(l.password,"1234")==0)
        {
            printf("\n\n\t\tTaking to the menu.Please wait for a sec...\n");
            sleep(1);

        system("cls");

        return 1;

        }
        else
            printf("Wrong name or password! ");
            sleep(2);
            system("cls");

             Login();//return to login page
    }

    else
      {
        printf("Unverified, hence redirecting to login page \n");

        return 0;

      }
    }


#endif // LOGIN_H_INCLUDED
