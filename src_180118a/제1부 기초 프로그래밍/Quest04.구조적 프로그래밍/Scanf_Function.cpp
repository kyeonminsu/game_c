#include <stdio.h>
#include <stdlib.h>

void test(int* a, int* b)
{
	printf("%d %d", a, b);	// a, b 값 자체가 주소이기 때문에 그대로 전달하면 된다
}

int main()
{
	int a;
	int b;
	
	scanf("%d %d", &a, &b);	// a, b의 주소는 각각 &a, &b로 표기 된다.
	test(&a, &b);
	return 0; 
}
