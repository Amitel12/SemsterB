#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char data; 
	struct node* next;
} Node;
Node* createNode(char c) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = c;
	newNode->next = NULL;
	return newNode;
}
Node* buildExample()
{
	char sentence[]{ ' ', ' ', ' ', 'N', 'o', ' ', ' ', ' ', 'w', 'a', 'y', '!', ' ', ' '};
	int n = sizeof(sentence) / sizeof(sentence[0]);
	Node* head = NULL;
	Node* tail = NULL;
	for (int i = 0; i < n; i++)
	{
		Node* newNode = createNode(sentence[i]);
		if (head == NULL)
		{
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}
	return head;
}
void removeExtraSpaces(Node** head);
void printlist(Node* head);
int main()
{
	Node* head = buildExample();
	printf("Before:\n");
	printlist(head);
	removeExtraSpaces(&head);
	printf("After:\n");
	printlist(head);

	Node* temp;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	return 0;
	
}

void removeExtraSpaces(Node** head)
{
	//remove sapces before sentence
	Node* curr = NULL;
	while ((*head) != NULL && (*head)->data == ' ')
	{
		curr = (*head)->next;
		free(*head);
		*head = curr;
	}
	if (*head == NULL)
	{
		return;
	}
	Node* prev = NULL;
	Node* letter = NULL;
	curr = *head;
	prev = *head;
	while (curr != NULL)
	{
		
		if (curr->data == ' ' && prev->data == ' ')
		{
			prev->next = curr->next;
			free(curr);
			curr = prev;
		}
		if (curr->data != ' ')
		{
			letter = curr;
		}
		prev = curr;
		curr = curr->next;
	}
	if (prev->data == ' ')
	{
		free(prev);
		letter->next = NULL;
	}
}
void printlist(Node* head)
{
	while (head != NULL)
	{
		printf(" '%c'-> ", head->data);
		head = head->next;
	}
	printf("NULL\n");
}