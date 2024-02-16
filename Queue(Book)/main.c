#include<stdio.h>
#include<stdlib.h>

struct queueNode
{
	char data;
	struct queueNode* nextPtr;
};

typedef struct queueNode QUEUENODE;
typedef QUEUENODE* QUEUENODEPTR;

void printQueue(QUEUENODEPTR);
int isEmpty(QUEUENODEPTR);
char dequeue(QUEUENODEPTR*, QUEUENODEPTR*);
void enqueue(QUEUENODEPTR*, QUEUENODEPTR*, char);


int main()
{
	QUEUENODEPTR headPtr = NULL, tailPtr = NULL;
	char item;

	enqueue(&headPtr, &tailPtr, 'A');
	enqueue(&headPtr, &tailPtr, 'B');
	enqueue(&headPtr, &tailPtr, 'C');
	enqueue(&headPtr, &tailPtr, 'D');

	printQueue(headPtr);

	dequeue(&headPtr, &tailPtr);
	printQueue(headPtr);
	dequeue(&headPtr, &tailPtr);
	printQueue(headPtr);
	dequeue(&headPtr, &tailPtr);
	printQueue(headPtr);
	dequeue(&headPtr, &tailPtr);
	printQueue(headPtr);


	return 0;
}

void enqueue(QUEUENODEPTR* headPtr, QUEUENODEPTR* tailPtr, char value)
{

	QUEUENODEPTR newPtr;
	newPtr = malloc(sizeof(QUEUENODE));

	if (newPtr != NULL)
	{
		newPtr->data = value;
		newPtr->nextPtr = NULL;

		if (isEmpty(*headPtr))
			*headPtr = newPtr;
		else
			(*tailPtr)->nextPtr = newPtr;
		*tailPtr = newPtr;

	}
	else
		printf("%c not inserted. No memory available.\n", value);

}

char dequeue(QUEUENODEPTR* headPtr, QUEUENODEPTR* tailPtr)
{
	char value;
	QUEUENODEPTR tempPtr;

	value = (*headPtr)->data;
	tempPtr = *headPtr;
	*headPtr = (*headPtr)->nextPtr;

	if (*headPtr == NULL)
		*tailPtr = NULL;

	free(tempPtr);
	return value;
}

void printQueue(QUEUENODEPTR currentPtr)
{
	if (currentPtr == NULL)
		printf("Queue is empty.\n");
	else
	{
		printf("The queue is ;\n");

		while (currentPtr != NULL)
		{
			printf("%c --> ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}

		printf("NULL\n");
	}
	
}

int isEmpty(QUEUENODEPTR headPtr)
{
	return headPtr == NULL;
}