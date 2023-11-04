#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

typedef struct Member{
    char name[30];
    int id;
    double payment;
    int slot;
}member;


void file_handling();
void file_handling(){
    int flag=0;
    while(flag==0){
        int n;
        system("cls");

        printf("\t\t\tMember and Schedule Managing Page\n");
        printf("\t\t\t___________________________________\n");

        printf("1.Add Member.\n2.List of Members.\n3.Search Member.\n");
        printf("4.Remove Member.\n5.Edit Member.\n6.View Schedule\n7.Exit.\n");
        scanf("%d", &n);
        fflush(stdin);
        switch(n){
            case 1: add_member();
                break;
            case 2: list_of_members();
                break;
            case 3: search_member();
                break;
            case 4: remove_member();
                break;
            case 5: edit_member();
                break;
            case 6: show_slots();

            case 7: flag=1;
                break;
            default:
                printf("Invalid Input.\n");
                getch();
                file_handling();
                break;
        }
    }

}
void add_member()
{
    system("cls");
    FILE *fa = fopen("ym.txt", "a+"); // fopen(filename, mode)
    member me;
    fflush(stdin);
    printf("Member's Name: ");
    gets(me.name);fflush(stdin);

    printf("Member's ID: ");
    scanf("%d", &me.id);fflush(stdin);

    printf("Member's Payment: ");
    scanf("%lf", &me.payment);fflush(stdin);

    printf("Member's Slot: ");


    scanf("%d", &me.slot);fflush(stdin);
    fwrite(&me,sizeof(me),1,fa); // fwrite(source, sizeof(struct),1,destination file)
    printf("Added!\n");
    fclose(fa);
    getch();
}


void list_of_members()//To show the list of members along with the information
{
    system("cls");
    printf("\t\t\t\tList of Members \n\n");
    FILE *fr = fopen("ym.txt", "r+");
    member me;
    while(fread(&me,sizeof(me),1,fr) != NULL){
        printf(" Name :%s\nID : %d\n Paid amount: %.2f\n Booked Slot: %d\n\n", me.name,me.id,me.payment, me.slot);
    }

    fclose(fr);
    getch();

}

//To search for an added member
void search_member()
{
    system("cls");
    FILE *fs = fopen("ym.txt", "r+");
    member me;

    char search[30];
    printf("Search by name: ");
    gets(search);
    fflush(stdin);

    int flag = 0;

    while(fread(&me,sizeof(me),1,fs) != NULL)
       {
        if(strcmp(me.name,search)==0)
          {
            printf("Name: %s\nID :%d\nPaid Amount : %.2f\n", me.name,me.id,me.payment);
            getch();

            flag = 1;

            break;
          }
    }
    if(flag == 0)
     {
        printf("Not Found! Try Again!");
        getch();
        search_member();
     }
    fclose(fs);
    getch();
}

  void edit_member()//To edit a member's information
   {

   system("cls");
    FILE *fs;
    fs = fopen("ym.txt", "r+");
    member me;

    char search[30];
    printf("Search by name: ");
    gets(search);
    fflush(stdin);
    rewind(fs); //Resets the file cursor position

    while(fread(&me,sizeof(me),1,fs) != NULL){
        if(strcmp(search,me.name) == 0){
            fflush(stdin);
            printf("Member's Name: ");
            gets(me.name);fflush(stdin);
            printf("Member's ID: ");
            scanf("%d", &me.id);fflush(stdin);
            printf("Member's Payment: ");
            scanf("%lf", &me.payment);fflush(stdin);
            fseek(fs,-sizeof(me),SEEK_CUR);
            fwrite(&me,sizeof(me),1,fs);
            break;
        }
    }

    fclose(fs);
    getch();
}


  void remove_member()//To remove a previously added member
  {
    system("cls");

    char search[30];
    printf("Search by Name: ");
    gets(search);
    fflush(stdin);

    member me;
    FILE *source = fopen("ym.txt", "r+");
    FILE *copy = fopen("ym_temp.txt", "w+");

    while(fread(&me,sizeof(me),1,source) != NULL)
       {

        if(strcmp(search,me.name) != 0){
            fwrite(&me,sizeof(me),1,copy);
        }
       }

    fclose(source);
    fclose(copy);

    remove("ym.txt"); //remove(source file)
    rename("ym_temp.txt","ym.txt"); //rename(temp file, desired name of file)

    printf("Successfully Removed");
    getch();
}


   void show_slots()//show the time slots
   {

        system("cls");

    char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
    char *times[] = {"8:00 AM", "9:30 AM", "11:00 AM", "12:30 PM", "2:00 PM"};

    printf("Time Schedule:\n\n");

    // Display row with  times
    printf("%-12s|%-14s|%-14s|%-14s|%-14s|%-14s|\n", "", "8:00 AM", "9:30 AM", "11:00 AM", "12:30 PM", "2:00 PM");

    // Display slot according to day and time
    for(int i = 1; i <= 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%-12s|", days[j]);

            for(int k = 0; k < 5; k++)
            {
                printf("slot%-9d |", i++);
            }

            printf("\n");
        }
    }

    getch();

   }


   void slot()//member number will increase if added and decrease when removed
   {
    system("cls");

    int arr[25];

    for(int i=0;i<25;i++)
    {
        arr[i] = 0;
    }

    FILE *fs = fopen("ym.txt","r+");
    member me;

    while(fread(&me,sizeof(me),1,fs) != NULL)
        {
          arr[me.slot-1]++;
        }

    printf("\t\t\t\t\t\tSlots: \n\n\n");

    for(int i=0;i<25;i++)
     {
        printf("\t\tSlot %d = %d members\n",i, arr[i]);
     }

    fclose(fs);

    getch();
 }


#endif // MENU_H_INCLUDED
