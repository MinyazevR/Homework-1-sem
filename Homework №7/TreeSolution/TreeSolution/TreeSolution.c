#include "../../ParsingTree/ParsingTree/ParsingTree.h"
#include <stdio.h>
#include <malloc.h>

const char* readExpression(const char* fileName, int* error)
{
    FILE* file = fopen(fileName, "r");
    if (file == NULL)
    {
        *error = 1;
        return NULL;
    }
    // The size of the expression in the file is limited to 99 characters
    char* expression = calloc(100, sizeof(char));
    if (expression == NULL)
    {
        *error = 3;
        fclose(file);
        return NULL;
    }
    const char* result = fgets(expression, 100, file);
    if (result == NULL)
    {
        free(expression);
        *error = 2;
    }
    fclose(file);
    return result;
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
    free(expression);
    const int answer = findAnswer(tree, &error);
    if (error == 1)
    {
        return -1;
    }
    printf("value of the expression : %d\n", answer);
    printTree(tree);
    deleteTree(&tree);
}