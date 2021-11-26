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
<<<<<<< HEAD
            *error = INSUFFICIENT_MEMORY;
            free(copyValue);
            return root;
=======
            free(copyValue);
            return NULL;
>>>>>>> parent of e8f39c0 (added work with errors, changed the functions of adding and removing nodes)
        }
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
                Node* newRoot = (Node*)calloc(1, sizeof(Node));
                if (newRoot == NULL)
                {
<<<<<<< HEAD
                    *error = INSUFFICIENT_MEMORY;
                    free(copyValue);
                    return root;
=======
                    return NULL;
>>>>>>> parent of e8f39c0 (added work with errors, changed the functions of adding and removing nodes)
                }
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
            currentRoot->value = copyValue;
            return splay(currentRoot);
        }
        else
        {
            if (currentRoot->leftSon == NULL)
            {
                Node* newRoot = (Node*)calloc(1, sizeof(Node));
                if (newRoot == NULL)
                {
<<<<<<< HEAD
                    *error = INSUFFICIENT_MEMORY;
                    free(copyValue);
                    return root;
=======
                    return NULL;
>>>>>>> parent of e8f39c0 (added work with errors, changed the functions of adding and removing nodes)
                }
                newRoot->key = key;
                newRoot->value = copyValue;
                attach(currentRoot, newRoot, left);
                return splay(newRoot);
            }
            currentRoot = currentRoot->leftSon;
        }
    }
    free(copyValue);
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

bool inTree(Node* root, int key)
{
<<<<<<< HEAD
    Node* searchResult = search(root, key);
    return searchResult != NULL;
}

void deleteNode(Node** root, int key, Error* error)
{
    if (*error != NOT_ERROR)
    {
        return;
    }
    Node* searchResult = search(*root, key);
    if (searchResult == NULL)
    {
        *error = ROOT_IS_MISSING;
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
            }
            else
            {
                (*root)->parent->leftSon = NULL;
=======
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
>>>>>>> parent of e8f39c0 (added work with errors, changed the functions of adding and removing nodes)
            }
            i->parent->leftSon = i->leftSon;
            i->leftSon->parent = i->parent;
            free(i);
            return splay(root->parent);
        }
<<<<<<< HEAD
        free((*root)->value);
        free(*root);
        (*root) = (parent != NULL) ? splay(parent) : NULL;
        return;
    }
    if ((*root)->rightSon != NULL && (*root)->leftSon != NULL)
    {
        Node* currentRoot = *root;
        currentRoot = currentRoot->leftSon;
        while (currentRoot->rightSon != NULL)
=======
        Node* k = root->parent;
        i->key = root->key;
        i->value = root->value;
        root->parent->rightSon = NULL;
        root->parent = NULL;
        free(root->value);
        free(root);
        return splay(k);
    }
    if (root->rightSon == NULL && root->leftSon == NULL)
    {
        if (root->parent == NULL)
>>>>>>> parent of e8f39c0 (added work with errors, changed the functions of adding and removing nodes)
        {
            free(root->value);
            free(root);
            return NULL;
        }
<<<<<<< HEAD
        if (currentRoot == (*root)->leftSon)
        {
            Node* parent = (*root)->parent;
            attach(currentRoot, (*root)->rightSon, right);
            if (parent == NULL)
=======
        else
        {
            Node* parent = root->parent;
            if (root->parent->rightSon == root)
>>>>>>> parent of e8f39c0 (added work with errors, changed the functions of adding and removing nodes)
            {
                root->parent->rightSon = NULL;
                root->parent = NULL;
            }
            else if (root->parent->leftSon == root)
            {
                root->parent->leftSon = NULL;
                root->parent = NULL;
            }
<<<<<<< HEAD
            else
            {
                parent->rightSon == (*root) ? attach((*root)->parent, (*root)->leftSon, right) : attach((*root)->parent, (*root)->leftSon, left);
            }
            free((*root)->value);
            free(*root);
            *root = parent == NULL ? currentRoot : splay(currentRoot->parent);
            return;
        }
        Node* currentRootParent = currentRoot->parent;
        (*root)->key = currentRoot->key;
        char* newValue = calloc(strlen((currentRoot)->value) + 1, sizeof(char));
        if (newValue == NULL)
        {
            *error = INSUFFICIENT_MEMORY;
            return;
        }
        free((*root)->value);
        strcpy(newValue, currentRoot->value);
        (*root)->value = newValue;
        currentRootParent->rightSon = NULL;
        free(currentRoot->value);
        free(currentRoot);
        *root = splay(currentRootParent);
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
    if ((*root)->rightSon == NULL)
    {
         parent->leftSon == *root ? attach(parent,(*root)->leftSon,left)
             : attach(parent,(*root)->leftSon, right);
    }
    else
    {
        parent->leftSon == *root ? attach(parent, (*root)->rightSon, left)
            : attach(parent, (*root)->rightSon, right);
    }
    free((*root)->value);
    free(*root);
    *root = splay(parent);
    return;
=======
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
>>>>>>> parent of e8f39c0 (added work with errors, changed the functions of adding and removing nodes)
}

bool invariant(Node* tree, int parentKey, int childKey)
{
    Node* searchResult = search(tree, childKey);
    return searchResult->parent->key == parentKey && searchResult->key == childKey;
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