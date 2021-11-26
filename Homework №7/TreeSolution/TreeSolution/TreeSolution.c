#include "../../ParsingTree/ParsingTree/ParsingTree.h"
#include <stdio.h>
#include <malloc.h>

char* readExpression(const char* fileName, int* error)
{
    FILE* file = fopen(fileName, "r");
    if (file == NULL)
    {
        *error = 1;
        return NULL;
    }
    char* expression = calloc(100, sizeof(char));
    if (expression == NULL)
    {
        *error = 3;
        fclose(file);
        return NULL;
    }
    while (!feof(file))
    {
        fgets(expression, 99, file);
    }
    if (expression == NULL)
    {
        *error = 2;
    }
    fclose(file);
    return expression;
}

int main()
{
    int error = 0;
    const char* expression = readExpression("Expression.txt", &error);
    if (error == 1)
    {
        printf("Could not open the file");
        return -1;
    }
    if (error == 2)
    {
        printf("Could not read expression from file");
        return -1;
    }
    if (error == 3)
    {
        printf("Memory not allocated");
        return -1;
    }
    Node* tree = buildTree(expression);
    const int answer = findAnswer(tree, &error);
    if (error == 1)
    {
        return -1;
    }
    printf("value of the expression : %d\n", answer);
    printTree(tree);
    deleteTree(&tree);
}