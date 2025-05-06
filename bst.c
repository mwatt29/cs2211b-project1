//CS2211b 2025
//Assingment 4
// Murray Watt
// 251341261
// March 12 2025




#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// Initialize the binary search tree
BStree bstree_ini(int size) {
    BStree bst;
    bst.tree_nodes = (Node *)malloc((size + 1) * sizeof(Node));
    bst.is_free = (unsigned char *)malloc((size + 1) * sizeof(unsigned char));
    for (int i = 0; i <= size; i++) {
        bst.is_free[i] = 1;
    }
    bst.size = size;
    return bst;
}

// Helper function for inserting a node recursively
void bstree_insert_helper(BStree bst, Key key, char *data, int index) {
    if (index > bst.size) {
        fprintf(stderr, "Error: Array index out of bounds\n");
        return;
    }

    if (bst.is_free[index]) {
        bst.tree_nodes[index].key = key;
        bst.tree_nodes[index].data = data;
        bst.is_free[index] = 0;
    } else {
        int cmp = key_comp(key, bst.tree_nodes[index].key);
        if (cmp < 0) {
            if (2 * index <= bst.size) { // Check bounds for left child
                bstree_insert_helper(bst, key, data, 2 * index);
            } else {
                fprintf(stderr, "Error: Array index out of bounds\n");
            }
        } else if (cmp > 0) {
            if (2 * index + 1 <= bst.size) { // Check bounds for right child
                bstree_insert_helper(bst, key, data, 2 * index + 1);
            } else {
                fprintf(stderr, "Error: Array index out of bounds\n");
            }
        }
        // If cmp == 0, the key is already in the tree, so do nothing
    }
}

// Insert a key-data pair into the BST
void bstree_insert(BStree bst, Key key, char *data) {
    bstree_insert_helper(bst, key, data, 1);
}

// Helper function for in-order traversal
void bstree_traversal_helper(BStree bst, int index) {
    if (index <= bst.size && !bst.is_free[index]) {
        bstree_traversal_helper(bst, 2 * index);
        print_node(bst.tree_nodes[index]);
        bstree_traversal_helper(bst, 2 * index + 1);
    }
}

// Perform in-order traversal of the BST
void bstree_traversal(BStree bst) {
    bstree_traversal_helper(bst, 1);
}

// Free all dynamically allocated memory in the BST
void bstree_free(BStree bst) {
    for (int i = 1; i <= bst.size; i++) {
        if (!bst.is_free[i]) {
            free(bst.tree_nodes[i].key.name);
            free(bst.tree_nodes[i].data);
        }
    }
    free(bst.tree_nodes);
    free(bst.is_free);
}
