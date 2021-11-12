#include "ParsingTree.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node
{
    struct Node* leftSon;
    struct Node* rightSon;
    struct Node* parent;
    char value;
    int number;
} Node;

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
    free(root);
}

void deleteTree(Node** root)
{
    deleteTreeRecursive(*root);
    *root = NULL;
}

Node* returnHead(Node* root)
{
    if (root == NULL)
    {
        return root;
    }
    while (root->parent != NULL)
    {
        root = root->parent;
    }
    return root;
}

int returnAnswer(Node* root)
{
    return root->number;
}

bool compare(char symbol)
{
    return symbol == '+' || symbol == '-'
        || symbol == '*' || symbol == '/';
}

Node* buildTree(char* array)
{
    int counter = 0;
    Node* tree = createTree();
    while (array[counter] != '\0')
    {
        if (array[counter] == '(' || array[counter] == ')' || array[counter] == ' ')
        {
            counter++;
            continue;
        }
        Node* newRoot = (Node*)calloc(1, sizeof(Node));
        if (newRoot == NULL)
        {
            return NULL;
        }
        if (tree == NULL)
        {
            newRoot->value = array[counter];
            tree = newRoot;
            if (array[counter] <= '9' && array[counter] >= '0')
            {
                newRoot->number = array[counter] - '0';
                if (array[counter + 1] != '\0')
                {

                }
                continue;
            }
            newRoot->number = 0;
            counter++;
            continue;
        }
        if (compare(array[counter]))
        {
            if (tree->leftSon == NULL && compare(tree->value))
            {
                tree->leftSon = newRoot;
                newRoot->parent = tree;
                newRoot->value = array[counter];
                newRoot->number = 0;
                tree = newRoot;
                counter++;
                continue;
            }
            else if (tree->rightSon == NULL && compare(tree->value))
            {
                tree->rightSon = newRoot;
                newRoot->parent = tree;
                newRoot->value = array[counter];
                newRoot->number = 0;
                tree = newRoot;
                counter++;
                continue;
            }
            while (tree->parent != NULL)
            {
                tree = tree->parent;
                if (tree->leftSon == NULL && compare(tree->value))
                {
                    tree->leftSon = newRoot;
                    newRoot->parent = tree;
                    newRoot->value = array[counter];
                    newRoot->number = 0;
                    counter++;
                    tree = newRoot;
                    break;
                }
                else if (tree->rightSon == NULL && compare(tree->value))
                {
                    tree->rightSon = newRoot;
                    newRoot->parent = tree;
                    newRoot->value = array[counter];
                    newRoot->number = 0;
                    counter++;
                    tree = newRoot;
                    break;
                }
            }
            continue;
        }
        if (array[counter] <= '9' && array[counter] >= '0')
        {
            if (compare(tree->value) && tree->leftSon == NULL)
            {
                tree->leftSon = newRoot;
                newRoot->parent = tree;
                newRoot->value = array[counter];
                newRoot->number = array[counter] - '0';
                counter++;
                continue;
            }
            else if (tree->rightSon == NULL && compare(tree->value))
            {
                tree->rightSon = newRoot;
                newRoot->parent = tree;
                newRoot->value = array[counter];
                newRoot->number = array[counter] - '0';
                counter++;
                continue;
            }
            while (tree->parent != NULL)
            {
                tree = tree->parent;
                if (tree->leftSon == NULL && compare(tree->value))
                {
                    tree->leftSon = newRoot;
                    newRoot->parent = tree;
                    newRoot->value = array[counter];
                    newRoot->number = array[counter] - '0';
                    counter++;
                    break;
                }
                else if (tree->rightSon == NULL && compare(tree->value))
                {
                    tree->rightSon = newRoot;
                    newRoot->parent = tree;
                    newRoot->value = array[counter];
                    newRoot->number = array[counter] - '0';
                    counter++;
                    break;
                }
            }
        }
    }
    return tree;
}

void findAnswer(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->parent == NULL && root->number != 0)
    {
        return;
    }
    if (root->leftSon != NULL && root->rightSon != NULL && root->leftSon->number != 0 && root->rightSon->number != 0 && compare(root->value))
    {
        if (root->value == '+')
        {
            root->number = root->leftSon->number + root->rightSon->number;
        }
        if (root->value == '-')
        {
            root->number = root->leftSon->number - root->rightSon->number;
        }
        if (root->value == '*')
        {
            root->number = root->leftSon->number * root->rightSon->number;
        }
        if (root->value == '/')
        {
            root->number = root->leftSon->number / root->rightSon->number;
        }
        findAnswer(root->parent);
    }
    if (root->leftSon != NULL && root->leftSon->number == 0)
    {
        findAnswer(root->leftSon);
    }
    if (root->rightSon != NULL && root->rightSon->number == 0)
    {
        findAnswer(root->rightSon);
    }
}

void printTree(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    printTree(root->leftSon);
    printTree(root->rightSon);
    printf("%c", (root->value));
}

Node* rightSon(Node* root)
{
    return root->rightSon;
}

Node* leftSon(Node* root)
{
    return root->leftSon;
}

Node* parent(Node* root)
{
    return root->parent;
}

char getValue(Node* root)
{
    return root->value;
}