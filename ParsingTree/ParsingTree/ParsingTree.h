#pragma once

// Structure representing a tree
typedef struct Node Node;

// Function for creating a tree
Node* createTree();

// Function for deleting a  tree
void deleteTree(Node** root);

// Function that returns the root of the tree
Node* returnHead(Node* root);

// Function for building a tree
Node* buildTree(char* array);

// Function for calculating the value of an expression
void findAnswer(Node* root);

// Function for tree output
void printTree(Node* root);

// Function for returning the result of counting
int returnAnswer(Node* root);

// Function for accessing the right son of the current root
Node* rightSon(Node* root);

// Function for accessing the left son of the current root
Node* leftSon(Node* root);

// Function for accessing the parent of the current root
Node* parent(Node* root);

// Function to get the value
char getValue(Node* root);
