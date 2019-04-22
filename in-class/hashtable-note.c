// Hash tables

// First, let's look at ...

// Array (unsorted, no gaps allowed)
//              Worst   Avg
// Insertion    O(1)    O(1)
// Search       O(n)    O(n)
// Deletion     O(n)    O(n)

// Array (sorted, no gaps allowed)
//              Worst       Avg
// Insertion    O(n)        O(n)
// Search       O(log n)    O(log n)
// Deletion     O(n)        O(n)

// Binary search tree (unballanced)
//              Worst       Avg
// Insertion    O(n)        O(log n)
// Search       O(n)        O(log n)
// Deletion     O(n)        O(log n)

// Binary search tree (balanced)
//              Worst       Avg
// Insertion    O(log n)    O(log n)
// Search       O(log n)    O(log n)
// Deletion     O(log n)    O(log n)

// === === === === === === === === ===

// Direct indexing of huge array
//              Worst       Avg
// Insertion    O(1)        O(1)
// Search       O(1)        O(1)
// Deletion     O(1)        O(1)

// === === === === === === === === ===

// Hash Table
//              Worst       Avg
// Insertion    O(1)        O(1)

// Search       O(1)        O(1)
// Deletion     O(1)        O(1)

// Create an array and call it a hash table to hold 
// N student records. Space complexity redueced to # 
// of structs being used.

// === === === === === === === === ===

    