#include "ParsingTree.h"
#include "TestParsingTree.h"

bool testFindAnswer()
{
    Node* firstTree = createTree();
    firstTree = buildTree("- * + 4 3 5 * 2 7");
    firstTree = returnHead(firstTree);
    findAnswer(firstTree);
    const int firstAnswer = returnAnswer(firstTree);
    deleteTree(&firstTree);

    Node* secondTree = createTree();
    secondTree = buildTree("/ (+ * + 5 6 7 8) (+ - + 5 6 9 3)");
    secondTree = returnHead(secondTree);
    findAnswer(secondTree);
    const int secondAnswer = returnAnswer(secondTree);
    deleteTree(&secondTree);

    Node* thirdTree = createTree();
    thirdTree = buildTree("(* (+ 1 1) 2)");
    thirdTree = returnHead(thirdTree);
    findAnswer(thirdTree);
    const int thirdAnswer = returnAnswer(thirdTree);
    deleteTree(&thirdTree);

    return firstAnswer == 21 && secondAnswer == 17 && thirdAnswer == 4 ;
}

bool testBuildTree()
{
    Node* firstTree = createTree();
    firstTree = buildTree("(* (+ 1 4) 2)");
    const char firstSymbol = getValue(firstTree);
    const char secondSymbol = getValue(rightSon(firstTree));
    const char thirdSymbol = getValue(leftSon(firstTree));
    const char fourthSymbol = getValue(leftSon(leftSon(firstTree)));
    const char fifthSymbol = getValue(rightSon(leftSon(firstTree)));
    deleteTree(&firstTree);
    return firstSymbol == '*' && secondSymbol == '2' && thirdSymbol == '+' && fourthSymbol == '1' && fifthSymbol == '4';
}