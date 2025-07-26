#include <stdio.h>  
#include <stdlib.h>  
#include <stdbool.h>

typedef struct node {
	int value;
	struct node* next;
}Node;

void print_list(Node* head);
Node* insert_at_head(Node* head, int new_value);
Node* insert_at_tail(Node* head, int new_value);
Node* delete_at_head(Node* head);
Node* delete_at_tail(Node* head);
int length(Node* head);
Node* Delete_Value(Node* head, int value);
void replace_matches(Node* head, int oldval, int newval);
Node* delete_first_match(Node* head, int delete_value, bool* was_deleted);


int main()
{
	Node* list1_head = NULL;
	list1_head = insert_at_head(list1_head, 7);
	list1_head = insert_at_head(list1_head, 5);
	list1_head = insert_at_head(list1_head, 5);
	list1_head = insert_at_tail(list1_head, 10);
	print_list(list1_head);
	//list1_head = delete_at_tail(list1_head);
	//print_list(list1_head);
	//printf("Length:%d \n",length(list1_head));
	//list1_head = Delete_Value(list1_head, 3);
	//replace_matches(list1_head, 5, 55);
	bool deleted;
	list1_head = delete_first_match(list1_head, 8, &deleted);
	print_list(list1_head);
	if (deleted)
	{
		printf("Deleted first node with 8\n");
	}
	else
	{
		printf("A node with value 8 was not deleted\n");
	}
	
}

Node* delete_first_match(Node* head, int delete_value, bool* was_deleted)
{
	if (head == NULL)
	{
		*was_deleted = false;
		return NULL;
	}
	if (head->value == delete_value)
	{
		Node* temp = head->next;
		free(head);
		*was_deleted = true;
		return temp;
	}
	Node* prev = head;
	Node* curr = head->next;
	
	while (curr != NULL)
	{
		if (curr->value == delete_value)
		{
			prev->next = curr->next;
			free(curr);
			*was_deleted = true;
			return head;
		}
		prev = curr;
		curr = curr->next;
	}
	*was_deleted = false;
	return head;
}

void replace_matches(Node* head, int oldval, int newval)
{
	Node* curr = NULL;
	curr = head;
	while (curr != NULL)
	{
		if (curr->value == oldval)
		{
			curr->value = newval;
		}
		curr = curr->next;
	}
}
Node* Delete_Value(Node* head, int value)
{
	Node* curr = NULL;
	Node* prev = NULL;
	prev = curr = head;
	if (head == NULL) return NULL;
	if (head->value == value) return head->next;
	while (curr != NULL)
	{

		if (curr->value == value)
		{
			prev->next = curr->next;
			free(curr);
			curr = prev;
		}

		prev = curr;
		curr = curr->next;
	}
	return head;
}
int length(Node* head)
{
	Node* curr = head;
	int length = 0;
	while (curr != NULL)
	{
		length++;
		curr = curr->next;
	}
	return length;
}
Node* delete_at_tail(Node* head)
{
	if (head == NULL) return NULL;
	else if (head->next == NULL)
	{
		free(head);
		return NULL;
	}
	else
	{
		Node* current = head;
		Node* prev = NULL;
		while (current->next != NULL)
		{
			prev = current;
			current = current->next;
		}
		prev->next = NULL;
		free(current);
		return head;
	}
}
Node* delete_at_head(Node* head)
{
	if (head == NULL) return NULL;
	else
	{
		Node* to_return = head->next;
		free(head);
		return to_return;
	}
}

Node* insert_at_tail(Node* head, int new_value)
{
	Node* new_node = (Node*)calloc(1, sizeof(Node));
	new_node->value = new_value;
	if (head == NULL) return new_node;
	else
	{
		Node* Curr = head;
		while (Curr->next != NULL)
		{
			Curr = Curr->next;
		}
		Curr->next = new_node;
		return head;
	}
}

Node* insert_at_head(Node* head, int new_value)
{
	Node* new_node = (Node*)calloc(1, sizeof(Node));
	new_node->value = new_value;
	if (head == NULL) return new_node;
	else
	{
		new_node->next = head;
		return new_node;
	}

}

void print_list(Node* head)
{
	Node* Curr = NULL;
	Curr = head;
	int i = 0;
	while (Curr != NULL)
	{
		printf("[%d][%d] -> ", i, Curr->value);
		Curr = Curr->next;
		i++;
	}
	printf("NULL\n");
}