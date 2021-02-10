#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node* next;
} node_t;

//typedef struct node node_t;

void printlist(node_t *head){
	node_t *temporary = head;

	while(temporary != NULL){
		printf("%d\n", temporary->value);
		temporary = temporary->next;
	}
	printf("\n");
}

node_t * create_new_node(int value){
	node_t *result = malloc(sizeof(node_t));
	result->value = value;
	result->next = NULL;
	return result;
}

node_t* insert_at_head(node_t **head, node_t* node_to_insert){
	node_to_insert->next = *head;
	*head = node_to_insert;
	return node_to_insert;
}

void *insert_node_after(node_t* node_to_insert_after, node_t* newnode){
	newnode->next = node_to_insert_after->next;
	node_to_insert_after->next = newnode;
}

void *find_node(node_t* head, int value){
	node_t *tmp = head;
	while(tmp != NULL){
		if(tmp->value == value) return tmp;
		tmp = tmp->next;
	}
		return NULL;
}

int main(int argc, char **argv){
	node_t *tmp;
	node_t *head = NULL;

	for(int i = 0; i < 24; i ++){
		tmp = create_new_node(i);
		/*
		tmp->next = head;
		head = tmp;
		*/
		insert_at_head(&head, tmp);
	}

	tmp = find_node(head, 13);
	printf("Found node number: %d\n", tmp->value);

	insert_node_after(tmp, create_new_node(66));

/*  Lesson 2
	node_t *head;
	node_t *tmp;

	tmp = create_new_node(32);
	head = tmp;
	tmp = create_new_node(8);
	tmp->next = head;
	head = tmp;
	tmp = create_new_node(34);
	tmp->next = head;
	head = tmp;
*/
/*
	Lesson 1
	node_t *head, n1, n2, n3;
	//node_t *head;

	n1.value = 45;
	n2.value = 8;
	n3.value = 32;

	head = &n1;
	n3.next = NULL;
	//n2.next = &n4;
	n1.next = &n2;

	node_t n4;
	n4.value = 13;
	n4.next = &n3;
	n2.next = &n4;

	//moves the head pointer down one before print
	head = head->next;
*/
	printlist(head);

	return 0; 
}