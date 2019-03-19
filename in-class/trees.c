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

Deleting nodes from BST

1) The node to be deleted is a leaf
    - just remove the node

2) The node has a single child
    - move the child up in the tree

3) The node has two children
    -  find max value of the left subtree. Then delete that value from the left subtree.