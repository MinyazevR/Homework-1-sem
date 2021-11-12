#include "../../ParsingTree/ParsingTree/ParsingTree.h"
#include <stdio.h>

Node* readExpression(Node* tree, const char* fileName, int* error)
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
    Node* tree = createTree();
    int error = 0;
    tree = readExpression(tree, "Expression.txt", &error);
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
    tree = returnHead(tree);
    findAnswer(tree);
    const int answer = returnAnswer(tree);
    printf("Meaning of the expression : %d\n", answer);
    printTree(tree);
    deleteTree(&tree);
}