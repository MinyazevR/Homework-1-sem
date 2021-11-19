#pragma once

// Structure representing a tree
typedef struct Node Node;

// Function for deleting a  tree
void deleteTree(Node** root);

// Function for building a tree
Node* buildTree(const char* array);

// Function for calculating the value of an expression
int findAnswer(Node* root, int* error);

// Function for tree output
void printTree(Node* root);