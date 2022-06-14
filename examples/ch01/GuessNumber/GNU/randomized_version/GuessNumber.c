/*
* The program randomly generates numbers   
* between 1 and 1000 for the user to guess.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MIN_NUMBER 1
const MAX_NUMBER = 100;

void guessGame(void); 
int isCorrect(int, int); 


int main(void)
{
   srand(time(0));
   guessGame(); 

   return 0;
} // end main


void guessGame(void)
{
   int answer = 0; 
   int guess = 0; 
   int response = 0; 

   do {
      answer = MIN_NUMBER + rand() % MAX_NUMBER;

      printf("Hello AJ, I have a number between %d and %d .\n" 
          "Can you guess my number?\n"
           "Please type your first guess.", MIN_NUMBER, MAX_NUMBER);

      printf("%s", "? ");
      scanf("%d", &guess);

      while (!isCorrect(guess, answer)) 
         scanf("%d", &guess);

      puts("\nExcellent! You guessed the number!\n"
         "Would you like to play again?");
      printf("%s", "Please type ( 1=yes, 2=no )? ");
      scanf("%d", &response);

      puts("");
   } while (response == 1);
} 


int isCorrect(int g, int a)
{
    if (g == a){
        return 1;
    }

   if (g < a)
      printf( "%s", "Too low. Try again.\n? " );
   else
      printf( "%s", "Too high. Try again.\n? " );

   return 0;
} 



/**************************************************************************
 * (C) Copyright 1992-2012 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
