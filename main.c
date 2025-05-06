//CS2211b 2025
// Assignment 4
// Murray Watt
// 251341261
// mwatt29
// March 12 2025


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

#define MAX_STR_LENGTH 100

void read_input(BStree bst) {
    int num;
    char str[MAX_STR_LENGTH];
    char data[MAX_STR_LENGTH];

    while (scanf("%d ", &num) == 1) { // Read the integer part of the key
        fgets(str, MAX_STR_LENGTH, stdin); // Read the string part of the key (may contain spaces)
        str[strcspn(str, "\n")] = '\0'; // Remove the newline character from the string

        scanf("%s", data); // Read the data (no spaces)

        // Construct the key and insert into the BST
        Key key = key_construct(str, num);
        bstree_insert(bst, key, strdup(data)); // Use strdup to dynamically allocate data
    }
}

int main(int argc, char *argv[]) {
    int size;

    // Read the size of the BST array
    if (scanf("%d", &size) != 1) {
        fprintf(stderr, "Error: Failed to read the size of the BST array.\n");
        return 1;
    }

    // Initialize the BST
    BStree bst = bstree_ini(size);

    // Read input from stdin or a file
    if (argc == 1) {
        // Read from stdin
        read_input(bst);
    } else if (argc == 2) {
        // Read from a file
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Error: Unable to open file %s.\n", argv[1]);
            bstree_free(bst);
            return 1;
        }

        // Redirect stdin to the file
        freopen(argv[1], "r", stdin);
        read_input(bst);

        fclose(file);
    } else {
        fprintf(stderr, "Usage: %s [input_file]\n", argv[0]);
        bstree_free(bst);
        return 1;
    }

    // Perform in-order traversal
    bstree_traversal(bst);

    // Free the BST
    bstree_free(bst);

    return 0;
}
