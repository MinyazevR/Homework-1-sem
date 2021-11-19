#include "../../ParsingTree/ParsingTree/ParsingTree.h"
#include <stdio.h>

Node* readExpression(const char* fileName, int* error)
{
    FILE* file = fopen(fileName, "r");
    if (file == NULL)
    {
        *error = 1;
        return NULL;
    }
    char expression[100] = { '\0' };
    return buildTree(fgets(expression, 100, file));
    fclose(file);
}

int main()
{
    int error = 0;
    Node* tree = readExpression("Expression.txt", &error);
    if (error == 1)
    {
        deleteTree(&tree);
        printf("Could not open the file");
        return -1;
    }
    if (tree == NULL)
    {
        printf("Could not read expression from file");
        return -1;
    }
    const int answer = findAnswer(tree, &error);
    if (error == 1)
    {
        return -1;
    }
    printf("value of the expression : %d\n", answer);
    printTree(tree);
    deleteTree(&tree);
}