#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// function that returns the result depending on the signs of the exponent and the base of the degree (double for degrees of type 5^(-4) = 0.0016). = 0.0016).
double resultFromSign(double exponentiationResult, int basisOfDegree, int degreeIndicator)
{
    if (basisOfDegree > 0 && degreeIndicator < 0)
    {
        return 1 / exponentiationResult;
    }

    if (basisOfDegree > 0 && degreeIndicator > 0)
    {
        return exponentiationResult;
    }

    if (basisOfDegree < 0 && degreeIndicator > 0)
    {
        if (degreeIndicator % 2 != 0)
        {
            return -exponentiationResult;
        }

        if (degreeIndicator % 2 == 0)
        {
            return exponentiationResult;
        }
    }

    if (basisOfDegree < 0 && degreeIndicator < 0)
    {
        if (degreeIndicator % 2 != 0)
        {
            return -1 / exponentiationResult;
        }

        if (degreeIndicator % 2 == 0)
        {
            return 1 / exponentiationResult;
        }
    }

    if (basisOfDegree != 0 && degreeIndicator == 0)
    {
        return 1;
    }
    return 0;
}

// exponentiation in O (log n)
double effectiveExponentiation(int basisOfDegree, int degreeIndicator)
{
    double exponentiationResult = 1;
    int absoluteValueDegreeIndicator = abs(degreeIndicator);
    double absoluteValueBasisOfDegree = abs(basisOfDegree);
    while (absoluteValueDegreeIndicator > 0)
    {
        if (absoluteValueDegreeIndicator % 2 == 0)
        {
            absoluteValueDegreeIndicator = absoluteValueDegreeIndicator / 2;
            absoluteValueBasisOfDegree *= absoluteValueBasisOfDegree;
        }
        else
        {
            absoluteValueDegreeIndicator--;
            exponentiationResult *= absoluteValueBasisOfDegree;
        }
    }
    exponentiationResult = resultFromSign(exponentiationResult, basisOfDegree, degreeIndicator);
    return exponentiationResult;
}

// exponentiation in linear time
double ineffectiveExponentiation(int basisOfDegree, int degreeIndicator)
{
    double exponentiationResult = 1;
    int absoluteValueDegreeIndicator = abs(degreeIndicator);
    int absoluteValueBasisOfDegree = abs(basisOfDegree);
    for (int i = 1; i <= absoluteValueDegreeIndicator; i++)
    {
        exponentiationResult *= absoluteValueBasisOfDegree;
    }
    exponentiationResult = resultFromSign(exponentiationResult, basisOfDegree, degreeIndicator);
    return exponentiationResult;
}

bool testCorrectExponentiation()
{
    return effectiveExponentiation(-1, 5) == -1 && ineffectiveExponentiation(-1, 5) == -1
    && effectiveExponentiation(0, 5) == 0 && ineffectiveExponentiation(0, 5) == 0
    && effectiveExponentiation(5, 0) == 1 && ineffectiveExponentiation(5, 0) == 1
    && effectiveExponentiation(-5, -2) == 0.04 && effectiveExponentiation(2, -5) == 0.03125
    && ineffectiveExponentiation(12, 4) == 20736 && ineffectiveExponentiation(2, -4) == 0.0625;
}

int main(int argc, char* argv[])
{
    if (!testCorrectExponentiation())
    {
        printf("The test failed\n");
        return -1;
    }
    if (argc != 0)
    {
        return 0;
    }
    printf("Enter the degree base\n");
    int basisOfDegree = 0;
    scanf_s("%d", &basisOfDegree);
    printf("Enter the degree indicator\n");
    int degreeIndicator = 0;
    scanf_s("%d", &degreeIndicator);
    if (basisOfDegree == 0 && degreeIndicator == 0)
    {
        printf("The expression doesn't make sense.");
        return 0;
    }
    printf("Exponentiation in O (log n) : %.16lf\n\n", effectiveExponentiation(basisOfDegree, degreeIndicator));
    printf("Exponentiation in linear time : %.16lf\n", ineffectiveExponentiation(basisOfDegree, degreeIndicator));
}