#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct treeNode
{
	struct treeNode* leftPtr;
	struct treeNode* rightPtr;
	int data;
};

typedef struct treeNode TREENODE;
typedef TREENODE* TREENODEPTR;

void insertNode(TREENODEPTR*, int);
void inOrder(TREENODEPTR);
void preOrder(TREENODEPTR);
void postOrder(TREENODEPTR);

int main()
{
	int i, item;
	TREENODEPTR rootPtr = NULL;

	srand(time(NULL));

	printf("The numbers being placed in the tree are:\n");

	insertNode(&rootPtr, 27);
	insertNode(&rootPtr, 13);
	insertNode(&rootPtr, 42);
	insertNode(&rootPtr, 6);
	insertNode(&rootPtr, 17);
	insertNode(&rootPtr, 33);
	insertNode(&rootPtr, 48);



	printf("\nThe preOrder traversal is:\n");
	preOrder(rootPtr);

	printf("\nThe inOrder traversal is:\n");
	inOrder(rootPtr);

	printf("\nThe postOrder traversal is:\n");
	postOrder(rootPtr);


	return 0;
}

void insertNode(TREENODEPTR* treePtr, int value)
{
	if (*treePtr == NULL)
	{
		*treePtr = malloc(sizeof(TREENODE));

		if (*treePtr != NULL)
		{
			(*treePtr)->data = value;
			(*treePtr)->leftPtr = NULL;
			(*treePtr)->rightPtr = NULL;

		}
		else
			printf("%d not insertrd. No memory available.\n", value);

	}
	else
		if (value < (*treePtr)->data)
			insertNode(&((*treePtr)->leftPtr), value);
		else
			if (value > (*treePtr)->data)
				insertNode(&((*treePtr)->rightPtr), value);
			else
				printf("dup");

}

void inOrder(TREENODEPTR treePtr)
{
	if (treePtr != NULL)
	{
		inOrder(treePtr->leftPtr);
		printf("%3d", treePtr->data);
		inOrder(treePtr->rightPtr);
	}
}

void preOrder(TREENODEPTR treePtr)
{
	if (treePtr != NULL)
	{
		printf("%3d", treePtr->data);
		preOrder(treePtr->leftPtr);
		preOrder(treePtr->rightPtr);
	}
}

void postOrder(TREENODEPTR treePtr)
{
	if (treePtr != NULL)
	{
		postOrder(treePtr->leftPtr);
		postOrder(treePtr->rightPtr);
		printf("%3d", treePtr->data);
	}
}