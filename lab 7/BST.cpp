#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if(root == NULL){
    return;
  }
  traverseInOrder(root -> left);
  printf("%d ", root->key);
  traverseInOrder(root -> right);
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
  if(node == NULL){
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
  }

  if(key < node->key){
    node->left = insertNode(node->left, key);
  }else if(key > node->key){
    node->right = insertNode(node->right, key);
  }

  return node;
}

//for get minimum value node
struct node* minValueNode(struct node* node)
{
    struct node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if(root == NULL){
    return root;
  }

  if(key < root->key){
    root->left = deleteNode(root->left, key);
  }else if(key > root->key){
    root->right = deleteNode(root->right, key);
  }else{
    if(root->left == NULL and root->right == NULL){
      return NULL;
    }else if(root->left == NULL){
        struct node* temp = root->right;
        free(root);
        return temp;
    }else if(root->right == NULL){
        struct node* temp  = root->right;
        free(root);
        return temp;
    }else{

      struct node* temp = minValueNode(root->right);
      root->key = temp->key;
      root->right = deleteNode(root->right, temp->key);

    }
  }
  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}
