// Topics Covered

// 	- structure and ordering of heap
// 	- basic operations of heap
// 		- know how-to trace through them
// 	- when remove from heap, restore heapiness?
// 	- insert into heap, new node goes where? heapiness restored?
// 	- Big "O" runtimes
// 	- minheap vs maxheap

// 	- array representation of heap
// 	- find parents, left children, right children, and bottom-right-most non-leaf node of a heap
// 	- coding basic heap operations

// 	- know heapify()
// 	- Big "O" of heapify()

// 	- know heapsort & Big "O" runtimes
// 	- any other similar runtimes?

// There two basic forms of binary heaps: MIN-heap and MAX-heap
//      - MAX-heap: the key at the root must be greater than all of its children
//      - MIN-heap: the key at the root must be less than than all of its children

// Binary heaps can be classified by some properties:
//      - it's a complete tree
//      - it is either a min-heap or a max heap

//  Binary heaps are typical represented as arrays

// Common uses of HEAPS:

    // - heapsort: uses a binary heap to sort an array in O(nlogn) time
    // - priority queue
    // - graph algorithms: such as Dijkstra's shortest path and Prim's minimum spanning tree

#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y);

typedef struct