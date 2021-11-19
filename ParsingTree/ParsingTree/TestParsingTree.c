#include "ParsingTree.h"
#include "TestParsingTree.h"

bool testFindAnswer()
{
    Node* firstTree = createTree();
    firstTree = buildTree("- * + 4 3 5 * 2 7");
    firstTree = returnHead(firstTree);
    int error = 0;
    const int firstAnswer = findAnswer(firstTree, &error);
    deleteTree(&firstTree);

    Node* secondTree = createTree();
    secondTree = buildTree("/+*+5678+-+5693");
    secondTree = returnHead(secondTree);
    findAnswer(secondTree, &error);
    const int secondAnswer = returnAnswer(secondTree);
    deleteTree(&secondTree);

    Node* thirdTree = createTree();
    thirdTree = buildTree("*+112");
    thirdTree = returnHead(thirdTree);
    findAnswer(thirdTree, &error);
    const int thirdAnswer = returnAnswer(thirdTree);
    deleteTree(&thirdTree);

    Node* fourthTree = createTree();
    fourthTree = buildTree("+-556");
    fourthTree = returnHead(fourthTree);
    findAnswer(fourthTree, &error);
    const int fourthAnswer = returnAnswer(fourthTree);
    deleteTree(&fourthTree);

    return firstAnswer == 21 && secondAnswer == 17 && thirdAnswer == 4 && fourthAnswer == 6 ;
}

bool testBuildTree()
{
    Node* firstTree = createTree();
    firstTree = buildTree("*+142");
    const char firstSymbol = getValue(firstTree);
    const char secondSymbol = getValue(rightSon(firstTree));
    const char thirdSymbol = getValue(leftSon(firstTree));
    const char fourthSymbol = getValue(leftSon(leftSon(firstTree)));
    const char fifthSymbol = getValue(rightSon(leftSon(firstTree)));
    deleteTree(&firstTree);
    return firstSymbol == '*' && secondSymbol == '2' && thirdSymbol == '+' && fourthSymbol == '1' && fifthSymbol == '4';
}