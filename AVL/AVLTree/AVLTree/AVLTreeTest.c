#include "AVLTree.h"
#include "AVLTreeTest.h"

bool addNodeTest()
{
    Node* tree = createTree();
    int error = 0;
    tree = addNode(tree, 12, "firstString", &error);
    tree = addNode(tree, 4, "secondString", &error);
    bool firstResult = invariant(tree);
    tree = addNode(tree, 45, "value", &error);
    bool secondResult = invariant(tree);
    tree = addNode(tree, 34, "hello world", &error);
    bool thirdResult = invariant(tree);
    tree = addNode(tree, 29, "4 points", &error);
    bool fourthResult = invariant(tree);
    tree = addNode(tree, 223, "AVLTree", &error);
    bool fifthResult = invariant(tree);
    tree = addNode(tree, 223, "addNode", &error);
    bool sixthResult = invariant(tree);
    tree = addNode(tree, 52, "i want a session", &error);
    bool seventhResult = invariant(tree);
    tree = addNode(tree, 24, "twenty", &error);
    bool eighthResult = invariant(tree);
    tree = addNode(tree, 2, "lastValue", &error);
    bool ninthResult = invariant(tree);
    deleteTree(&tree);
    return firstResult && secondResult && thirdResult && fourthResult && fifthResult
        && sixthResult && seventhResult && eighthResult && ninthResult;
}

bool firstDeleteNodeTest()
{
    Node* tree = createTree();
    int error = 0;
    tree = addNode(tree, 3, "firstValue", &error);
    tree = addNode(tree, 28, "assdf", &error);
    tree = addNode(tree, 12, "xzcv", &error);
    tree = addNode(tree, 344, "htrhrth", &error);
    tree = addNode(tree, 21, "wertyy", &error);
    tree = addNode(tree, 223, "fghgf", &error);
    tree = addNode(tree, 52, "asfasf", &error);
    tree = addNode(tree, -123, "qwrrwq", &error);
    deleteNode(&tree, 52, &error);
    deleteNode(&tree, 344, &error);
    bool firstResult = invariant(tree);
    deleteNode(&tree, 28, &error);
    bool secondResult = invariant(tree);
    deleteNode(&tree, 21, &error);
    bool thirdResult = invariant(tree);
    deleteNode(&tree, 223, &error);
    bool fourthResult = invariant(tree);
    deleteTree(&tree);
    return firstResult && secondResult && thirdResult && fourthResult && error == 0;
}

bool secondDeleteNodeTest()
{
    Node* tree = createTree();
    int error = 0;
    tree = addNode(tree, 46, "frt", &error);
    tree = addNode(tree, 14, "luej", &error);
    tree = addNode(tree, 23, "  ", &error);
    tree = addNode(tree, -3, "(adsdsd)", &error);
    tree = addNode(tree, 1, "firstValue", &error);
    tree = addNode(tree, -22, "fcv", &error);
    tree = addNode(tree, 5, "fi", &error);
    tree = addNode(tree, -13, "kek", &error);
    deleteNode(&tree, 21, &error);
    bool firstResult = invariant(tree);
    deleteNode(&tree, 12, &error);
    deleteNode(&tree, 152, &error);
    bool secondResult = invariant(tree);
    deleteNode(&tree, 344, &error);
    bool thirdResult = invariant(tree);
    deleteTree(&tree);
    return firstResult && secondResult && thirdResult && error == 0;
}
bool allTestResult()
{
    return addNodeTest() && secondDeleteNodeTest() && firstDeleteNodeTest();
}