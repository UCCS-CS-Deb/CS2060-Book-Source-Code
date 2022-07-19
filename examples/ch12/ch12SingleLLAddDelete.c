/*
Example code to create a linked list of structure
Use this code example instead of the book example
Set debug to see what happens when adding and deleting different nodes. 
See if you can determine which line of code runs next before stepping.
What happens if you change void insertNode (Node **headPtr, int number) 
to void insertNode (Node *headPtr, int number)?

Add comments to explain code
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



//In this example we will just use a generic name node and data to represent a structure
//
typedef struct node
{
	//
	int data;

	//
	struct node * nextNodePtr;
}Node;

void exploreDoublePointers();
void linkingLists();
void printList (Node*listPtr);
void insertNode (Node **headPtr, int number);
void deleteNode (Node **headPtr, int numberToDelete);
void freeRemainingNodes(Node** headPtr);
char validateYesNo();


int main(void)
{

	linkingLists();
	puts("Explore double pointers");
	exploreDoublePointers();

	puts("\n\nExplore linked lists");

	//
	Node *headNodePtr = NULL;
	int number = 0;
	char yesOrNo = ' ';


	printList(headNodePtr);

	//
	do
	{
		//Focusing on linked lists so not validating that a number was entered
		printf("%s", "Enter number ");	
		scanf("%d", &number);
		while ((getchar()) != '\n');

		// 
		insertNode(&headNodePtr, number);

		// why does insert node pass the address of head pointer but print list does not?
		printList(headNodePtr);
		printf("%s", "\nDo you want to add another number? ");

		yesOrNo = validateYesNo();	
	} while (yesOrNo == 'y');

	//
	do
	{
		//Focusing on linked lists so not validating that a number was entered
		printf("%s", "\nEnter number in the  list to delete ");
		scanf("%d", &number);
		while ((getchar()) != '\n');

		//
		deleteNode(&headNodePtr, number);

		// why does insert node pass the address of head pointer but print list does not?
		printList(headNodePtr);

		printf("%s", "\nDo you want to delete another number? ");
		yesOrNo = validateYesNo();

	} while ((yesOrNo == 'y') && (headNodePtr !=NULL));

	//Free remaining memory
	freeRemainingNodes(&headNodePtr);
	printList(headNodePtr);
 
	return 0;
}

// 
void insertNode (Node **headPtr, int number)
{

	// Allocate memory for the new node in the heap
	Node *newNodePtr = malloc(sizeof(Node));

	// check to make pointer to memory location was successful
	if (newNodePtr != NULL)
	{
		//put data in new node by deferencing address
		newNodePtr->data = number;
		//intitialize the nextNodePtr to be NULL
		newNodePtr->nextNodePtr = NULL;

		// Figure out where new node belongs in linked list, create 2 pointers to help
		Node *previousPtr = NULL;
		//start iteration with the headPtr 
		Node *currentPtr = *headPtr;

		//Looking for where to put node in list
		// Loop while haven't reached end of list and 
		//current node's number <= number
		while (currentPtr != NULL && currentPtr->data <= number )
		{
			//go to next node
			//so current becomes previous 
			previousPtr = currentPtr;
			//current is not the next node in the list
			currentPtr = currentPtr->nextNodePtr;
		}

		// If the previous pointer is null that means it goes to head of the list
		if (previousPtr == NULL)
		{
			//inserting as 1st node set headPtr
			*headPtr = newNodePtr;
		}
		// currentPtr pointing to node AFTER insertion point
		else
		{
			//previous ptr needs to point to current node
			previousPtr->nextNodePtr = newNodePtr;
		}
	   
		// Connect new node into list
		newNodePtr->nextNodePtr = currentPtr;
	} 
	//null pointer from memory allocation
	else
	{
		printf ("No memory to create node for %d\n", number);
	}

} // insertNode


// Function receives the pointer to the first node of linked list
// and data to match in the linked list
// Need to use a double pointer **headPtr to receive the first node
//so the headPtr address can be updated in main if it needs to change
void deleteNode (Node **headPtr, int numberToDelete)
{
	// Figure out where node to delete is in linked list, 
	//create nodes to keep track of previous and current pointers
	Node *previousPtr = NULL;
	Node *currentPtr = *headPtr;

	// Check if there is any node in the list
	if (*headPtr != NULL)
	{
		if ((*headPtr)->data == numberToDelete)
		{
			//update headPtr to point to next node before deallocating memory
			*headPtr = (*headPtr)->nextNodePtr;
			// now can delete current node
			free(currentPtr);
			currentPtr = NULL;
		}
		else //not first node
		{
			//Loop through remaining nodes
			// While haven't reached end of list (NULL) and 
			//current node's number != numberToDelete
			while (currentPtr != NULL && currentPtr->data != numberToDelete)
			{
				// go to the next node
				previousPtr = currentPtr;
				currentPtr = currentPtr->nextNodePtr;
			}

			// if found node to delete 	
			if (currentPtr != NULL)
			{
				// previousPtr is pointing to node to be deleted 
				// Update to point to next node of node to be deleted
				previousPtr->nextNodePtr = currentPtr->nextNodePtr;
				//delete current node
				free(currentPtr);
				currentPtr = NULL;
			}
			//NULL, node is not in list!	
			else
			{
				puts("Node to delete not found!");
			}
		}
	}
	else // no nodes in the list
	{
		puts("There aren't any nodes in the list!");
	}
	
} //deleteNode


// Iterate through the list to print information from each node
//Pass the address where to start in the list
//No need to pass with double pointer since will not be updating the address
void printList (Node *listPtr)
{
	// Check if there are any values in the list
	if (listPtr != NULL)
	{
		printf ("%s","The list is: ");
		//set currentPtr to first node in list
		Node *currentPtr = listPtr;
		
		//loop through the list until the last node points to null
		while (currentPtr != NULL)
		{
			// display and go to next node
			printf ("%d --> ", currentPtr->data);
			currentPtr = currentPtr->nextNodePtr;
		}	
		puts("");
	}
	// linked list is empty
	else
	{
		puts ("List is empty");
	} 
} // printList


// Iterate through the list to delete any remaining nodes 
// before exiting the program
void freeRemainingNodes(Node **headPtr)
{
	Node *currentPtr = *headPtr;
	Node* nextNodePtr = NULL;

	while (currentPtr != NULL )
	{
		nextNodePtr = currentPtr->nextNodePtr;
		free(currentPtr);
		currentPtr = nextNodePtr;
	}

	*headPtr = NULL;
}

//validateYesNo and return a 'y' or 'n' char 
char validateYesNo() {
	char validYesNo; //Represents yes or no via a character. This will be returned.

	//Loop until the user enters a y or n 
	do {
		//Get character value
		puts("Please enter (y)es or (n)o:");
		validYesNo = getchar();

		//Clear the input buffer 
		while (getchar() != '\n');

		//tolower forces uppercases entries into lowercase to simplify cases.
		validYesNo = tolower(validYesNo);

	} while (validYesNo != 'y' && validYesNo != 'n');

	//return valid char
	return  validYesNo;
} //End validateYesNo


void linkingLists()
{
	//pointer to first node to headPtr
	struct node* headPtr = NULL;
	//pointer to next node
	struct node* nodePtr = NULL;


	//allocate memory for 1st node (heap)
	nodePtr = malloc(sizeof(struct node));
	// set up the  node if memory was allocated
	if (nodePtr != NULL)
	{
		//assign value to data member
		nodePtr->data = 2;
		// assign null to pointer to next pointer member
		nodePtr->nextNodePtr = NULL;
	}
	// Set the headPtr to point to this first node
	headPtr = nodePtr;

	printList(headPtr);

	// Allocate memory for another node in the heap
	nodePtr = malloc(sizeof(struct node));
	// set up second node
	if (nodePtr != NULL)
	{
		nodePtr->data = 4;
		nodePtr->nextNodePtr = NULL;
	}
	// Connect the two nodes
	headPtr->nextNodePtr = nodePtr;

	printList(headPtr);

	// Add third node to hold 6
	// Allocate memory for another node in the heap
	nodePtr = malloc(sizeof(struct node));
	// set up second node
	if (nodePtr != NULL)
	{
		nodePtr->data = 6;
		nodePtr->nextNodePtr = NULL;
	}
	// Connect the two nodes
	headPtr->nextNodePtr->nextNodePtr = nodePtr;

	printList(headPtr);



}

void exploreDoublePointers()
{
	int n = 20;
	int* nPtr = NULL;
	int** doublenPtr = NULL;

	puts("int n = 20;  \nint* nPtr = NULL;   \nint** doublenPtr = NULL; ");
	printf("&n = %p\n", &n);
	nPtr = &n;
	puts("Assign nPtr = &n;");
	printf("&nPtr = %p\n", &nPtr);
	printf("nPtr = %p\n", nPtr);
	printf("*nPtr = %d\n", *nPtr);
	doublenPtr = &nPtr;
	puts("Assign doublenPtr = &nPtr;");
	printf("Address &doublenPtr= %p\n", &doublenPtr);
	printf("Value stored at *doublenPtr= %p\n", *doublenPtr);
	printf("Value stored at *nPtr =  %d\n", *nPtr);
	printf("Value stored at **doublenPtr =  %d\n\n", **doublenPtr);


	int n2 = 40;
	printf("n2 = 40;  &n2 = %p\n", &n2);
	*doublenPtr = &n2;
	puts("Assign *doublenPtr = &n2;");
	printf("&doublenPtr= %p\n", &doublenPtr);
	printf("*doublenPtr= %p\n", *doublenPtr);
	printf("&nPtr = %p\n", &nPtr);
	printf("nPtr = %p\n", nPtr);
	printf("Value stored at pointer *nPtr =  %d\n", *nPtr);
	printf("Value stored at another pointer **doublenPtr =  %d\n", **doublenPtr);

}






