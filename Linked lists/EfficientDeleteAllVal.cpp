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
Node* efficient_delete_match(Node* head, int delete_value, int* num_deleted);


int main()
{
	Node* list1 = NULL;
	list1 = insert_at_tail(list1, 3);
	list1 = insert_at_tail(list1, 3);
	list1 = insert_at_tail(list1, 4);
	list1 = insert_at_tail(list1, 3);
	list1 = insert_at_tail(list1, 4);
	list1 = insert_at_tail(list1, 5);
	list1 = insert_at_tail(list1, 4);
	print_list(list1);
	int deleted= 0;
	efficient_delete_match(list1, 4, &deleted);
	print_list(list1);
	printf("Deleted 4 %d times", deleted);
	

}

Node* efficient_delete_match(Node* head, int delete_value, int* num_deleted)
{
	*num_deleted = 0;
	if (head == NULL)return NULL;
	Node* current, * temp,*new_head;
	current = head;
	while (current->value == delete_value)
	{
		temp = current;
		current = current->next;
		free(temp);
		*num_deleted+=1;
		if (current == NULL) return NULL;
	}
	new_head = current;
	while (current->next != NULL)
	{
		if (current->next->value == delete_value)
		{
			temp = current->next;
			current->next = current->next->next;
			free(temp);
			*num_deleted+=1;
		}
		else current = current->next;
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