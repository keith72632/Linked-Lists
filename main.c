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

int main(int argc, char **argv){
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

	printlist(head);

	return 0; 
}