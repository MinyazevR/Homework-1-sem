#include "TestTree.h"
#include "Tree.h"
#include <string.h>

bool testAddNode()
{
    Node* tree = createTree();
    tree = addNode(tree, 3, "asdadsdsa");
    tree = addNode(tree, 5, "sdadad");
    bool firstCheck = isFather(tree, 5, 3);
    tree = addNode(tree, 1, "wdwddw");
    bool secondCheck = isFather(tree, 1, 3);
    bool thirdCheck = isFather(tree, 3, 5);
    tree = addNode(tree, 6, "afwfwfw");
    bool fourthCheck = isFather(tree, 6, 1);
    bool fifthCheck = isFather(tree, 1, 5);
    bool sixthCheck = isFather(tree, 5, 3);
    tree = addNode(tree, 2, "adwdwd");
    bool seventhCheck = isFather(tree, 2, 1);
    bool eighthCheck = isFather(tree, 2, 6);
    bool ninthCheck = isFather(tree, 6, 3);
    bool tenthCheck = isFather(tree, 3, 5);
    deleteTree(&tree);
    return firstCheck && secondCheck && thirdCheck 
        && fourthCheck && fifthCheck && sixthCheck 
        && seventhCheck && eighthCheck && ninthCheck && tenthCheck;
}

bool testDeleteNode()
{
    Node* tree = createTree();
    tree = addNode(tree, 3, "Hello World");
    tree = addNode(tree, 8, "Hello army");
    tree = addNode(tree, 1, "AVL tree");
    tree = addNode(tree, -8, "^-^");
    tree = addNode(tree, 12, "Test");
    tree = addNode(tree, 2, "git commit");
    tree = deleteNode(tree, 12);
    bool firstCheck = inTree(tree, 12);
    tree = deleteNode(tree, 1);
    bool secondCheck = inTree(tree, 1);
    tree = deleteNode(tree, -8);
    bool thirdCheck = inTree(tree, -8);
    deleteTree(&tree);
    return !firstCheck && !secondCheck && !thirdCheck;
}

bool testInTree()
{
    Node* tree = createTree();
    tree = addNode(tree, 3, "cyclic list");
    tree = addNode(tree, -123, "Memory link");
    tree = addNode(tree, 10, "git checkout -b");
    tree = addNode(tree, -5, "eeeeee");
    tree = addNode(tree, 12, "stormbringer");
    tree = addNode(tree, 2, "i surrender");
    bool firstCheck = inTree(tree, 3);
    bool secondCheck = inTree(tree, -5);
    bool thirdCheck = inTree(tree, 12);
    bool fourthCheck = inTree(tree, 2);
    bool fifthCheck = inTree(tree,-123);

    bool sixthCheck = inTree(tree, 2021);
    tree = deleteNode(tree, 2);
    bool seventhCheck = inTree(tree, 2);
    bool eighthCheck = inTree(tree, 0);
    tree = deleteNode(tree, -123);
    bool ninthCheck = inTree(tree, -123);
    bool tenthCheck = inTree(tree, -47);
    deleteTree(&tree);
    return firstCheck && secondCheck && thirdCheck
        && fourthCheck && fifthCheck && !sixthCheck
        && !seventhCheck && !eighthCheck && !ninthCheck && !tenthCheck;
}

bool testGetValue()
{
    Node* tree = createTree();
    tree = addNode(tree, 3, "cyclic list");
    tree = addNode(tree, 10, "git checkout -b");
    const char* firstValue = getValue(tree, 3);
    const char* secondValue = getValue(tree, 4);
    const char* thirdValue = getValue(tree, 10);
    bool result = strcmp(firstValue, "cyclic list") == 0 && strcmp(thirdValue, "git checkout -b") == 0 && secondValue == NULL;
    deleteTree(&tree);
    return result;
}
