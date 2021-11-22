#include "AVLTree.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node
{
    struct Node* leftSon;
    struct Node* rightSon;
    struct Node* parent;
    int key;
    char* value;
    int rightHeight;
    int leftHeight;
    int balance;
} Node;

typedef enum Direction
{
    left,
    right
} Direction;

Node* createTree()
{
    return NULL;
}

void deleteTreeRecursive(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    deleteTreeRecursive(root->leftSon);
    deleteTreeRecursive(root->rightSon);
    free(root->value);
    free(root);
}

void deleteTree(Node** root)
{
    deleteTreeRecursive(*root);
    *root = NULL;
}

void attach(Node* parent, Node* child, Direction direction)
{
    if (direction == left)
    {
        parent->leftSon = child;
    }
    else
    {
        parent->rightSon = child;
    }
    if (child != NULL)
    {
        child->parent = parent;
    }
}

int maxHeight(Node* x)
{
    if (x == NULL)
    {
        return -1;
    }
    return x->leftHeight > x->rightHeight ? x->leftHeight : x->rightHeight;
}

void updateBalance(Node* root)
{
    root->balance = root->rightHeight - root->leftHeight;
}

void checkHeight(Node* x)
{
    x->balance = x->rightHeight - x->leftHeight;
    while (x->parent != NULL)
    {
        if (x->parent->leftSon == x)
        {
            x->parent->leftHeight = maxHeight(x) + 1;
        }
        else if (x->parent->rightSon == x)
        {
            x->parent->rightHeight = maxHeight(x) + 1;
        }
        x->parent->balance = x->parent->rightHeight - x->parent->leftHeight;
        if (x->parent->balance == 2 || x->parent->balance == -2)
        {
            return;
        }
        x = x->parent;
    }
}

Node* leftSmallRotation(Node* lastRoot)
{
    Node* newRoot = lastRoot->rightSon;
    Node* rootFather = lastRoot->parent;
    attach(lastRoot, newRoot->leftSon, right);
    attach(newRoot, lastRoot, left);
    if (rootFather != NULL)
    {
        if (rootFather->leftSon == lastRoot)
        {
            rootFather->leftSon = newRoot;
        }
        else if (rootFather->rightSon == lastRoot)
        {
            rootFather->rightSon = newRoot;
        }
    }
    newRoot->parent = rootFather;
    lastRoot->rightHeight = maxHeight(lastRoot->rightSon) + 1;
    updateBalance(lastRoot);
    newRoot->leftHeight = maxHeight(lastRoot) + 1;
    updateBalance(newRoot);
    checkHeight(newRoot);
    return newRoot;
}

Node* rightSmallRotation(Node* lastRoot)
{
    Node* father = lastRoot->parent;
    Node* newRoot = lastRoot->leftSon;
    attach(lastRoot, newRoot->rightSon, left);
    attach(newRoot, lastRoot, right);
    if (father != NULL)
    {
        if (father->leftSon == lastRoot)
        {
            father->leftSon = newRoot;
        }
        else if (father->rightSon == lastRoot)
        {
            father->rightSon = newRoot;
        }
    }
    newRoot->parent = father;
    lastRoot->leftHeight = maxHeight(lastRoot->leftSon) + 1;
    updateBalance(lastRoot);
    newRoot->rightHeight = maxHeight(lastRoot) + 1;
    updateBalance(newRoot);
    checkHeight(newRoot);
    return newRoot;
}

Node* largeLeftRotation(Node* lastRoot)
{
    Node* father = lastRoot->parent;
    Node* rightSon = lastRoot->rightSon;
    Node* newRoot = rightSon->leftSon;
    Node* newLeftSonForRightSon = rightSon->leftSon->rightSon;
    Node* newRightSonForLastRoot = rightSon->leftSon->leftSon;
    attach(lastRoot, newRightSonForLastRoot, right);
    attach(rightSon, newLeftSonForRightSon, left);
    attach(newRoot, lastRoot, left);
    attach(newRoot, rightSon, right);
    if (father != NULL)
    {
        if (father->leftSon == lastRoot)
        {
            father->leftSon = newRoot;
        }
        else if (father->rightSon == lastRoot)
        {
            father->rightSon = newRoot;
        }
    }
    newRoot->parent = father;
    rightSon->leftHeight = maxHeight(newLeftSonForRightSon) + 1;
    updateBalance(rightSon);
    lastRoot->rightHeight = maxHeight(newRightSonForLastRoot) + 1;
    updateBalance(lastRoot);
    newRoot->leftHeight = maxHeight(lastRoot) + 1;
    newRoot->rightHeight = maxHeight(rightSon) + 1;
    updateBalance(newRoot);
    checkHeight(newRoot);
    return newRoot;
}

