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


Node* addNode(Node* root, int key, char* value)
{
    char* copyValue = calloc(100, sizeof(char));
    if (copyValue == NULL)
    {
        return NULL;
    }
    strcpy(copyValue, value);
    if (root == NULL)
    {
        Node* newRoot = (Node*)calloc(1, sizeof(Node));
        if (newRoot == NULL)
        {
            free(copyValue);
            return NULL;
        }
        newRoot->key = key;
        newRoot->value = copyValue;
        return newRoot;
    }
    Node* i = root;
    while (i != NULL)
    {
        if (key > i->key)
        {
            if (i->rightSon == NULL)
            {
                Node* newRoot = (Node*)calloc(1, sizeof(Node));
                if (newRoot == NULL)
                {
                    return NULL;
                }
                newRoot->key = key;
                newRoot->value = copyValue;
                i->rightSon = newRoot;
                newRoot->parent = i;
                return splay(newRoot);
            }
            i = i->rightSon;
        }
        else if (key == i->key)
        {
            free(i->value);
            i->value = copyValue;
            i->key = key;
            return splay(i);
        }
        else
        {
            if (i->leftSon == NULL)
            {
                Node* newRoot = (Node*)calloc(1, sizeof(Node));
                if (newRoot == NULL)
                {
                    return NULL;
                }
                newRoot->key = key;
                newRoot->value = copyValue;
                i->leftSon = newRoot;
                newRoot->parent = i;
                return splay(newRoot);
            }
            i = i->leftSon;
        }
    }
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
    if (root == NULL)
    {
        return false;
    }
    return true;
}

Node* deleteNode(Node* root, int key)
{
    search(&root, key);
    if (root == NULL)
    {
        return NULL;
    }
    if (root->rightSon != NULL && root->leftSon != NULL)
    {
        Node* i = root;
        Node* son = root->leftSon;
        root = root->leftSon;
        while (root->rightSon != NULL)
        {
            root = root->rightSon;
        }
        if (root == i->leftSon)
        {
            if (i->parent == NULL)
            {
                i->rightSon->parent = root;
                root->rightSon = i->rightSon;
                root->parent = NULL;
                free(i->value);
                free(i);
                return root;
            }
            i->parent->leftSon = i->leftSon;
            i->leftSon->parent = i->parent;
            free(i);
            return splay(root->parent);
        }
        Node* k = root->parent;
        i->key = root->key;
        root->parent->rightSon = NULL;
        root->parent = NULL;
        free(root->value);
        free(root);
        return splay(k);
    }
    if (root->rightSon == NULL && root->leftSon == NULL)
    {
        if (root->parent == NULL)
        {
            free(root->value);
            free(root);
            return NULL;
        }
        else
        {
            Node* parent = root->parent;
            if (root->parent->rightSon == root)
            {
                root->parent->rightSon = NULL;
                root->parent = NULL;
            }
            else if (root->parent->leftSon == root)
            {
                root->parent->leftSon = NULL;
                root->parent = NULL;
            }
            free(root->value);
            free(root);
            return splay(parent);
        }
    }
    if (root->rightSon == NULL && root->leftSon != NULL)
    {
        if (root->parent == NULL)
        {
            Node* j = root->leftSon;
            root->leftSon->parent = NULL;
            root->leftSon = NULL;
            free(root->value);
            free(root);
            return j;
        }
        Node* parent = root->parent;
        root->leftSon->parent = root->parent;
        if (root->parent->leftSon == root)
        {
            root->parent->leftSon = root->leftSon;
        }
        else if (root->parent->rightSon == root)
        {
            root->parent->rightSon = root->leftSon;
        }
        free(root->value);
        free(root);
        return splay(parent);
    }
    if (root->rightSon != NULL && root->leftSon == NULL)
    {
        if (root->parent == NULL)
        {
            Node* i = root->rightSon;
            root->rightSon->parent = NULL;
            root->rightSon = NULL;
            free(root->value);
            free(root);  
            return i;
        }
        Node* parent = root->parent;
        root->rightSon->parent = root->parent;
        if (root->parent->leftSon == root)
        {
            root->parent->leftSon = root->rightSon;
        }
        else if (root->parent->rightSon == root)
        {
            root->parent->rightSon = root->rightSon;
        }
        free(root->value);
        free(root);
        return splay(parent);
    }
    return NULL;
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