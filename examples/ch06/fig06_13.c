// Fig. 6.13: fig06_13.c
// Passing arrays and individual array elements to functions.
#include <stdio.h>
#include <stdbool.h>

#define SIZE 5
#define REVIEWER 3
#define MOVIE 4
#define MIN_SCORE 0
#define MAX_SCORE 10

// function prototypes
void modifyArray(int b[], size_t size);
void modifyElement(int e);        
void printArray(const int c[], size_t size);
void modifyMultiArray(int a[][MOVIE], size_t reviewer, size_t movie);
void printMultiArray(const int c[][MOVIE], size_t reviewer, size_t movie);

// function main begins program execution
int main(void)
{
   int a[SIZE] = { 0, 1, 2, 3, 4 }; // initialize array a
   int multiArray[REVIEWER][MOVIE];

   // Showing that the value of an array is the address of the first 
   // element in the array 
   puts("");
   printf("array: %p    &array[0]: %p    &array: %p", a, &a[0], &a);
   puts("");
   puts("");

   puts("Effects of passing entire array by reference:\n\nThe "
      "values of the original array are:");

   // output original array
   for (size_t i = 0; i < SIZE; ++i) { 
      printf("%3d", a[i]);
   } 

   puts(""); // outputs a newline

   modifyArray(a, SIZE); // pass array a to modifyArray by reference                         
   puts("The values of the modified array are:");

   // output modified array
   for (size_t i = 0; i < SIZE; ++i) {
      printf("%3d", a[i]);
   } 


   // output value of a[3]
   printf("\n\n\nEffects of passing array element "
      "by value:\n\nThe value of a[3] is %d\n", a[3]);
   
   modifyElement(a[3]); // pass array element a[3] by value

   // output value of a[3]
   printf("The value of a[3] is %d\n", a[3]);


   // Asking user for the values of the multi array
   modifyMultiArray(multiArray, REVIEWER, MOVIE);

   // Printing out the multi array
   printMultiArray(multiArray, REVIEWER, MOVIE);
}

// in function modifyArray, "b" points to the original array "a" 
// in memory                                                     
void modifyArray(int b[], size_t size)                               
{                                                                   
   // multiply each array element by 2                         
   for (size_t j = 0; j < size; ++j) {                                 
      b[j] *= 2; // actually modifies original array               
   }                                                 
} 

// in function modifyElement, "e" is a local copy of array element
// a[3] passed from main                                     
void modifyElement(int e)                                       
{                                                                 
   // multiply parameter by 2                                  
   printf("Value in modifyElement is %d\n", e *= 2);            
} 
                       
// Printing an array
void printArray(const int c[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("Value of array[%llu]: %d\n", i, c[i]);
    }
}

void modifyMultiArray(int a[][MOVIE], size_t reviewer, size_t movie) {
    puts("");
    //Initializing local variables
    unsigned int score = 0;
    int scanReturn = -1;
    bool numberValid = false;

    //for loop going through the multi array
    for (size_t i = 0; i < reviewer; i++) {
        for (size_t j = 0; j < movie; j++) {
            //Asking user for the reviewer's score of the movie + validating outputs
            numberValid = false;
            do {
                printf("Enter reviewer %llu's review of movie %llu (between %d-%d): ", i, j, MIN_SCORE, MAX_SCORE);
                scanReturn = scanf("%u", &score);
                while ((getchar()) != '\n');

                // If scanf is not an int between 0-10
                if (scanReturn != 1 || score < MIN_SCORE || score > MAX_SCORE) {
                    puts("Invalid input :(");
                }
                else {
                    a[i][j] = score;
                    numberValid = true;
                }
            } while (!numberValid);
            
        }
    }
}

void printMultiArray(const int c[][MOVIE], size_t reviewer, size_t movie) {
    // Goes through rows
    for (size_t i = 0; i < reviewer; i++) {
        puts("");

        // Goes through columns
        for (size_t j = 0; j < movie; j++) {
            printf("%d ", c[i][j]);
        }
    }
}




/**************************************************************************
 * (C) Copyright 1992-2015 by Deitel & Associates, Inc. and               *
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
 *************************************************************************/

