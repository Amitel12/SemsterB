#include <stdio.h>

typedef struct node {
	int value;
	struct node* next;
}Node;

void print_list(Node* head);

int main()
{
	Node a,b,c;
	a.value = 5;
	b.value = 6;
	c.value = 7;
	a.next = &b;
	b.next = &c;
	c.next = NULL;
	print_list(&a);

}
void print_list(Node* head)
{
	Node* Curr = NULL;
	Curr = head;
	int i = 0;
	while (Curr != NULL)
	{
		printf("[%d][%d] -> ",i, Curr->value);
		Curr = Curr->next;
		i++;
	}
	printf("NULL");
}