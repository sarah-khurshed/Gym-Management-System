#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
#include "splash.h"
#include "login.h"
#include "menu.h"


int main(void)
 {
    system("color 8B");

    splash();

   int l=Login();

   if(l==0)
    {
       main();
    }

   else if(l==1)
   {

       int n;

     printf("\tChoose an option \n");

    printf("\t--------------------\n\n\n");

     printf("\t1. Member Management.\n\n");
     printf("\t2. Number of members/Booked slot.\n");

     printf("\n\n\t Enter chosen option : ");
     scanf("%d", &n);

   switch(n)
    {
        case 1:
             file_handling();
        break;

       case 2:
            slot();
       break;
    }
   }
    return 0;
 }
