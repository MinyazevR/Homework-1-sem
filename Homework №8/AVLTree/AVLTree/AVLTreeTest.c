#include "AVLTree.h"
#include "AVLTreeTest.h"

bool addNodeTest()
{
    Node* tree = createTree();
    int error = 0;
    tree = addNode(tree, "firstString", "firstString", &error);
    tree = addNode(tree, "secondString", "secondString", &error);
    bool firstResult = invariant(tree);
    tree = addNode(tree, "value", "value", &error);
    bool secondResult = invariant(tree);
    tree = addNode(tree, "hello world", "hello world", &error);
    bool thirdResult = invariant(tree);
    tree = addNode(tree, "4 points", "4 points", &error);
    bool fourthResult = invariant(tree);
    tree = addNode(tree, "AVLTree", "AVLTree", &error);
    bool fifthResult = invariant(tree);
    tree = addNode(tree, "addNode", "addNode", &error);
    bool sixthResult = invariant(tree);
    tree = addNode(tree, "i want a session", "i want a session", &error);
    bool seventhResult = invariant(tree);
    tree = addNode(tree, "twenty", "twenty", &error);
    bool eighthResult = invariant(tree);
    tree = addNode(tree, "lastValue", "lastValue", &error);
    bool ninthResult = invariant(tree);
    deleteTree(&tree);
    return firstResult && secondResult && thirdResult && fourthResult && fifthResult
        && sixthResult && seventhResult && eighthResult && ninthResult;
}

bool firstDeleteNodeTest()
{
    Node* tree = createTree();
    int error = 0;
    tree = addNode(tree, "firstValue", "firstValue", &error);
    tree = addNode(tree, "assdf", "assdf", &error);
    tree = addNode(tree, "xzcv", "xzcv", &error);
    tree = addNode(tree, "htrhrth", "htrhrth", &error);
    tree = addNode(tree, "wertyy", "wertyy", &error);
    tree = addNode(tree, "fghgf", "fghgf", &error);
    tree = addNode(tree, "asfasf", "asfasf", &error);
    tree = addNode(tree, "qwrrwq", "qwrrwq", &error);
    deleteNode(&tree, "asfasf", &error);
    deleteNode(&tree, "htrhrth", &error);
    bool firstResult = invariant(tree);
    deleteNode(&tree, "assdf", &error);
    bool secondResult = invariant(tree);
    deleteNode(&tree, "wertyy", &error);
    bool thirdResult = invariant(tree);
    deleteNode(&tree, "fghgf", &error);
    bool fourthResult = invariant(tree);
    deleteTree(&tree);
    return firstResult && secondResult && thirdResult && fourthResult && error == 0;
}

bool secondDeleteNodeTest()
{
    Node* tree = createTree();
    int error = 0;
    tree = addNode(tree, "frt", "frt", &error);
    tree = addNode(tree, "luej", "luej", &error);
    tree = addNode(tree, " ", " ", &error);
    tree = addNode(tree, "(adsdsd)", "(adsdsd)", &error);
    tree = addNode(tree, "firstValue", "firstValue", &error);
    tree = addNode(tree, "fcv", "fcv", &error);
    tree = addNode(tree, "fi", "fi", &error);
    tree = addNode(tree, "kek", "kek", &error);
    deleteNode(&tree, "kek", &error);
    bool firstResult = invariant(tree);
    deleteNode(&tree, "luej", &error);
    deleteNode(&tree, "fcv", &error);
    bool secondResult = invariant(tree);
    deleteNode(&tree, "xzczxc", &error);
    bool thirdResult = invariant(tree);
    deleteTree(&tree);
    return firstResult && secondResult && thirdResult && error == 0;
}
bool allTestResult()
{
    return addNodeTest() && firstDeleteNodeTest() && secondDeleteNodeTest();
}