Node* largeRightRotation(Node* lastRoot)
{
    Node* father = lastRoot->parent;
    Node* leftSon = lastRoot->leftSon;
    Node* newRoot = leftSon->rightSon;
    Node* newLeftSonForLastRoot = leftSon->rightSon->rightSon;
    Node* newRightSonForLeftSon = leftSon->rightSon->leftSon;
    attach(lastRoot, newLeftSonForLastRoot, left);
    attach(leftSon, newRightSonForLeftSon, right);
    attach(newRoot, lastRoot, right);
    attach(newRoot, leftSon, left);
    if (father != NULL)
    {
        if (father->leftSon == lastRoot)
        {
            father->leftSon = newRoot;
        }
        else if (father->rightSon == lastRoot)
        {
            father->rightSon = newRoot;
        }
    }
    newRoot->parent = father;
    leftSon->rightHeight = maxHeight(newRightSonForLeftSon) + 1;
    updateBalance(leftSon);
    lastRoot->leftHeight = maxHeight(newLeftSonForLastRoot) + 1;
    updateBalance(lastRoot);
    newRoot->leftHeight = maxHeight(leftSon) + 1;
    newRoot->rightHeight = maxHeight(lastRoot) + 1;
    updateBalance(newRoot);
    checkHeight(newRoot);
    return newRoot;
}

Node* checkBalance(Node* root)
{
    while (root->parent != NULL)
    {
        if (root->parent->balance == -2)
        {
            if (root->leftHeight >= root->rightHeight)
            {
                root = rightSmallRotation(root->parent);
            }
            else
            {
                root = largeRightRotation(root->parent);
            }
        }
        else if (root->parent->balance == 2)
        {
            if (root->rightHeight >= root->leftHeight)
            {
                root = leftSmallRotation(root->parent);
            }
            else
            {
                root = largeLeftRotation(root->parent);
            }
        }
        if (root->parent == NULL)
        {
            break;
        }
        root = root->parent;
    }
    return root;
}

Node* createNewNode(Node* root, int key, char* value, int* error)
{
    char* copyValue = calloc(strlen(value) + 1, sizeof(char));
    if (copyValue == NULL)
    {
        *error = 1;
        return root;
    }
    strcpy(copyValue, value);
    if (root != NULL && key == root->key)
    {
        free(root->value);
        root->value = copyValue;
        return root;
    }
    Node* newRoot = (Node*)calloc(1, sizeof(Node));
    if (newRoot == NULL)
    {
        *error = 1;
        free(copyValue);
        return root;
    }
    newRoot->key = key;
    newRoot->value = copyValue;
    return newRoot;
}

void startCheckingHeights(Node* root, Node* newRoot, Direction direction)
{
    direction == left ? root->leftHeight++ : root->rightHeight++;
    checkHeight(newRoot);
}

Node* addNode(Node* root, int key, char* value, int* error)
{
    if (*error != 0)
    {
        return root;
    }
    if (root == NULL)
    {
        return createNewNode(root, key, value, error);
    }
    while(root != NULL)
    { 
        if (key > root->key)
        {
            if (root->rightSon == NULL)
            {
                Node* newRoot = createNewNode(root, key, value, error);
                if (*error == 1)
                {
                    return root;
                }
                attach(root, newRoot, right);
                startCheckingHeights(root, newRoot, right);
                return checkBalance(newRoot);
            }
            root = root->rightSon;
        }
        else if (key < root->key)
        {
            if (root->leftSon == NULL)
            {
                Node* newRoot = createNewNode(root, key, value, error);
                if (*error == 1)
                {
                    return root;
                }
                attach(root, newRoot, left);
                startCheckingHeights(root, newRoot, left);
                return checkBalance(newRoot);
            }
            root = root->leftSon;
        }
        else
        {
            return createNewNode(root, key, value, error);
            if (*error == 1)
            {
                return root;
            }
        }
    }
    return root;
}

