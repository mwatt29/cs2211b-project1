# cs2211b-project1

# What This Project Does

# Overview
This assignment involves implementing a Binary Search Tree (BST) in C using arrays. The BST will store nodes containing a key (a string and integer pair) and associated data (a string). The implementation must support insertion, traversal, and proper memory management.

Files Provided
data.h – Contains structure definitions for Key and Node, along with function prototypes.

data.c – Implements functions for key comparison, construction, and printing.

bst.h – Defines the BStree structure and function prototypes for BST operations.

bst.c – Contains the implementation of BST functions (initialization, insertion, traversal, and freeing memory).

main.c – A sample program demonstrating BST usage.

Implementation Details
1. Data Structures

Key: A structure containing:

char *name (string)

int num (integer)

Node: A structure containing:

Key key (a Key object)

char *data (a string)

BStree: A structure containing:

Node *tree_nodes (array of nodes)

unsigned char *is_free (array indicating whether a node is free)

int size (size of the array)

2. Key Functions
data.c
key_construct(char *in_name, int in_num)
Dynamically allocates memory for a Key and initializes it.

key_comp(Key key1, Key key2)
Compares two keys first by name (using strcmp) and then by num.

print_key(Key key)
Prints a key in the format: num name.

print_node(Node node)
Prints a node in the format: num name data.

bst.c
bstree_ini(int size)
Initializes a BST by allocating memory for tree_nodes and is_free.

bstree_insert(BStree bst, Key key, char *data)
Inserts a new node into the BST while maintaining BST properties (no duplicates, left < parent < right).

bstree_traversal(BStree bst)
Performs an in-order traversal (left → root → right) and prints nodes.

bstree_free(BStree bst)
Frees all dynamically allocated memory.

3. Recursive Implementation
Insertion and traversal must be implemented recursively.

Helper functions may be used (e.g., recursive insertion helper).

4. Input Handling
The program should read input in the format:

<int> <string>  (key)
<string>        (data)
Example:

70 Oxford Street
$2500
