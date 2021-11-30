#include <stdio.h>

int main(int argc, char* argv[])
{   
	if (argc != 0)
	{
		return 0;
	}
	int x, y;
	printf("Enter õ\n");
	scanf_s("%d", &x);
	printf("Enter y\n");
	scanf_s("%d", &y);
	x = x ^ y;
	y = x ^ y;
	x = x ^ y;
	printf("new value x = %d\n", x);
	printf("new value y = %d\n", y);
}