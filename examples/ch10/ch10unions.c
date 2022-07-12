//Ch10 Union and Structure

#include <stdio.h>
#include <string.h>

union id
{
	char name[40];
	unsigned long number;
};

typedef struct 
{
	gpa float;
	union id description;
} Student

int main( )
{
	// declare union
	union id infoUCCS;

	// What do you notice about the memory size.
	printf( "Memory size occupied by data : %d\n", sizeof(infoUCCS));

	// initialize union
	infoUCCS.number = 312409;
	strcpy( infoUCCS.name, "Debug Rebels");

	// What is printed out and why?
	printf( "\ninfoUCCS.number : %lu\n", infoUCCS.number);
	printf( "infoUCCS.name: %s\n", infoUCCS.name);

	// Can you explain the following?
	infoUCCS.number = 556789;
	printf( "\ninfoUCCS.number: %lu\n", infoUCCS.number);


	strcpy( infoUCCS.name, "Format Fury");
	printf( "infoUCCS.name: %s\n", infoUCCS.name);
	
	TA ta1 = {10000, 'Pointer Sisters'};
	Faculty fac1 = {70000, 20456};
		
	printf("sizeof(ta1\n%d\n", sizeof(ta1));
	printf(" sizeof(fac1)\n%d\n", sizeof(fac1));

	printf("%s %d\n",
	ta1.description.name,ta1.description.number);
	fac1.description.number = 12;
	printf("%s %d\n",
	fac1.description.name,fac1.description.number);


	return 0;
}




