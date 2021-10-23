

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
struct node {
  int key;
  struct node *left, *right;
};
static bool flag = false;
// struct node *root = NULL;
// Create a node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Inorder Traversal
void inorder(struct node *root) {
  if (root != NULL) {
    // Traverse left
    inorder(root->left);

    // Traverse root
    printf("%d -> ", root->key);

    // Traverse right
    inorder(root->right);
  }
}
//Preoder traversal
void preorder(struct node *root)
{if(root !=NULL){
    printf("%d ->",root->key);
    preorder(root->left);
    preorder(root->right);
}}
//post order traversal
void postorder(struct node *root)
{if(root !=NULL){
    
    postorder(root->left);
    postorder(root->right);
    printf("%d ->",root->key);
}}


// Insert a node
struct node *insert(struct node *node, int key) {
  // Return a new node if the tree is empty
  if (node == NULL) return newNode(key);

  // Traverse to the right place and insert the node
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

void searchNode(struct node *temp, int value){  
    //Check whether tree is empty  
    if(temp == NULL){  
        printf("Tree is empty\n");  
    }  
    else{  
        //If value is found in the given binary tree then, set the flag to true  
        if(temp->key == value){  
            flag = true;  
             return;  
        }  
        //Search in left subtree  
        if(flag == false && temp->left != NULL){  
        searchNode(temp->left, value);  
        }  
        //Search in right subtree  
        if(flag == false && temp->right != NULL){  
        searchNode(temp->right, value);  
        }  
    }  
}  
   

// Find the inorder successor
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  // Return if the tree is empty
  if (root == NULL) return root;

  // Find the node to be deleted
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    // If the node is with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // If the node has two children
    struct node *temp = minValueNode(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

// Driver code
int main() {

  struct node *root = NULL;
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);
 printf("before deleting 10 from the node\n");
  printf("Inorder traversal: ");
  inorder(root);
   printf("\nPreorder traversal: ");
  preorder(root);

  printf("\nPostorder traversal: ");
  postorder(root);
  printf("\nAfter deleting 10\n");
  root = deleteNode(root, 10);
  printf("Inorder traversal: ");
  inorder(root);

  printf("\nPreorder traversal: ");
  preorder(root);

  printf("\nPostorder traversal: ");
  postorder(root);
 

 printf("\nsearching for the element 5 .......");
 searchNode(root,5);  
      
    if(flag)  
        printf("\nElement is present in the binary tree");  
    else  
        printf("\nElement is not present in the binary tree");  
    return 0;  
}
