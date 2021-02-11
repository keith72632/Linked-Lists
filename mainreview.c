#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node *next;
} node_t;

void* printlist(node_t *head)
{
	node_t *temp = head;
	while(temp->next != NULL){
		printf("%d", temp->value);
		temp = temp->next;
	}
	printf("%d\n", temp->value);
}

node_t* create_node(int value)
{
	node_t *temp = malloc(sizeof(node_t));
	temp->value = value;
	temp->next = NULL;
	return temp;
}

void* insert_node_at_head(node_t **head, node_t *node_to_insert)
{
	node_to_insert->next = *head;
	*head = node_to_insert;
	return node_to_insert;
}

int main()
{
	node_t *head = malloc(sizeof(node_t));
	node_t *temp = malloc(sizeof(node_t));
	node_t *newNode = malloc(sizeof(node_t));
	/*
	node_t *head;
	node_t n1, n2, n3, n4;

	n1.value = 33;
	n2.value = 66;
	n3.value = 99;
	n4 = create_node(122);

	head = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	*/

	for(int i = 1; i < 10; i++){
		if(i != 10){
			temp = create_node(i);
			temp->next = head;
			head = temp;	
		} else {
			temp->next = NULL;
		}
		
	}
	newNode = create_node(55);
	insert_node_at_head(&head, newNode);
	
	printlist(head);

	return 0;

}