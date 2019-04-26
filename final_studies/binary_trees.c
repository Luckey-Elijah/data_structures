#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Topics covered:

// 	- differences between trees, binary trees, and binary search trees.
// 	- efficiency of insertion, look-up, search, etc. in binary trees vs BST.
// 	- runtimes of BST operations, and details of why.

// 	- define "complete binary tree" 
// 		- a complete binary tree is one that where every "level" is completely filled execpt possibly the last level; in that case the last level must have nodes that are in left most positions
// 	- height of a complete binary tree with n nodes
// 		- the height of a binary tree can be calculated calculated 
// 	- define a "full" binary tree
// 	- define a "perfect" binary tree

// 	- function: insertion_bst()
// 	- function: deletion_bst()
// 	- write functions on BST
// 		- recursive
// 		- iterative
// 		- etc

typedef struct node
{
	// nodes have left and right children nodes
	struct node *right;
	struct node *left;
	
	// nodes contain numerical data
	int data;
}node;

void print_node_data(node *root)
{
	if (!(root->data))
	{
		// If there is ever no data in the node, it won't print
		printf("ROOT->DATA is NULL\n");
		return;
	}

	printf("%d ", root->data);
}

int *random_arr_generator(int a_size)
{
	srand(time(0));
	// printf("calling random_arr_generator(%d)\n", a_size);
	
	// initialize values and array
	int i, temp_n;
	int *random_arr = malloc((sizeof(int)) * a_size);

	// loop that populates the array
	for (i = 0; i <= a_size; i++) {
		// temp random int stored here
		temp_n = rand() % 100 + 1;

		// random value stored here
		random_arr[i] = temp_n;
		printf("%d, ", temp_n);
  }

	printf("\n");
	return random_arr;
}

struct node *create_node(int new_data)
{
	struct node *new_node= malloc(sizeof(node));
	new_node->data = new_data;
	new_node->left = new_node->right = NULL; 

	return new_node;
}

node *insert_node(node *root, int new_data)
{
	// printf("insert_node(root: %d, data: %d)\n", root->data, new_data);
	if (root == NULL)
	{
		// printf("INSERTED: %d\n", new_data);
		return create_node(new_data);
	}
	// LESS-THAN
	else if (new_data < root->data)
	{
		// printf("INSERTED: %d\n", new_data);
		root->left = insert_node(root->left, new_data);
		// printf("INSERTED\n");
	}
	// GREATER-THAN
	else if (new_data > root->data)
	{
		// printf("INSERTED: %d\n", new_data);
		root->right = insert_node(root->right, new_data);
	}
	else
	{
		// printf("did not INSERT %d. Already exists.\n", new_data);
	}
	
}

struct node *create_tree(int *node_array, int num_nodes)
{
	// printf("create_tree(size: %d)\n", num_nodes);
	if (node_array == NULL) {
		// case that the array is empty 
		printf("ARRAY given is NULL\n");
		return NULL;
	}

	// creates the root node
	node *root = create_node(node_array[0]); 
	printf("INSERTED: %d\n", node_array[0]);
	
	int i;
	for (i = 1; i < num_nodes; i++)
	{
		// INSERTS new node into tree
		printf("INSERTED: %d\n", node_array[i]);
		root = insert_node(root, node_array[i]);
	}

	// printf("exit create_tree\n");
	return root;
}

void inorder_traversal(node *root)
{
	if (root == NULL)
	{
		// NULL root value, exits
		return;
	}

	// does traversal: INORDER
	inorder_traversal(root->left);
	print_node_data(root);
	inorder_traversal(root->right);
}

void preorder_traversal(node *root)
{
	if (root == NULL)
	{
		// NULL root value, exits
		return;
	}

	// does traversal: PREORDER
	print_node_data(root);
	preorder_traversal(root->left);
	preorder_traversal(root->right);
}

void postorder_traversal(node *root)
{
	if (root == NULL)
	{
		// NULL root value, exits
		return;
	}

	// does traversal: POSTERDER
	postorder_traversal(root->left);
	postorder_traversal(root->right);
	print_node_data(root);
}

void traversals(node *root)
{
	if (!root)
	{
		printf("ROOT is NULL\n");
		return;
	}

	printf("\ninorder_traversal: ");
	inorder_traversal(root);

	printf("\npostorder_traversal: ");
	postorder_traversal(root);

	printf("\npreorder_traversal: ");
	preorder_traversal(root);
}

// removes all nodes in a tree and "burns" them
node *set_fire(node *root)
{
    if (root == NULL)       // NULL condition
        return NULL;

    set_fire(root->left);   // traverse left
    set_fire(root->right);  // traverse right
    free(root);             // then remove

    return NULL;
}

int main(int argc, char const *argv[])
{
	// driver code for creating BSTs
	int num_nodes = 10;
	int *node_values = random_arr_generator(num_nodes);

	node *root = create_tree(node_values, num_nodes);
	traversals(root);

	root = set_fire(root);

	return 0;
}