#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int counter = 0;
	struct node *ptr = head;
	while(ptr != NULL){
		ptr = ptr->next;
		counter ++;
	}
	return counter;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
    int len = length(head);
    struct node* temp = head;
    char *storage = malloc((len + 1)*sizeof(char));
    if(storage == NULL){
        return NULL;
    }
    int i = 0;
    while(temp != NULL){
        storage[i++] = temp->letter;
        temp = temp->next;
    }
    storage[i] = '\0';
    return storage;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
    struct node* newNode = malloc(sizeof(node));
    if (newNode == NULL) {
        return;
    }
    newNode->letter = c;
    newNode->next = NULL;
    if(*pHead == NULL){
        *pHead = newNode;
        return;
    }

    struct node* current = *pHead;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
    struct node *temp = *pHead;
    
    while(temp->next != NULL){
        struct node *current = temp;
        temp = temp->next;
        free(current);
    }
    *pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}