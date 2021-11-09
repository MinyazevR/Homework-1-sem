#include "Tree.h"
#include "TestTree.h"

int main()
{
    if (!testAddNode() || !testDeleteNode() || !testInTree() || !testGetValue())
    {
        return -1;
    }
}