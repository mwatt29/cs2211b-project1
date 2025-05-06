


#ifndef BST_H
#define BST_H

#include "data.h"

typedef struct {
  Node *tree_nodes; // pointer to an array of tree nodes
  unsigned char *is_free; // array to track free nodes 
  int size; // number of nodes in bst
} BStree;

BStree bstree_ini(int size); // initliazes BST and how many nodes it can hold
void bstree_insert(BStree bst, Key key, char *data); // inserts a key value pair into the BST
void bstree_traversal(BStree bst);// traverses the bst and processes its elements
void bstree_free(BStree bst);// frees allocated memory for bst

#endif 
