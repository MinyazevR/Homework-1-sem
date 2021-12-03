#include "ParsingTree.h"
#include "TestParsingTree.h"

bool testFindAnswer()
{
    Node* firstTree = buildTree("1");
    int error = 0;
    const int firstAnswer = findAnswer(firstTree, &error);
    deleteTree(&firstTree);

    Node* secondTree = buildTree("(/ (+ (* (+ 5 6) 7) 8) (+ (- (+ 5 6) 9) 3))");
    const int secondAnswer = findAnswer(secondTree, &error);
    deleteTree(&secondTree);

    Node* thirdTree = buildTree("(* (+ 1 1) 2)");
    const int thirdAnswer = findAnswer(thirdTree, &error);
    deleteTree(&thirdTree);

    Node* fourthTree = buildTree("(+ (- 5 5) 6)");
    const int fourthAnswer = findAnswer(fourthTree, &error);
    deleteTree(&fourthTree);

    return firstAnswer == 1 && secondAnswer == 17 && thirdAnswer == 4 && fourthAnswer == 6 && error == 0;
}