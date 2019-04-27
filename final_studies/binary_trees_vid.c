// Topics Covered:

// - difference trees:

        // - one root node 
        // - can children 
        
        // - binary has one root node
        // - can only have up to two 

        // - binary search tree (BST)
        // - have up to two children nodes
        // - left child node must be small thant eh parent node 
        // - right child node must be larger than the parent

// - binary tree types:

// - implement it in code

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node 
{
    // you ahve a left and right child node
    struct node *right;
    struct node *left;

    // each node will contain data
    int data;
}node;

struct node *create_tree(int num_nodes);
void preorder_traversal(struct node *root);
void postorder_traversal(struct node *root);
node *set_fire(struct node *root);

int main()
{
    int num_nodes = 10;

    // create tree
    struct node *root = create_tree(num_nodes);

    // display the tree
    printf("PREORDER: ");
    preorder_traversal(root);
    printf("\n");

    printf("POSTORDER: ");
    postorder_traversal(root);
    printf("\n");

    // remove the tree from memory
    printf("SET_FIRE to ROOT.\n");
    root = set_fire(root);

    printf("PREORDER: ");
    preorder_traversal(root);
    printf("\n");
}

// creates a node in memory with malloc() and returns the newly created node
struct node *create_node(int data)
{
    struct node *root = malloc(sizeof(struct node));

    // error checking
    if (!root)
    {
        fprintf(stderr, "Could not allocate memory for that node.\n");
        return root = NULL;
    }

    // settings values ot structure
    root->data  = data;
    root->left  = NULL;
    root->right = NULL;

    // exits
    return root;
}

// inserts node into proper place of the binary tree
struct node *insert_node(node *root, int data)
{
    // if a node doesn't exist at this point return a new node
    if (root == NULL)
    {
        return create_node(data);
    }

    // when data is greater than the roots data
    else if (data > root->data)
    {
        root->right = insert_node(root->right, data);
    }

    // when data is less than the roots data
    else if (data < root->data)
    {
        root->left = insert_node(root->left, data);
    }

    // statement that return the root when that data is equal to the node->data
    // and its made its way throught all the conditional statements
    return root;
}

struct node *create_tree(int num_nodes)
{
    srand(time(0));

    struct node *root = NULL;
    int temp_data;
    int i; // iterator

    printf("INSERTING: ");


    for (i = 0; i < num_nodes; i++)
    {
        // creates random value
        temp_data = rand() % 100 + 1;

        // inserts random value
        root = insert_node(root, temp_data);

        // print the inserted node
        printf("%d ", temp_data);
    }

    printf("\n");

    return root;
}

void preorder_traversal(struct node *root)
{
    // end of tree, exiting
    if (root == NULL)
        return;
    
    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void postorder_traversal(struct node *root)
{
    // end of tree, exiting
    if (root == NULL)
        return;
    
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->data);
}

node *set_fire(node *root)
{
    // base case
    if (!root)
    {
        printf("%d ", root->data);
        return NULL;
    }

    // traverse the tree to burn
    set_fire(root->left);
    set_fire(root->right);
    
    // burn the root
    // free(root);

    return root;
}