Node* search(Node* root, int key)
{
    Node* newRoot = root;
    while (newRoot != NULL)
    {
        if (key > newRoot->key)
        {
            newRoot = newRoot->rightSon;
        }
        else if (key < newRoot->key)
        {
            newRoot = newRoot->leftSon;
        }
        else
        {
            return newRoot;
        }
    }
    return NULL;
}

void deleteNode(Node** root, int key, int* error)
{
    if (*error != 0)
    {
        return;
    }
    Node* searchResult = search(*root, key);
    if (searchResult == NULL)
    {
        return;
    }
    *root = searchResult;
    if ((*root)->rightSon == NULL && (*root)->leftSon == NULL)
    {
        Node* parent = (*root)->parent;
        if (parent != NULL)
        {
            if ((*root)->parent->rightSon == (*root))
            {
                (*root)->parent->rightSon = NULL;
                parent->rightHeight = 0;
            }
            else
            {
                (*root)->parent->leftSon = NULL;
                parent->leftHeight = 0;
            }
        }
        checkHeight(parent);
        Node* newRoot = checkBalance(*root);
        free((*root)->value);
        free(*root);
        *root = parent == NULL ? NULL : newRoot;
        return;
    }
    if ((*root)->rightSon != NULL && (*root)->leftSon != NULL)
    {
        Node* currentRoot = *root;
        currentRoot = currentRoot->leftSon;
        while (currentRoot->rightSon != NULL)
        {
            currentRoot = currentRoot->rightSon;
        }
        if (currentRoot == (*root)->leftSon)
        {
            Node* parent = (*root)->parent;
            attach(currentRoot, (*root)->rightSon, right);
            if (parent == NULL)
            {
                currentRoot->parent = NULL;
            }
            else
            {
                parent->rightSon == (*root) ? attach((*root)->parent, currentRoot, right) : attach((*root)->parent, currentRoot, left);
            }
            currentRoot->rightHeight = (*root)->rightHeight;
            free((*root)->value);
            free(*root);
            checkHeight(currentRoot);
            *root = checkBalance(currentRoot->rightSon);
            return;
        }
        Node* currentRootParent = currentRoot->parent;
        char* newValue = calloc(strlen((currentRoot)->value) + 1, sizeof(char));
        if (newValue == NULL)
        {
            return;
        }
        (*root)->key = currentRoot->key;
        free((*root)->value);
        strcpy(newValue, currentRoot->value);
        (*root)->value = newValue;
        currentRootParent->rightSon = NULL;
        currentRootParent->rightHeight = 0;
        checkHeight(currentRootParent);
        Node* newRoot = checkBalance(currentRoot);
        free(currentRoot->value);
        free(currentRoot);
        *root = newRoot;
        return;
    }
    if ((*root)->parent == NULL)
    {
        *root = (*root)->rightSon == NULL ? (*root)->leftSon : (*root)->rightSon;
        if ((*root)->parent != NULL)
        {
            free((*root)->parent->value);
        }
        free((*root)->parent);
        (*root)->parent = NULL;
        return;
    }
    Node* parent = (*root)->parent;
    Node* newRoot = NULL;
    if ((*root)->rightSon == NULL)
    {
        parent->leftSon == *root ? attach(parent, (*root)->leftSon, left)
            : attach(parent, (*root)->leftSon, right);
        checkHeight((*root)->leftSon);
        newRoot = checkBalance((*root)->leftSon);
    }
    else
    {
        parent->leftSon == *root ? attach(parent, (*root)->rightSon, left)
            : attach(parent, (*root)->rightSon, right);
        checkHeight((*root)->rightSon);
        newRoot = checkBalance((*root)->rightSon);
    }
    free((*root)->value);
    free(*root);
    *root = newRoot;
    return;
}

bool inTree(Node* root, int key)
{
    Node* searchResult = search(root, key);
    return searchResult != NULL;
}

char* getValue(Node* root, int key)
{
    Node* searchResult = search(root, key);
    if (searchResult == NULL)
    {
        return NULL;
    }
    return searchResult->value;
}

bool invariant(Node* node)
{
    return abs(node->rightHeight - node->leftHeight) < 2;
}