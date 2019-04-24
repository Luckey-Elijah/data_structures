#include <stdio.h>
#include <stdlib.h>

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
	int data;
	struct node *left;
	struct node *right;
}node;

node *create_node(int new_data)
{
	node *new_node;
	new_node = malloc(sizeof(node));

	// checking here if we properlly allocated memory for node
	if (new_node == NULL)
	{
		// print error message
		printf("Could not allocate memory for new node.\nData: %d\n", new_data);

		// return NULL pointer to node
		return (new_node = NULL); 
	}

	new_node->data = new_data;
	return new_node;
}

node *insert_node(node *root, int new_data)
{
	if (root == NULL)
	{
		printf("ROOT node is NULL, creating a new ROOT NODE.\n");
		root = create_node(new_data);
	}
}

int main(int argc, char const *argv[])
{
	// driver code for creating BSTs
	int *node_values[] = {};

	node *root = create_tree(node_values);

	return 0;
}