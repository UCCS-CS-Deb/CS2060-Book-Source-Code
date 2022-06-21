// Fig. 2.1: fig02_01.c
// A first program in C 
#include <stdio.h>

// function main begins program execution 
int main( void )
{
	//Initializing variables
	unsigned int length = 0;
	unsigned int width = 0;
	unsigned int area = 0;
	unsigned int division = 0;

	//Getting input for length
	puts("Enter the length: ");
	scanf("%u", &length);

	//Getting input for width
	puts("Enter the width: ");
	scanf("%u", &width);

	//Calculating area
	area = length * width;

	//Calculating length/width
	division = length / width;

	printf("Length: %u   Width: %u   Area: %u\n", length, width, area);
	printf("Length/width: %u\n", division);

	return 0;
} // end function main 


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
