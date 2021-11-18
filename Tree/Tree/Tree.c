#include "Tree.h"
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    struct Node* leftSon;
    struct Node* rightSon;
    struct Node* parent;
    int key;
    char* value;
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

void zig(Node* x)
{
    Node* father = x->parent;
    if (x == father->leftSon)
    {
        Node* rightSon = x->rightSon;
        attach(x, father, right);
        attach(father, rightSon, left);
    }
    else
    {
        Node* leftSon = x->leftSon;
        attach(x, father, left);
        attach(father, leftSon, right);
    }
    x->parent = NULL;
}

void zigZig(Node* x)
{
    Node* father = x->parent;
    Node* grandFather = father->parent;
    Node* grandGrandFather = grandFather->parent;
    if (x == father->leftSon)
    {
        Node* rightSon = x->rightSon;
        Node* bro = father->rightSon;
        attach(father, rightSon, left);
        attach(grandFather, bro, left);
        attach(father, grandFather, right);
        attach(x, father, right);
    }
    else if (x == father->rightSon)
    {
        Node* leftSon = x->leftSon;
        Node* bro = father->leftSon;
        attach(father, leftSon, right);
        attach(grandFather, bro, right);
        attach(father, grandFather, left);
        attach(x, father, left);
    }
    if (grandGrandFather != NULL)
    {
        if (grandGrandFather->leftSon == grandFather)
        {
            grandGrandFather->leftSon = x;
        }
        else if (grandGrandFather->rightSon == grandFather)
        {
            grandGrandFather->rightSon = x;
        }
    }
    x->parent = grandGrandFather;
}

void zigZag(Node* x)
{
    Node* father = x->parent;
    Node* grandFather = father->parent;
    Node* grandGrandFather = grandFather->parent;
    if (father->rightSon == x)
    {
        Node* leftSon = x->leftSon;
        Node* rightSon = x->rightSon;
        attach(x, father, left);
        attach(grandFather, rightSon, left);
        attach(father, leftSon, right);
        attach(x, grandFather, right);
    }
    else if (father->leftSon == x)
    {
        Node* leftSon = x->leftSon;
        Node* rightSon = x->rightSon;
        attach(x, father, right);
        attach(grandFather, leftSon, right);
        attach(father, rightSon, left);
        attach(x, grandFather, left);
    }
    if (grandGrandFather != NULL)
    {
        if (grandGrandFather->leftSon == grandFather)
        {
            grandGrandFather->leftSon = x;
        }
        else if (grandGrandFather->rightSon == grandFather)
        {
            grandGrandFather->rightSon = x;
        }
    }
    x->parent = grandGrandFather;
}

Node* splay(Node* x)
{
    if (x->parent == NULL)
    {
        return x;
    }
    if (x->parent->parent == NULL)
    {
        zig(x);
        return x;
    }
    if ((x->parent->leftSon == x && x->parent->parent->leftSon == x->parent)
        || (x->parent->rightSon == x && x->parent->parent->rightSon == x->parent))
    {
        zigZig(x);
    }
    else 
    {
        zigZag(x);
    }
    return splay(x);
}


Node* addNode(Node* root, int key, const char* value, Error* error)
{
    if (*error != NOT_ERROR)
    {
        return root;
    }
    char* copyValue = calloc(strlen(value) + 1, sizeof(char));
    if (copyValue == NULL)
    {
        *error = INSUFFICIENT_MEMORY;
        return root;
    }
    strcpy(copyValue, value);
    Node* newRoot = (Node*)calloc(1, sizeof(Node));
    if (newRoot == NULL)
    {
        *error = INSUFFICIENT_MEMORY;
        free(copyValue);
        return root;
    }
    if (root == NULL)
    {
        newRoot->key = key;
        newRoot->value = copyValue;
        return newRoot;
    }
    Node* currentRoot = root;
    while (currentRoot != NULL)
    {
        if (key > currentRoot->key)
        {
            if (currentRoot->rightSon == NULL)
            {
                newRoot->key = key;
                newRoot->value = copyValue;
                attach(currentRoot, newRoot, right);
                return splay(newRoot);
            }
            currentRoot = currentRoot->rightSon;
        }
        else if (key == currentRoot->key)
        {
            free(currentRoot->value);
            free(currentRoot);
            newRoot->value = copyValue;
            newRoot->key = key;
            return splay(currentRoot);
        }
        else
        {
            if (currentRoot->leftSon == NULL)
            {
                newRoot->key = key;
                newRoot->value = copyValue;
                attach(currentRoot, newRoot, left);
                return splay(newRoot);
            }
            currentRoot = currentRoot->leftSon;
        }
    }
    free(newRoot);
    free(copyValue);
    return root;
}

