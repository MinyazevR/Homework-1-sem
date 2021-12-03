#include "ParsingTree.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node
{
    struct Node* leftSon;
    struct Node* rightSon;
    struct Node* parent;
    char symbol;
    int expressionValues;
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

Node* returnRoot(Node* node)
{
    if (node == NULL)
    {
        return node;
    }
    while (node->parent != NULL)
    {
        node = node->parent;
    }
    return node;
}

bool isOperator(char symbol)
{
    return symbol == '+' || symbol == '-'
        || symbol == '*' || symbol == '/';
}

void attach(Node* parent, Node* child, Direction direction)
{
    if (parent == NULL)
    {
        return;
    }
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

Node* createNode(char symbol)
{
    Node* newNode = (Node*)calloc(1, sizeof(Node));
    if (newNode == NULL)
    {
        return NULL;
    }
    newNode->symbol = symbol;
    newNode->expressionValues = isOperator(symbol) ? 0 : symbol - '0';
    return newNode;
}

Node* addNode(const char* array, int* counter, Node* node)
{
    if (*counter > 0 && node == NULL)
    {
        return NULL;
    }
    while (array[*counter] == '(' || array[*counter] == ')'
        || array[*counter] == ' ')
    {
        (*counter)++;
    }
    if (isOperator(array[*counter]))
    {
        Node* temporary = createNode(array[*counter]);
        if (temporary == NULL)
        {
            node = returnRoot(node);
            deleteTree(&node);
            return NULL;
        }
        Node* operator = temporary;
        (*counter)++;
        attach(operator, addNode(array, counter, operator), left);
        attach(operator, addNode(array, counter, operator), right);
        return operator;
    }
    Node* operand = createNode(array[*counter]);
    if (operand == NULL)
    {
        node = returnRoot(node);
        deleteTree(&node);
        return NULL;
    }
    (*counter)++;
    return operand;
}

Node* buildTree(const char* array)
{
    int counter = 0;
    Node* node = NULL;
    return addNode(array, &counter, node);
}

int findAnswer(Node* root, int* error)
{
    if (*error != 0)
    {
        return 0;
    }
    if (root == NULL)
    {
        *error = 1;
        return 0;
    }
    if (root->rightSon == NULL && root->leftSon == NULL)
    {
        return root->expressionValues;
    }
    if (root->leftSon != NULL)
    {
        root->leftSon->expressionValues = findAnswer(root->leftSon, error);
    }
    if (root->rightSon != NULL)
    {
        root->rightSon->expressionValues = findAnswer(root->rightSon, error);
    }
    if (root->rightSon != NULL && root->leftSon != NULL)
    {
        if (root->symbol == '+')
        {
            root->expressionValues = root->leftSon->expressionValues + root->rightSon->expressionValues;
        }
        if (root->symbol == '-')
        {
            root->expressionValues = root->leftSon->expressionValues - root->rightSon->expressionValues;
        }
        if (root->symbol == '*')
        {
            root->expressionValues = root->leftSon->expressionValues * root->rightSon->expressionValues;
        }
        if (root->symbol == '/')
        {
            root->expressionValues = root->leftSon->expressionValues / root->rightSon->expressionValues;
        }
    }
    return root->expressionValues;
}

void printTreeRecursive(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    if (isOperator(root->symbol))
    {
        printf("%c ", '(');
        printf("%c ", root->symbol);
    }
    else if (root->parent != NULL && root->parent->rightSon == root)
    {
        printf("%c ", root->symbol);
        printf("%c ", ')');
    }
    else
    {
        printf("%c ", root->symbol);
    }
    printTreeRecursive(root->leftSon);
    printTreeRecursive(root->rightSon);
}

void printTree(Node* root)
{
    printTreeRecursive(root);
    printf("%c", ')');
}