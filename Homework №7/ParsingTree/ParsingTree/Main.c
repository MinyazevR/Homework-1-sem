#include "TestParsingTree.h"

int main()
{
    if (!testFindAnswer() || !testBuildTree())
    {
        return -1;
    }
}