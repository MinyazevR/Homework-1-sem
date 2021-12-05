#pragma once
#include <stdbool.h>

// the structure representing the AVL tree
typedef struct Node Node;

// function for adding a node to a tree
Node* addNode(Node* root, char* key, char* value, int* error);

// function for removing a node from a tree
void deleteNode(Node** root, char* key, int* error);

// function for deleting a tree
void deleteTree(Node** root);

// function for creating a tree
Node* createTree();

// function for getting tree values
char* getValue(Node* root, char* key);

// function for checking the invariant of the tree
bool invariant(Node* node);

// function for checking the presence of a key
bool inTree(Node* root, char* key);