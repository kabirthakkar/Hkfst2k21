#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTree
{
    int data, count;
    struct BinaryTree *left, *right;
} BinaryTree;

BinaryTree *getNewNode(const int value)
{
    BinaryTree *temp = (BinaryTree *)malloc(sizeof(BinaryTree));

    if (!temp) // in case memory allocation failed
    {
        printf("Error : memory allocation failed\n");
        return NULL;
    }

    temp->data = value;
    temp->count = 1;
    temp->left = temp->right = NULL;
    return temp;
}

const int userInput(const char *msg)
{
    if (msg) // if any message is provided
        printf("%s : ", msg);
    else
        printf("Enter data : ");

    int input = 0;
    scanf("%d", &input);
    return input;
}

BinaryTree *getNewTree(BinaryTree *obj, const int value)
{
    BinaryTree *temp = obj;
    if (!obj) // if no pre-existing tree isntance is passed
        obj = getNewNode(value);
    else if (obj->data == value)    // is similar value is found
        ++obj->count;
    else if (value < obj->data)     // given value is smaller than current node
        obj->left = getNewTree(obj->left, value);
    else    // given value is greater than current node
        obj->right = getNewTree(obj->right, value);
    
    return obj;
}

void preOrder(BinaryTree *obj)
{
    printf("%d ", obj->data);
    if (obj->left)
        preOrder(obj->left);
    if (obj->right)
        preOrder(obj->right);
}

int main()
{
    BinaryTree *one = NULL;
    one = getNewTree(one, 10);
    one = getNewTree(one, 20);
    one = getNewTree(one, 5);
    one = getNewTree(one, 7);
    one = getNewTree(one, 3);
    one = getNewTree(one, 15);

    preOrder(one);

    return 0;
}
