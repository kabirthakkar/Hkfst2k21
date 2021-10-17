#include <stdio.h>
#include <stdlib.h>

// STRUCTURE OF NODE
typedef struct Node node;
struct Node {
	int data;
	node* next;
};

// ASSIGN HEAD TO NULL
node* head = NULL;

// ALLOCATE MEMORY AND INSERT DATA
node* create_node(int data) {
	node* newNode = (node*) malloc(sizeof(node));
	if (!newNode) {
		return NULL;
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

// INSERTION AT BEGINNING
void sll_push(int data) {
	node* newNode = create_node(data);
	newNode->next = head;
	head = newNode;
}

// INSERTION AT LAST
void sll_append(int data) {

	node* temp = head;
	if (head == NULL) {
		sll_push(data);
		return;
	}
	while(temp->next != NULL) {
		temp = temp->next;
	}
	node* newNode = create_node(data);
	temp->next = newNode;
	return;
}

// INSERTION AT POSITION(INDEX)
void sll_pushAt(int data, int index) {
	node* temp = head;
	if (index <= 0) {
		printf("Enter correct position\n");
		return;
	}
	if (index == 1) {
		// if satisfies ## conditions
		sll_push(data);
	}
//	# it is giving seg fault when list have 2 node and i enter position 5
	else if (index > 1) {
		if (head == NULL) {
			sll_append(data);
		}
		else {
			node* newNode = create_node(data);
			node* temp = head;
			for(int i = 1; i < index-1; i++) {
				if(temp != NULL) {
					temp = temp->next;
				}
			}
			if(temp == NULL) {
				printf("Give index less than nodes present\n");
				return;
			}
			newNode->next = temp->next;
			temp->next = newNode;
			return;
		}
	}
}

// REMOVE FROM HEAD
void sll_remove() {
	if (head == NULL) {
		return;
	}
	node* temp = head;
	head = head->next;
	free(temp);
	return;
}

// REMOVE FROM LAST
void sll_pop() {
	if (head == NULL) {
		return;
	}
	else if (head->next == NULL) {
		free(head);
		return;
	}
	node* temp = head;
	while(temp->next->next != NULL) {
		temp = temp->next;
	}
	free(temp->next);
	temp->next = NULL;
}

// REMOVE THE FIRST OCCURANCE OF DATA
void sll_delete(int data) {
	if (head == NULL) {
		return;
	}
	node* temp = head;
	node* temp1 = NULL;
	while(temp->next != NULL) {
		if(temp->next->data == data) {
			temp1 = temp->next->next;
			free(temp->next);
			temp->next = temp1;
			break;
		}
		else {
			temp = temp->next;
		}
	}
}

// DELETE NODE FROM PARTICULAR POSITION
void sll_deleteAt(int index) {
	// VALIDATE LIST
	if(head == NULL) {
		return;
	}
	if (index <= 1) {
		sll_remove();
	}
	else {
		node* temp = head;
		node* temp1 = NULL;
		for(int i = 1; i <= index - 1; i++) {
			if (temp->next == NULL) {
				return;
			}
			temp = temp->next;
		}
		temp1 = temp->next->next;
		free(temp->next);
		temp->next = temp1->next;
		return;
	}
}


// GET INDEX OF PARTICULAR VALUE
void sll_find(int data) {
	node* temp = head;
	int count = 1;
	while(temp != NULL) {
		if (temp->data == data) {
			printf("The index is: %d", count);
			return;
		}
		temp = temp->next;
		count++;
	}
	printf("Not found\n");
}
		


// UPDATE THE LIST
/* GET THE INDEX AND VALUE FOR REPLACEMENT*/
void sll_update(int data, int index) {
	// get the index from sll_find and update it here.
	node* temp = head;
	for(int i = 1; i < index - 1 && temp != NULL; i++) {
		temp = temp->next;
	}
	temp->data = data;
	return;
}

// PRINT LIST
void sll_print() {
	if (head == NULL) {
		printf("Empty list!!!\n");
	}
	node* tmp = head;
	printf("\nIn SLL print \n");
	while(tmp != NULL) {
		printf("%d\t", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}

// REVERSING THE LIST
void sll_reverse() {
	node* next;
	
	node* curr = head;
	node* container = NULL;
	
	while(curr != NULL) {
		next = curr->next;
		curr->next = container;
		container = curr;
		curr = next;
	}
	head = container;
}

// FREE ALLOCATED MEMORY
void free_memory() {
	node* tmp = head;
	while(tmp != NULL) {
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

// COUNT THE NODES IN THE LIST
void sll_count() {
	node* temp = head;
	int count = 1;
	while(temp != NULL) {
		temp = temp->next;
		count++;
	}
	printf("%d nodes are present in the list\n", count);
}

// SORT THE LIST
void sort() {
	// check for empty list. 
	if (head == NULL) {
		printf("try inserting elements before using sort\n");
		return;
	}
	node* end = NULL;
	node* temp2 = NULL;
	for(end = NULL; end != head->next; end = temp2) {
		for(node* temp = head; temp->next != end; temp = temp->next) {
			temp2 = temp->next;
			if (temp->data > temp2->data) {
				int tmp = temp->data;
				temp->data = temp2->data;
				temp2->data = tmp;
			}
		}
	}
	printf("The sorted elements are: \n");
	sll_print();
}

void insort(int data) {
	printf("The list should be sorted before this operation.\
otherwise the resultant list will be errorful\n");
	
	node* temp = head;
	node* newNode = create_node(data);

	while(temp->next != NULL && temp->next->data < data) {
		temp = temp->next;
	}

	node* temp2 = temp->next;
	temp->next = newNode;
	newNode->next = temp2;
	
	sll_print();
}

void insert_at_mid(int data) {
	
	if (head == NULL) {
		sll_push(data);
	}
	else if(head->next == NULL) {
		sll_append(data);
	}
	else {
		node* fastptr = head;
		node* slowptr = head;

		while(fastptr != NULL && fastptr->next != NULL) {
			fastptr = fastptr->next->next;
			slowptr = slowptr->next;
		}

		// if nodes are even
		if(fastptr == NULL) {
			// modify slowptr data and add a newnode of same data next to it.
			int temp_data = slowptr->data;
			slowptr->data = data;
			// make newNode and insert next to slow ptr.
			node* temp = slowptr->next;
			node* newNode = create_node(temp_data);
			slowptr->next = newNode;
			newNode->next = temp;
		}
		else {
			node* temp = slowptr->next;
			node* newNode = create_node(data);
			slowptr->next = newNode;
			newNode->next = temp;
		}
	}
}

// PRINT THE NODE OF MID POSITION
void print_mid() {
	if(head == NULL) {
		printf("Nothing in the list\n");
	}
	else if (head->next == NULL) {
		printf("%d is at position: %d\n", head->data, 1);
	}
	else {
		node* slowptr = head;
		node* fastptr = head;
		int counter = 1;
		int pre_data;
		while(fastptr != NULL && fastptr->next != NULL) {
			fastptr = fastptr->next->next;
			pre_data = slowptr->data;
			slowptr = slowptr->next;
			counter++;
		}
		if(fastptr == NULL) {
			printf("%d and %d are  at position: %d, %d\n", pre_data, slowptr->data, counter-1, counter);
		}
		else {
			printf("%d at position: %d\n", slowptr->data, counter);
		}
	}
}

int main() {
	
	while(1) {
		int n;
		printf("\nLinked list operations: \n");
		printf("1. push\t\t\t\t2. Append\t\t\t3. Push_At\n");
		printf("4. remove\t\t\t5. pop\t\t\t\t6. delete\n");
		printf("7. deleteAt\t\t\t8. find\t\t\t\t9. update\n");
		printf("10. print\n");
		printf("11. reverse\t\t\t12. free\t\t\t13. sort\n");
		printf("14: insort\t\t\t15: insert_mid\t\t\t16: print_mid\n");
		printf("17. Count nodes\n");
		printf("Enter operation: ");
		scanf("%d", &n);
		
		switch(n) {
			case 1:
			{
				int num;
				printf("Enter data: ");
				scanf("%d", &num);
				sll_push(num);
				break;
			}
			case 2:
			{
				int num;
				printf("Enter number: ");
				scanf("%d", &num);
				sll_append(num);
				break;
			}
			case 3:
			{
				int num, index;
				printf("Enter index: ");
				scanf("%d", &index);
				printf("Enter data: ");
				scanf("%d", &num);
				sll_pushAt(num, index);
				break;
			}
			case 4:
			{
				sll_remove();
				break;
			}
			case 5:
			{
				sll_pop();
				break;
				
			}
			case 6:
			{
				int data;
				printf("Enter number: ");
				scanf("%d", &data);
				sll_delete(data);
				break;
			}
			case 7:
			{
				int index;
				printf("Enter index: ");
				scanf("%d", &index);
				sll_deleteAt(index);
				break;
			}
			case 8:
			{
				int data;
				printf("Enter number: ");
				scanf("%d", &data);
				sll_find(data);
				break;
			}
			case 9:
			{
				int num, index;
				printf("Enter index: ");
				scanf("%d", &index);
				printf("Enter data: ");
				scanf("%d", &num);
				sll_update(num, index);
				break;
			}
			case 10:
			{
				sll_print();
				break;
			}
			case 11:
			{
				sll_reverse();
				break;
			}
			case 12:
			{
				free_memory();
				break;
			}
			case 13:
			{
				sort();
				break;
			}
			case 14:
			{
				int data;
				printf("Enter data: ");
				scanf("%d", &data);
				insort(data);
				break;
			}
			case 15:
			{
				int data;
				printf("Enter data to insert at mid: ");
				scanf("%d", &data);
				insert_at_mid(data);
				break;
			}
			case 16:
			{
				print_mid();
				break;
			}
			case 17:
			{
				sll_count();
			}
			default:
			{
				free_memory();
				sll_print();
				return 0;
			}
		}
	}
	return 0;
}
