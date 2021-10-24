#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *start = NULL;

struct node *create(struct node *start){
	int n;
	struct node * new_node = (struct node *)malloc(sizeof(struct node));
	printf("enter value  : ");
	scanf("%d",&n);
	new_node->data =n;
	new_node->next =start;
	start=new_node;
	return start;
}


struct node *ins_end(struct node* start){
	int n;
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	struct node *ptr;
	printf("enter value: ");
	scanf("%d",&n);
	new_node->data =n;
	new_node->next =NULL;
	ptr = start;
	while(ptr->next !=NULL){
		ptr =ptr->next;
	}
	ptr->next= new_node;
	return start;
}

struct node *rev(struct node*start){

struct node *ptr,*preptr=NULL,*temp;
	ptr=start;
	while(ptr!=NULL){
		temp=ptr->next;
		ptr->next=preptr;
		preptr =ptr;
		ptr=temp;
    }
	start= preptr;
 	return start;
}


void display(struct node *start){
	struct node *temp;
	if(start == NULL)
		printf("the linked list doesn't exists. ");
	else{
		temp = start;
		while(temp != NULL){
			printf("  %d",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}




int main(){
	int ch;
	while(1){
		printf("1.   Create .\n");
		printf("2.   Insert at end.\n");
		printf("3.   reverse the entered link list.\n");
		printf("4.   Display .\n");
		printf("5.   Exit .\n");
		printf(" Enter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				start = create(start);
				break;
			case 2:
				start = ins_end(start);
				break;
			case 3:
				start = rev(start);
				break;
			case 4:
				display(start);
				break;
			case 5:
				exit(0);
				break;
			default:
				printf(" wrong choice . \n");
		}
	}
	return 0;
}
