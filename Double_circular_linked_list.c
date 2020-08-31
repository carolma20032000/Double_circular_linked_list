/*====================================
double circular linked list
======================================*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* prev;
	struct node* next;
};
typedef struct node NODE;

NODE* create_node(int data) {
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
//	if (new_node == NULL) {
//		printf("Failed to create new_node! \n");
//		return NULL;
//	}
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->data = data;
	return new_node;
}

void insert_end(NODE** head, int data) {
	NODE *new_node = create_node(data);
	if (*head == NULL) {
		new_node->next = new_node;
		new_node->prev = new_node;
		*head = new_node;
		return;
	}
	NODE* last_node = (*head)->prev;
	last_node->next = new_node;
	new_node->prev = last_node;
	new_node->next = *head;
	return;
}

void display(NODE* head) {
	NODE* temp = head;
	while (temp->next != head) {
		printf("%d  ",temp->data);
		temp = temp->next;
	}
	printf("%d \n", temp->data);
	return;
}

void insert_head(NODE** head, int data) {
	NODE* new_node = create_node(data);
	NODE* last_node = (*head)->prev;
	if (*head == NULL) {
		new_node->next = new_node;
		new_node->prev = new_node;
		new_node->data = data;
		(*head) = new_node;
		return;
	}
	last_node->next = new_node;
	new_node->next = *head;
	(*head)->prev = new_node;
	new_node->prev = last_node;
	*head = new_node;
}

int main() {
	//create a double linked list first.
	int data;
	NODE* head = NULL;

	insert_end(&head, 5);
	display(head);

	insert_head(&head, 7);
	display(head);

	return 0;
}