void search(Node** root, int key)
{
    Node* i = *root;
    while (i != NULL)
    {
        if (key > i->key)
        {
            i = i->rightSon;
        }
        else if (key < i->key)
        {
            i = i->leftSon;
        }
        else
        {
            *root = i;
            return;
        }
    }
    *root = NULL;
}

bool inTree(Node* root, int key)
{
    search(&root, key);
    return root != NULL;
}

Node* deleteNode(Node* root, int key, Error* error)
{
    if (*error != NOT_ERROR)
    {
        return root;
    }
    search(&root, key);
    if (root == NULL)
    {
        *error = ROOT_IS_MISSING;
        return root;
    }
    if (root->rightSon == NULL && root->leftSon == NULL)
    {
        Node* parent = root->parent;
        if (parent != NULL)
        {
            if (root->parent->rightSon == root)
            {
                root->parent->rightSon = NULL;
            }
            else
            {
                root->parent->leftSon = NULL;
            }
        }
        free(root->value);
        free(root);
        return (parent == NULL) ? NULL : splay(parent);
    }
    if (root->rightSon != NULL && root->leftSon != NULL)
    {
        Node* currentRoot = root;
        currentRoot = currentRoot->leftSon;
        while (currentRoot->rightSon != NULL)
        {
            currentRoot = currentRoot->rightSon;
        }
        if (currentRoot == root->leftSon)
        {
            Node* parent = root->parent;
            parent == NULL ? attach(currentRoot, root->rightSon, right)
                : attach(root->parent, root->leftSon, left);
            if (parent == NULL)
            {
                currentRoot->parent = NULL;
            }
            free(root->value);
            free(root);
            return parent == NULL ? currentRoot : splay(currentRoot->parent);
        }
        Node* currentRootParent = currentRoot->parent;
        root->key = currentRoot->key;
        char* newValue = calloc(strlen(root->value) + 1, sizeof(char));
        if (newValue == NULL)
        {
            *error = INSUFFICIENT_MEMORY;
            return root;
        }
        free(root->value);
        strcpy(newValue, currentRoot->value);
        root->value = newValue;
        currentRootParent->rightSon = NULL;
        free(currentRoot->value);
        free(currentRoot);
        return splay(currentRootParent);
    }
    if (root->parent == NULL)
    {
        root = root->rightSon == NULL ? root->leftSon : root->rightSon;
        if (root->parent != NULL)
        {
            free(root->parent->value);
        }
        free(root->parent);
        root->parent = NULL;
        return root;
    }
    Node* parent = root->parent;
    if (root->rightSon == NULL)
    {
         parent->leftSon == root ? attach(parent,root->leftSon,left)
             : attach(parent,root->leftSon, right);
    }
    else
    {
        parent->leftSon == root ? attach(parent, root->rightSon, left)
            : attach(parent, root->rightSon, right);
    }
    free(root->value);
    free(root);
    return splay(parent);
}

bool isFather(Node* tree, int parentKey, int childKey)
{
    search(&tree, childKey);
    return tree->parent->key == parentKey && tree->key == childKey;
}

char* getValue(Node* root, int key)
{
    search(&root, key);
    if (root == NULL)
    {
        return NULL;
    }
    return root->value;
}