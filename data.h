//CS2211b 2025
// Assignment 4
// Murray Watt
// 251341261
// mwatt29
// March 12 2025

#ifndef DATA_H
#define DATA_H

typedef struct { // defintion of key structure
    char *name;
    int num;
} Key;

typedef struct { // definition of node structure
    Key key;
    char *data;
} Node;

Key key_construct(char *in_name, int in_num); // constructs a key with a given name and number
int key_comp(Key key1, Key key2);// compares two keys first by name, then bby number if names are equal
void print_key(Key key); // prints the details of the key
void print_node(Node node);// prints the details of node, including its key and data

#endif // DATA_H
