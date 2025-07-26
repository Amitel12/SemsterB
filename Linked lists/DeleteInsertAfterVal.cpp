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
Node* append_list(Node* head1, Node* head2);
Node* reverse_list(Node* head);
void sort_list(Node* head);
void delete_duplicates(Node* head);
Node* insert_after(Node* head, int new_value, int after_value);
Node* delete_list(Node* node);
int main()
{
	Node* list1 = NULL;
	list1 = insert_at_tail(list1, 1);
	list1 = insert_at_tail(list1, 2);
	list1 = insert_at_tail(list1, 4);
	list1 = insert_at_tail(list1, 5);
	list1 = insert_at_tail(list1, 6);
	print_list(list1);
	list1 = insert_after(list1,3, 2);
	
	print_list(list1);
	//list1 = delete_list(list1);
}

Node* delete_list(Node* node)
{
	if (node != NULL)
	{
		delete_list(node->next);
		free(node);
	}
	return NULL;
}
Node* insert_after(Node* head, int new_value, int after_value)
{
	Node* new_node = (Node*)calloc(1, sizeof(Node));
	new_node->value = new_value;
	if (head == NULL) return new_node;
	else
	{
		Node* current = head;
		while (current->next != NULL)
		{
			if (current->value == after_value)
			{
				new_node->next = current->next;
				current->next = new_node;
				return head; //after only one occurrence
			}
			else current = current->next;
		}
		new_node->next = current->next; //tail case if no match is found
		current->next = new_node;
		return head;
	}
	
}

void delete_duplicates(Node* head)
{
	if (head == NULL) return;
	if (head->next == NULL) return;
	Node* current1, * current2, * duplicate;
	current1 = head;
	while (current1 != NULL && current1->next != NULL) // not at the tail
	{
		current2 = current1;
		while (current2->next != NULL)
		{
			if (current1->value == current2->next->value)
			{
				duplicate = current2->next;
				current2->next = current2->next->next;
				free(duplicate);
			}
			else current2 = current2->next;
		}

		current1 = current1->next;
	}
}

void sort_list(Node* head) // wish it wont be on the test >_<
{
	if (head == NULL) return;
	if (head->next == NULL) return;
	bool swapped = false;
	Node* end = NULL;
	while (end != head)
	{
		Node* curr = head;
		while (curr->next != end)
		{
			if (curr->value > curr->next->value)
			{
				int temp = curr->value;
				curr->value = curr->next->value;
				curr->next->value = temp;
			}
			curr = curr->next;
		}
		end = curr;
	}
}

Node* reverse_list(Node* head)
{
	if (head == NULL) return NULL;
	if (head->next == NULL) return head;
	Node* curr = head;
	Node* after = head->next;
	head->next = NULL;
	while (after != NULL)
	{
		Node* temp = after->next;
		after->next = curr;
		curr = after;
		after = temp;
	}
	return curr;
}

Node* append_list(Node* head1, Node* head2)
{
	if (head1 == NULL) return head2;
	Node* current = head1;
	while (current->next != NULL) current = current->next;
	current->next = head2;
	return head1;
}
Node* efficient_delete_match(Node* head, int delete_value, int* num_deleted)
{
	*num_deleted = 0;
	if (head == NULL)return NULL;
	Node* current, * temp, * new_head;
	current = head;
	while (current->value == delete_value)
	{
		temp = current;
		current = current->next;
		free(temp);
		*num_deleted += 1;
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
			*num_deleted += 1;
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