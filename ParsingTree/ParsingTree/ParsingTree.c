#include "ParsingTree.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef enum VisitedNode
{
    nodeVisited,
    nodeNotVisited
} VisitedNode;

typedef struct Node
{
    struct Node* leftSon;
    struct Node* rightSon;
    struct Node* parent;
    char value;
    int number;
    VisitedNode isVisitedNode;
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

bool isOperator(char symbol)
{
    return symbol == '+' || symbol == '-'
        || symbol == '*' || symbol == '/';
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

Node* createNode(char array)
{
    Node* newRoot = (Node*)calloc(1, sizeof(Node));
    if (newRoot == NULL)
    {
        return NULL;
    }
    newRoot->value = array;
    newRoot->isVisitedNode = isOperator(array) ? nodeNotVisited : nodeVisited;
    newRoot->number = isOperator(array) ? 0 : array - '0';
    return newRoot;
}

Node* kek(char* array, int* counter, Node* node)
{
    if (*counter > 0 && node == NULL)
    {
        return NULL;
    }
    if (array[*counter] == '(' || array[*counter] == ')'
        || array[*counter] == ' ')
    {
        (*counter)++;
    }
    if (isOperator(array[*counter]))
    {
        Node* temporary = createNode(array[*counter]);
        if (temporary == NULL)
        {
            node = returnHead(node);
            deleteTree(&node);
            return NULL;
        }
        Node* operator = temporary;
        (*counter)++;
        attach(operator, kek(array, counter, operator), left);
        attach(operator, kek(array, counter, operator), right);
        return operator;
    }
    else
    {
        Node* operand = createNode(array[*counter]);
        if (operand == NULL)
        {
            node = returnHead(node);
            deleteTree(&node);
            return NULL;
        }
        (*counter)++;
        return operand;
    }
}

Node* buildTree(char* array)
{
    int counter = 0;
    Node* node = NULL;
    return kek(array, &counter, node);
}

void restoreField(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    restoreField(root->leftSon);
    restoreField(root->rightSon);
    if (isOperator(root->value))
    {
        root->isVisitedNode = nodeNotVisited;
    }
    else
    {
        root->isVisitedNode = nodeVisited;
    }
}

int findAnswer(Node* root, int* error)
{
    if (root == NULL)
    {
        *error = 1;
        return 0;
    }
    if (root->leftSon != NULL && root->rightSon != NULL && root->rightSon->isVisitedNode == nodeVisited && root->leftSon->isVisitedNode == nodeVisited && root->isVisitedNode == nodeNotVisited)
    {
        root->isVisitedNode = nodeVisited;
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
        if (root->parent != NULL)
        {
            return findAnswer(root->parent, error);
        }
        else
        {
            restoreField(root);
            return root->number;
        }
    }
    else if (root->leftSon != NULL && isOperator(root->leftSon->value) && root->leftSon->isVisitedNode == nodeNotVisited)
    {
        return findAnswer(root->leftSon, error);
    }
    else if (root->rightSon != NULL && isOperator(root->rightSon->value) && root->rightSon->isVisitedNode == nodeNotVisited)
    {
        return findAnswer(root->rightSon, error);
    }
    return findAnswer(root, error);
}

void printTree(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    printTree(root->leftSon);
    printTree(root->rightSon);
    printf("%c ", root->value);
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