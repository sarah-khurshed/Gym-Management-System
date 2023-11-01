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

    printf("\t\t\tWelcome to Manager Login Page\n");
    printf("\t\t\t______________________________\n\n");

    printf("Manager name: \n");
    gets(l.name);
    printf("Please enter password: \n");
    gets(l.password);


    if(strcmp(l.name,"manager")==0)
    {
        if(strcmp(l.password,"1234")==0)
        {
            printf("Verified\n");
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
