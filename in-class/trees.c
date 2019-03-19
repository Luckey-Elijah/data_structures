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

typedef struct node
{
    int data;
    struct node *left, *right;
}node;

node *create_node(int data)
{
    node *ptr = malloc(sizeof(node));
    ptr->data = data;
    ptr->left = ptr->right = NULL;

    return ptr;
}

node *bst_insert(node *root, int data)
{
    if (root == NULL){
        return create_node(data); // create_node returns a pointer to node
    }

    else if (data < root->data)
    {
        root->left = bst_insert(root->left, data); // recursive call to bst_insert() with new root node
    } 
    else if (data > root->data)
    {
        root->right = bst_insert(root->right, data);
    } 
    else
    {
        ;
    }
    
}

void inorder(node *root)
{
    if (root = NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(node *root)
{
    if (root = NULL)
        return;

    preorder(root->left);
    preorder(root->right);
    printf("%d ", root->data);
}

void postorder(node *root)
{
    if (root = NULL)
        return;

    printf("%d ", root->data);
    postorder(root->left);
    postorder(root->right);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(node *root)
{
    if (root == NULL)
        return -1;
    
    return 1 + max(height(root->left), height(root->right));
}

node *set_fire(node *root)
{
    if (root == NULL)
        return NULL;

    set_fire(root->left);
    set_fire(root->right);

    free(root);

    return NULL;
}

int main()
{
    
}
