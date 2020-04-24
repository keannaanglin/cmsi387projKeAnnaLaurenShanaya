#include <linux/syscalls.h>
#include <linux/kernel.h>

SYSCALL_DEFINE2(rapname, char*, first, char*, last)
{
	
   int first_index = (int)first[0]; //get ASCII values
   int last_index = (int)last[0];
 
   if(first_index >= 97 && first_index <= 122){ // ASCII for a-z = 97 - 126, subtract by 97 to get indices 0-25
       first_index = first_index - 97;
   }
   else if(first_index >= 65 && first_index <= 90){ // ASCII for A-Z = 65 - 90, subtract by 65 to get indices 0-25
       first_index = first_index - 65;
   }
   else{
       first_index = 0;
   }
 
   //repeat for last name
    if(last_index >= 97 && last_index <= 122){
       last_index = last_index - 97;
   }
   else if(last_index >= 65 && last_index <= 90){
       last_index = last_index - 65;
   }
   else{
       last_index = 0;
   }
 
   char first_name[26][15] = {
       "Lil ",
       "Shawty ",
       "Dirty ",
       "Pusha ",
       "Nephew ",
       "Tasty ",
       "Drizzy ",
       "Crispy ",
       "Senor ",
       "Scumbag ",
       "Thug ",
       "Baby ",
       "Krakka ",
       "Killa ",
       "Brotha ",
       "Drippin ",
       "Mo ",
       "Grillz ",
       "$hmoney ",
       "Fresh ",
       "MC ",
       "Smoke ",
       "BB ",
       "Clout ",
       "Chilly ",
       "Sir "
   };

   char last_name[26][15] = {
       "Baby",
       "Glock",
       "Dollaz",
       "Tha Juice",
       "Dawg",
       "Computer",
       "$moke",
       "Low-Key",
       "Double-O",
       "Playa",
       "Dutch Boy",
       "Book Nerd",
       "Juice Box",
       "Dagga",
       "Pain",
       "Swaggy",
       "Flame",
       "Funk",
       "Skrt Skrt",
       "Dijon",
       "Kool",
       "Steez",
       "Pastrami",
       "Get 'Em",
       "Lasagna",
       "Ca$h"
    };
 
    char* rap_name = first_name[first_index];
    int i,j;
    for(i=0; rap_name[i]!='\0'; ++i); // length of first_name

    for(j=0; last_name[last_index][j]!='\0'; ++j, ++i)
    {
       rap_name[i]=last_name[last_index][j];
    }
    rap_name[i]='\0';

    printk("Rap Name: %s\n", rap_name);
    return 0;
}
