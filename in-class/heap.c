// adding node to binary heap:
//     - O(logn)
//     - "percolating"
//     - since height of tree is O(logn)
// deleting node from binary heap:
//     -  move last node to root
//     - percolate down
//     - O(logn)

typedef struct heap
{
    int *array_heap;
    int capacity, heap_size;
}heap;
