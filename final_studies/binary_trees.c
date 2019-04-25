#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Topics covered:

// 	- differences bewtween trees, binary trees, and binary search trees.
// 	- efficiency of insertion, look-up, search, etc. in binary trees vs BST.
// 	- runtimes of BST operations, and details of why.

// 	- define "complete binary tree" 
// 	- height of a complete binary tree with n nodes
// 	- define a "full" binary tree
// 	- define a "perfect" binary tree

// 	- function: insertion_bst()
// 	- function: deletion_bst()
// 	- write functions on BST
// 		- recursive
// 		- iterative
// 		- etc

// 	- traversals:
// 		- in-order
// 		- pre-order
// 		- post-order

typedef struct node
{
	// nodes contain numerical data
	int data;

	// nodes have left and right children nodes
	struct node *left;
	struct node *right;
}node;

int *random_arr_generator(int a_size)
{
	srand(time(0));
	printf("calling random_arr_generator(%d)\n", a_size);
	
	// initialize values and array
	int i, temp_n;
	int *random_arr;

	// loop that populates the array
	for (i = 0; i <= a_size; i++) {
		// temp random int stored here
		temp_n = rand() % 100 + 1;

		// random value stored here
		random_arr[i] = temp_n;
  }

	// printf("random_arr_generator() SUCCESS\n");
	return random_arr;
}

void print_array(int *array, int arr_size)
{
	int i;
	printf("Array for inserting: ");
	for (i = 0; i < arr_size; i++)
	{
		printf("%d, ", array[i]);
	}
	printf("\n");
}

node *create_node(int new_data)
{
	node *new_node= malloc(sizeof(node));
	new_node->data = new_data;
	new_node->left = new_node->right = NULL; 

	return new_node;
}

node *insert_node(node *root, int new_data)
{
	printf("insert_node(root: %d, data: %d)\n", root->data, new_data);
	if (root == NULL)
	{
		return create_node(new_data);
		printf("INSERTED\n");
	}

	else if (new_data < root->data)
	{
		root->left = insert_node(root->left, new_data);
		printf("INSERTED\n");
	}

	else if (new_data > root->data)
	{
		root->right = insert_node(root->right, new_data);
		
	}
	else
	{
		;
	}

}

node *create_tree(int *node_array, int num_nodes)
{
	printf("create_tree(size: %d)\n", num_nodes);
	if (node_array == NULL) {
		// case that the array is empty 
		return NULL;
	}

	node *root = create_node(node_array[0]);
	int i;

	for (i = 1; i < num_nodes; i++)
	{
		root = insert_node(root, node_array[i]);
	}

	return root;
}

int main(int argc, char const *argv[])
{
	// driver code for creating BSTs
	int num_nodes = 5, i;
	int *node_values = random_arr_generator(num_nodes);

	print_array(node_values, num_nodes);

	node *root = create_tree(node_values, num_nodes);
	return 0;
}