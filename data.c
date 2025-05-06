// CS2211b 2025
// Assingment 4
// Murray Watt
// 251341261
// mwatt29
// March 12 2025




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

Key key_construct(char *in_name, int in_num) { // contructs a key with a given name and number
    Key key;
    key.name = (char *)malloc((strlen(in_name) + 1) * sizeof(char)); // allocate memory for the keys name and copy the input name
    strcpy(key.name, in_name);
    key.num = in_num; // assign the input nmber to the key
    return key;
}

int key_comp(Key key1, Key key2) { // compares two keys based on name first, and then by number if names are equal
    int cmp = strcmp(key1.name, key2.name);
    if (cmp == 0) {
        return key1.num - key2.num;
    }
    return cmp;
}

void print_key(Key key) { // prints a keys details , name and number
    printf("%d %s", key.num, key.name);
}

void print_node(Node node) { // prints a nodes details 
    print_key(node.key);
    printf("    %s\n", node.data); // prints nodes associated data
}
