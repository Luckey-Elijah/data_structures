// Search operation in a BST for key 'k'

// Best case:   O(1)
// Worst case:  O(n)
// Avg case:    O(log n)

// =====================

// Traversal Algorithms:
    
//     Inorder traversal (recursive):
//         - Traverse the left subtree using inorder traversal
//         - visit the root node
//         - traverse the right subtree using inorder traversal

//     Preorder traversal (recursive):
//         - visit the root node
//         - traverse the left subtree using preorder traversal
//         - traverse the right subtree using preorder traversal
    
//     Postorder traversal (recursive):
//         - traverse the left subtree using preorder traversal
//         - traverse the right subtree using preorder traversal
//         - visit the root node

// =====================

// Deleting nodes from BST: cases to consider..

// 1) The node to be deleted is a leaf
//     - just remove the node

// 2) The node has a single child
//     - move the child up in the tree

// 3) The node has two children
//     -  find max value of the left subtree. Then delete that value from the left subtree.

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// struct for the node object
typedef struct node
{
    int data;                   // value stored in node
    struct node *left, *right;  // pointers to next node
}node;

node *create_node(int data) // returns a pointer with data passed in node 
{
    node *ptr = malloc(sizeof(node));   // allocates space
    ptr->data = data;                   // sets value to data passed
    ptr->left = ptr->right = NULL;      // only need to create this root node

    return ptr; 
}

node *bst_insert(node *root, int data)
{
    if (root == NULL)   // NULL check
        return create_node(data); // create_node returns a pointer to node
    
    else if (data < root->data)
        // recursive call to bst_insert() with new root node
        root->left = bst_insert(root->left, data);

    else if (data > root->data)
        root->right = bst_insert(root->right, data);

    else
        ;
}

// inorder algorithm traversal
void inorder(node *root)
{
    if (root = NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// preorder algorithm traversal
void preorder(node *root)
{
    if (root = NULL)
        return;

    preorder(root->left);
    preorder(root->right);
    printf("%d ", root->data);
}

// postorder algorithm traversal
void postorder(node *root)
{
    if (root = NULL)
        return;

    printf("%d ", root->data);
    postorder(root->left);
    postorder(root->right);
}

int max(int a, int b) // aux func: input two values return greater values
{
    return (a > b) ? a : b;
}

// return the height of the tree under the node
int height(node *root)
{
    if (root == NULL)
        return -1;  // base case
    
    // returns 1 + each traversal
    return 1 + max(height(root->left), height(root->right)); 
}

// set_fire() returns a pointer to a NULL node. It removes all roots/leaves following that node
node *set_fire(node *root)
{
    if (root == NULL)       // NULL condition
        return NULL;

    set_fire(root->left);   // traverse left
    set_fire(root->right);  // traverse right
    free(root);             // then remove

    return NULL;
}

int main()
{
    // insert driver code here
}