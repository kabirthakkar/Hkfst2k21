#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

// Case 1 Insertion  in the beginning   -> O(1)
struct Node* insertAtFirst(struct Node *head, int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr -> data = data;
    ptr -> next = head;
    return ptr;
}

// Case 2 Insertion in between -> O(n)
struct Node* insertAtIndex(struct Node *head, int data, int index){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while(i != index-1){
        p = p -> next;
        i++;
    }
      ptr -> next = p -> next;
      p -> next = ptr;
      ptr -> data = data;
    return head;
}

// Case 3 Insertion at the end -> O(n)
struct Node* insertAtEnd(struct Node *head, int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr -> data = data;
    struct Node *p = head;
    while(p -> next != NULL){
         p = p -> next;
    }
    p -> next = ptr;
    
    ptr -> next = NULL;
    return head;
}

// Case 4 Insertion after a given node -> O(1)
struct Node* insertAfterNode(struct Node *head, struct Node *prevNode, int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    
    ptr->next = prevNode-> next;
    
    prevNode -> next = ptr;
    return head;
}


void linkedlistTraversal(struct Node* ptr){
    while(ptr != NULL){
        printf("Element: %d\n", ptr->data);
        ptr =  ptr -> next;
    }
}
int main(){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* first = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    
    head->data = 7;
    head->next = first;

    first->data = 11;
    first->next = second;

    second->data = 41;
    second->next = third;

    third->data = 66;
    third->next = NULL;
    
    printf("Before insertion\n");
    linkedlistTraversal(head);
    //head = insertAtFirst(head, 3);
    //head = insertAtIndex(head, 25, 2);
    //head = insertAtEnd(head, 78);
    head = insertAfterNode(head, second, 55);
    printf("After insertion\n");
    linkedlistTraversal(head);
    return 0;
}
