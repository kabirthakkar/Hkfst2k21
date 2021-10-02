#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}node;

void linkedlistTraversal(node *p){
    while(p != NULL){
    printf("Element: %d\n", p-> data);
    p = p -> next;
    }
}

int main(){
    node* head = (struct Node*)malloc(sizeof (struct Node));
    node* first = (struct Node*)malloc(sizeof(struct Node));
    node* second = (struct Node*)malloc(sizeof(struct Node));
    node* third = (struct Node*)malloc(sizeof(struct Node));
    
    // int a,b,c,d;
    // printf("Enter the values of a: ,b: ,c: ,d: \n");
    // scanf("%d %d %d %d ",&a,&b,&c,&d);
    head->data = 11;
    head->next = first;

    first->data =22;
    first->next = second;

    second->data = 33;
    second->next = third;

    third->data = 44;
    third->next = NULL;

    linkedlistTraversal(head);
    return 0;
}
