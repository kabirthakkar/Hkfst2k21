#include<stdio.h>
#include<stdlib.h>


struct Node{
	int data ;
	struct Node *next;
};

struct Node *head ;
void insertAtBeg(int value){
	struct Node *newNode;
	newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode -> data = value;
	if(head == NULL){
		newNode ->next = NULL;
		head = newNode;
	}
	else{
		newNode -> next = head;
		head = newNode;
	}
	printf("\n Node inserted successfully!!");
}

void insertAtEnd(int value){
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode -> data = value;
	newNode -> next = NULL;
	if(head ==  NULL){
		
		head = newNode;
	}
	else{
		struct Node *temp = head;
		while(temp->next != NULL){
			temp = temp ->next;
			
		}
		temp ->next = newNode; 
	}
}

void insertAtPos(){
	int i,value,loc;
	struct Node *newNode;
	
	newNode = (struct Node*)malloc(sizeof(struct Node));
	
	if(head ==NULL){
		newNode ->next = NULL;
		head = newNode;
	}
	else{
		printf("Enter element value: ");
		scanf("%d",&value);
		newNode ->data = value;
		struct Node *temp = head;
		printf("\nEnter position: ");
		scanf("%d",&loc);
		
		for(i=0; i < loc-1 ;i++){
			temp = temp->next;
		}
		newNode ->next = temp ->next;
		temp -> next = newNode;
	}
}

void deleteAtBeg(){
	if(head == NULL){
		printf("\nList is already empty");
		
	}
	else{
		struct Node *temp = head;
		if(head->next == NULL){
			head = NULL;
			free(temp);
		}
		else{
			head = temp ->next;
			free(temp);
			printf("\nNode deleted successfully!!");
		}
	}
}

void display(){
	struct Node *temp;
	temp = head;
	while(temp != NULL){
		printf("%d\t",temp->data);
		temp = temp ->next;
		
		
	}
	
}
int main(){
	int value ,c;
	while(c !=0){
	printf("\nChoose an option : press 0 for insert more \n1.insert at begininig \n2.insert at end \n3.Insert at Any Position \n4.Delete from begining. \n7.display");
	printf("\nEnter your choice: ");
	scanf("%d",&c);

	switch(c){
		case 1:
		printf("|Enter a item to insert: ");
		scanf("%d",&value);
		insertAtBeg(value);
		break;
		case 2:
		printf("|Enter a item to insert: ");
		scanf("%d",&value);
		insertAtEnd(value);
		break;
		case 3: 
		
		insertAtPos();
		
		break;
		case 4:
			deleteAtBeg();
			break;
		case 7:display();
		break;
		default:exit(1);
	}
}
	
}
