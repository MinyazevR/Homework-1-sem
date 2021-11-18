#include <stdbool.h>

// Structure representing a tree
typedef struct Node Node;

// Structure representing a tree
typedef enum Error
{
    NOT_ERROR,
    ROOT_IS_MISSING,
    INSUFFICIENT_MEMORY   
} Error;

// Function for creating a tree
Node* createTree();

// Function for deleting a  tree
void deleteTree(Node** root);

// Function for adding a node
Node* addNode(Node* root, int key, const char* value, Error* error);

// Function for checking the availability of a key
bool inTree(Node* root, int key);

// Function for deleting a node
Node* deleteNode(Node* root, int key, Error* error);

// Function for checking the node for paternity
bool isFather(Node* tree, int parentKey, int childKey);

// Function of getting a value by key
char* getValue(Node* root, int key);