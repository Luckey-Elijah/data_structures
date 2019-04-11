#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define VERBOSE 1

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
//     -  find max value of the left subtree. Then delete that value 
//        from the left subtree.


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
    ptr->left = ptr->right = NULL;      // only need to create this root;

    return ptr; 
}

node *bst_insert(node *root, int data)
{
    if (root == NULL)   // NULL check
        return create_node(data);   // create_node returns a 
                                    // pointer to node
    
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

int max(int a, int b)   // aux func: input two values return greater 
                        // values
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

// set_fire() returns a pointer to a NULL node. It removes all roots/
// leaves following that node

node *set_fire(node *root)
{
    if (root == NULL)       // NULL condition
        return NULL;

    set_fire(root->left);   // traverse left
    set_fire(root->right);  // traverse right
    free(root);             // then remove

    return NULL;
}

// When deleting a root node that has two children, replace the deleted
// node with the greatest value on

// function that deletes a node and re-orders a tree
node *bst_delete(node *root, int data)
{
    node *new_root;

    if (root->data > data)
    {
        root->left =bst_delete(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = bst_delete(root->right, data);
    }
    else
    {
        // Hooray! We have found the value
        // We first need to check the node for children
        
        // if no children, free the node
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL)
        {
            // this case is when there is only a right child
            new_root = root->right;
            free(root);
            return new_root;
        }
        else if (root->right == NULL)
        {
            new_root = root->left;
            free(root);
            return new_root;
        }
        else
        {
            // Case where the node to be deleted has two children
            // We have to find the max node on the left subtree
            root->data = find_max(root->left);
            root->left = bst_delete(root->left, root->data);
        }
        
    }
    
    return root;
}

// a function takes the root of a bst and returns a pointer
// to the node with max value

node *largest(node *root)
{
    // base case
    if (root->right == NULL)
    {
        return root;
    }

    if (root == NULL)
    {
        return NULL;
    }

    return largest(root->right);
}

// A function that takes the root of a bst and returns a pointer
// to the node with max value
node *iterative_largest(node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    while ( root->right != NULL)
    {
        root = root->right;
    }

    return root;
}

// recursive approach for counting the number of nodes
int count_nodes(node *root)
{
    return (root == NULL) ? 0 : count_nodes(root->left)
     + count_nodes(root->right) +1;
}

// A function that counts the number of node that have one node
int count_one_child_nodes(node *root)
{
    if (root = NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 0;
    }
    return (root->left == NULL || root->right == NULL)
     + count_one_child_nodes(root->left)
     + count_one_child_nodes(root->right);
}

// Return the number of leaf nodes in a binary tree
int count_leaf_nodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if(root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    else
    {
        return count_leaf_nodes(root->left)
         + count_leaf_nodes(root->right);
    }
    
}

// return the value of the highest value node
int find_max(node *root)
{
    while(root->right != NULL)
    {
        root = root->right;
    }

    return root->data;
}

int recursive_find_max(node *root)
{
    if (root->right == NULL)
    {
        return recursive_find_max(root->right);
    }
}

// Return 1 if the trees deffer, 0 otherwise
int tree_diff(node *a, node *b)
{
    if (a== NULL && b==NULL){
        return 0;
    }
    else if (a==NULL || b==NULL){
        return 1;
    }
    else if (a->data != b->data){
        return 1;
    }
    return tree_diff(a->left, b->right)
}

// Recursive function count how many nodes are greater than a 'key'
int bst_count_greater(node *root, int key)
{
    // no values exist
    if (root==NULL){
        return 0;
    }

    else if (root->data > key){
        return 1    + bst_count_greater(root->left, key) 
                    + bst_count_greater(root->right, key);
    }

    else{
        return bst_count_greater(root->right, key);
    }
}

typedef struct node
{
    int height, data;
    struct node *left, *right;
}node;

node *create_node(int data){
    node *n = malloc(sizeof(node));

    n->data = data;
    n->left = n->right = NULL;
    n->height = 0;
    if(VERBOSE)
        printf("    Inserted %d\n", data);
    
    return n;
}

int height_of(node *root){
    return (root == NULL) ? -1 : root->height;
}

int balance_factor(node *root){
    return height_of(root->left) - height_of(root->right);
}

node *single_right(node *root)
{
    // holding the root's right child
    node *temp = root->left;

    // root is moving to the left and loosing its right child
    // take the new root's orphaned left child
    root->left = temp->right;

    // right child moves up to take the place of the root
    temp->right = root;

    // update balance factor of each node
    root->height = 1+max(height_of(root->left), height_of(root->right));
    temp->height = 1+max(height_of(temp->left), height_of(temp->right));

    if (VERBOSE){
        printf("    (Performed single right rotation at node %d)\n", 
        root->data);}
}

// perform a single left rotation at specified node
node *single_left(node *root)
{
    // holding the root's right child
    node *temp = root->right;

    // root is moving to the left and loosing its right child
    // take the new root's orphaned left child
    root->right = temp->left;

    // right child moves up to take the place of the root
    temp->left = root;

    // update balance factor of each node
    root->height = 1+max(height_of(root->left), height_of(root->right));
    temp->height = 1+max(height_of(temp->left), height_of(temp->right));

    if (VERBOSE){
        printf("    (Performed single left rotation at node %d)\n", 
        root->data);}
}

node *avl_balance(node *root)
{
    // calc the balance factor of root
    int bf = balance_factor(root);

    // AVL
    if (bf == -2){
        if (balance_factor(root->right) > 0) {
            root->right = single_right(root->right);
        }
        
    }

    if (bf == 2){
        if (balance_factor(root->left) < 0){
            root->left = single_left(root->left);
        }
        root = single_right(root);
    }

    return root;
}

int main()
{
    // insert driver code here

    // ask user what node they want to delete
}

// AVL trees are self-balancing awesome tree. An AVL tree is a BST which
// is balanced. An AVL tree is balanced if every node has a balance 
// factor of -1, 0, or 1. The BF of a node is its left subtree height 
// minus its right subtree height

//             [35]     
//            /    \    
//         [20]    [40] 
//        /    \        
//     [10]    [25]     

// ========================

//             [a]             [b]
//            /               /   \ 
//         [b]    right->  [c]     [a]
//        /    rotation @ root
//     [c]

// GOLDEN RULES:

//     1. if the BF of a node is +2, this means that this tree is
//     left-heavy (or left subtree is greater than right subtree)
//     2. check the BF of the left child. If it is +1, a right rotation.
//     3. But if the BF factor of left child is -1, perform a left-right
//     rotation
