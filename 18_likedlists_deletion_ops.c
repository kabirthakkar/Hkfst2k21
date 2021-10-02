#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node *head){
    struct Node *p = head;
    while(p != NULL){
        printf("Element: %d\n", p -> data);
        p = p -> next;
    }
}

// Case 1 -> Deleting the first node
struct Node * deleteatFirst(struct Node * head){
    struct Node *p = head;
    head = head -> next;
    free(p);
    return head;
}

// Case 2 -> Deleting in between (the given index)
struct Node * deleteAtIndex(struct Node *head, int index){
    struct Node *p = head;
    int i = 0;
    while( i != index-1){
        p = p -> next;
        i++;
    }
    struct Node *q = p -> next;
    p -> next = q -> next;
    free(q);
    return head;
}

//Case 3 -> Deleting the end node
struct Node * deleteAtEnd(struct Node *head){
     struct Node * p = head;
     struct Node * q = p -> next;
     while (q -> next != NULL){
           p = p -> next;
           q = q -> next;
     }  
      p -> next = NULL;
      free(q);
      return head;
}

// Case 4 -> Delete the node at a given key/value
struct Node * DeleteAtgivenval(struct Node *head, int givenVal){
    struct Node *p = head;
    struct Node *q = p -> next;

    while(q -> data != givenVal && q-> next != NULL){
        q = q -> next;
        p = p -> next;
    }
    if(q -> data == givenVal){
    p -> next = q -> next;
    free(q);
    }
    return head;
}
int main(){
struct Node * head = (struct Node*)malloc(sizeof(struct Node));   
struct Node * first = (struct Node*)malloc(sizeof(struct Node));    
struct Node * second = (struct Node*)malloc(sizeof(struct Node));    
struct Node * third = (struct Node*)malloc(sizeof(struct Node));    
struct Node * fourth = (struct Node*)malloc(sizeof(struct Node));    
    
head -> data = 10;
head -> next = first;

first -> data = 20;
first -> next = second;

second -> data = 30;
second -> next = third;

third -> data = 40;
third -> next = fourth;

fourth -> data = 50;
fourth -> next = NULL;

printf("Before Deletion\n");
linkedListTraversal(head);
printf("************\n");

head = deleteatFirst(head);  //10
head = deleteAtIndex(head, 2);  //40
head = deleteAtEnd(head);    //50
head = DeleteAtgivenval(head,30); //30 
printf("After Deletion\n");
linkedListTraversal(head);
    return 0;
}


