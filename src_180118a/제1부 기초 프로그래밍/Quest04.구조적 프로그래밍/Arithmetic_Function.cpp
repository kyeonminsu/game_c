#include <stdio.h>
#include <stdlib.h>

void InputData(int* a, int* b)
{
	printf("input 2 data: ");
	scanf("%d %d", a, b);
}

void CalData(int a, int b, int* c, int* d, int* e, float* f)
{
	*c=a+b;
	*d=a-b;
	*e=a*b;
	*f=(float)a/b;
}

void PrintData(int a, int b, int c, int d, int e, float f)
{
	printf("%d + %d = %d\n", a, b, c);
	printf("%d - %d = %d\n", a, b, d);
	printf("%d * %d = %d\n", a, b, e);
	printf("%d / %d = %.2f\n", a, b, f);
}

int main()
{
	int a;
	int b;
	
	int c;
	int d;
	int e;
	float f;
	
	InputData(&a, &b);
	
	CalData(a, b, &c, &d, &e, &f);
	
	PrintData(a, b, c, d, e, f);
	
	return 0;
}
