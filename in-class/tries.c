// There are two characteristics of tries:
//     - First, a trie is a tree in which every node has 26 children
//     - Second, the string we insert into a trie is not stored 
//     inside our nodes. Instead, the string that the node represents
//     is based on the path


typedef struct trieNode
{
    // specific to alphabetical tries
    struct trieNode *children[26];
    int count;
}trieNode;

// Time Complexities
// -------------------------
// |        | worst | best |
// | ------ | ----- | ---- |
// | insert | O(k)  | O(k) |
// | search | O(k)  | O(1) |
// | del    | O(k)  | O(1) |

