#include <stdbool.h>

// Structure representing a tree
typedef struct Node Node;

// Function for creating a tree
Node* createTree();

// Function for deleting a  tree
void deleteTree(Node** root);

// Function for adding a node
Node* addNode(Node* root, int key, char* value);

// Function for checking the availability of a key
bool inTree(Node* root, int key);

// Function for deleting a node
<<<<<<< HEAD
void deleteNode(Node** root, int key, Error* error);
=======
Node* deleteNode(Node* root, int key);
>>>>>>> parent of e8f39c0 (added work with errors, changed the functions of adding and removing nodes)

// Function for checking tree invariant
bool invariant(Node* tree, int firstKey, int secondKey);

// Function of getting a value by key
char* getValue(Node* root, int key);