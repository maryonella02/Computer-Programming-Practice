#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int val;
	struct node * next;
}node_t;

void print_list(node_t * head){
	node_t * current = head;

	while (current != NULL){
		printf("%d\n", current->val);
		//merge la urmatorul element
		current = current->next;
	}
}

void pushend(node_t * head, int val){
	node_t * current = head;

	while (current->next != NULL){
		current = current->next;
	}

	current->next = malloc(sizeof(node_t));
	current->next->val = val;
	current->next->next = NULL;
}

void pushbeg(node_t ** head, int val){
	node_t * new_node;
	new_node = malloc(sizeof(node_t));
	new_node->val = val;
	new_node->next = *head;
	*head = new_node;
}

int pop(node_t ** head){
	int retval=-1;
	node_t * next_node = NULL;

	if (*head == NULL){
		return -1;
	}

	next_node = (*head)->next;
	retval = (*head)->val;
	free(*head);
	*head = next_node;

	return retval;
}

int remove_last(node_t * head){
	int retval = 0;
	 /* if there is only one item in the list, remove it */
	 if (head->next == NULL){
	 	retval = head->val;
	 	free(head);
	 	return retval;
	 }

	 /* get to the second to last node in the list */
	 node_t * current = head;
	 while (current->next->next != NULL){
	 	current = current->next;
	 }

	 /* now current points to the second to last item of the list, so let's remove current->next */
	 retval = current->next->val;
	 free(current->next);
	 current->next = NULL;
	 return retval;
}

int remove_by_index(node_t * head, int n){
	int i = 0;
	int retval = -1;
	node_t * current = head;
	node_t * temp_node = NULL;

	if (n == 0){
		pop(&head);
	}

	for (i=0; i<n-1; i++){
            //gaseste daca este valoare la acel index
		if (current->next == NULL){
			return -1;
		}
//forul itereaza pana ajunge la n
		current = current->next;
	}

	temp_node = current->next;
	retval = temp_node->val;
	current->next = temp_node->next;
	free(temp_node);

	return retval;
}

int remove_by_value(node_t ** head, int val) {
    node_t *previous, *current;

    if (*head == NULL) {
        return -1;
    }

    if ((*head)->val == val) {
        return pop(head);
    }

    previous = current = (*head)->next;
    while (current) {
        if (current->val == val) {
            previous->next = current->next;
            free(current);
            return val;
        }

        previous = current;
        current  = current->next;
    }
    return -1;
}

void searchvalue(node_t * head, int val){
	node_t * current = head;
	int k=0;
	while (current != NULL){
		if (current->val == val){
			k++;
		}
		current = current->next;
	}
	if (k>0){
		printf("The node is present\n");
	} else {
		printf ("The node is not present\n");
	}
}

int main(){

	int a, value;
	int key;
	node_t * head_list = NULL;
	head_list = malloc(sizeof(node_t));
	if (head_list == NULL){
		return 1;
	}

	head_list->val = 1;
	head_list->next = malloc(sizeof(node_t));
	head_list->next->val = 2;
	head_list->next->next = malloc(sizeof(node_t));
	head_list->next->next->val = 3;
	head_list->next->next->next = malloc(sizeof(node_t));
	head_list->next->next->next->val = 4;
	head_list->next->next->next->next = NULL;

	printf("Select the data structure:\n");
	printf("1.Queue\n2.Stack\n");
	int ds;
	scanf("%d",&ds);
	if (ds==1) goto queue;
	if (ds==2) goto stack;
	queue:
	repeatqueue:
	printf("*********************************************************\n");
	printf("Select the number of operation:\n");
	printf("1: add node\n");
	printf("2: search node\n");
	printf("3: view queue\n");
	printf("4: remove node from the queue\n");
	printf("*********************************************************\n");


	scanf("%d", &a);
	printf("\n");
	switch (a) {
		case 1:	printf("Enter the value\n");
				scanf("%d", &value);
				pushend(head_list, value);
				break;
		case 2: printf("Enter the value\n");
				scanf("%d", &value);
				searchvalue(head_list, value);
				break;
		case 3: print_list(head_list);
				break;
		case 4: pop(&head_list);
				break;
		default: break;
	}

	printf("Do you want to repeat?\n");
	printf("Press 1 if you want\nPress 0 if don't\n");

	scanf("%d", &key);

	if (key == 1){
		goto repeatqueue;
	} else if (key == 0){
		exit(EXIT_SUCCESS);
	}

	stack:
	repeatstack:
	printf("*********************************************************\n");
	printf("Select the number of operation:\n");
	printf("1: add node\n");
	printf("2: search node\n");
	printf("3: view stack\n");
	printf("4: remove node from the stack\n");
	printf("*********************************************************\n");

	scanf("%d", &a);
	printf("\n");
	switch (a) {
		case 1: printf("Enter the value\n");
				scanf("%d", &value);
				pushend(head_list, value);
				break;
		case 2: printf("Enter the value\n");
				scanf("%d", &value);
				searchvalue(head_list, value);
				break;
		case 3: print_list(head_list);
				break;
		case 4: remove_last(head_list);
				break;
		default: break;
	}

	printf("Do you want to repeat?\n");
	printf("Press 1 if you want\nPress 0 if don't\n");

	scanf("%d", &key);

	if (key == 1){
		goto repeatstack;
	} else if (key == 0){
		exit(EXIT_SUCCESS);
	}
	return 0;
}
