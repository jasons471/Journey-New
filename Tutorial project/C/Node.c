#include <stdio.h> 
#include <stdlib.h> 
#include<stdbool.h> 
struct node{ 
int data; 
struct node *left; 
struct node *right; 
}; 
struct node *createNode(int n){ 
struct node *newNode = malloc(sizeof(struct node)); 
newNode->data=n; 
newNode->left = NULL; 
newNode->right = NULL; 
return newNode; 
} 
struct node *insert(struct node *root, int value){ 
if(root == NULL){ 
return createNode(value); 
} 
else if(root->data<value){ 
root->right=insert(root->right, value); 
} 
else{ 
root->left = insert(root->left, value); 
} 
return root; 
} 
void inOrder(struct node *root){ 
if(root==NULL){ 
return; 
} 
inOrder(root->left); 
printf("%d ", root->data); 
inOrder(root->right); 
} 
bool search(struct node *root, int searchingValue){ 
bool found = false; 
if(root==NULL){  
 
        return false; 
       } 
       else if(root->data==searchingValue){ 
         return true; 
       } 
       else if(root->data<searchingValue){ 
        found = search(root->right, searchingValue); 
       } 
       else{ 
        found = search(root->left, searchingValue); 
       } 
 
       return found; 
} 
 
struct node *minValueNode(struct node *root) { 
  struct node *tmp = root; 
  while (tmp->left != NULL) 
    tmp = tmp->left; 
 
  return tmp; 
} 
 
struct node *deleteNode(struct node *root, int key) { 
   if (root == NULL) 
      return root; 
   if (key < root->data) 
      root->left = deleteNode(root->left, key); 
   else if (key > root->data) 
      root->right = deleteNode(root->right, key); 
 
   else { 
         if (root->left == NULL) { 
         struct node *temp = root->right; 
         free(root); 
         return temp; 
    } else if (root->right == NULL) { 
        struct node *temp = root->left; 
        free(root); 
        return temp; 
    } 
    struct node *temp = minValueNode(root->right); 
    root->data = temp->data; 
    root->right = deleteNode(root->right, temp->data); 
  } 
  return root; 
} 
int main() 
{ 
struct node *root = NULL; 
root = insert(root, 50); 
root = insert(root, 30); 
root = insert(root, 20); 
root = insert(root, 60); 
root = insert(root, 55); 
root = insert(root, 65); 
printf("Inorder traversal: "); 
inOrder(root); 
printf("\nAfter deleting:60 \n"); 
root = deleteNode(root, 60); 
printf("Inorder traversal: "); 
inOrder(root); 
int node = search(root, 30); 
if(node == 0){ 
printf("\nValue is not found in BST\n"); 
} else{ 
printf("\nValue is found in BST\n"); 
} 
return 0; 
}