#include <stdio.h>
#include <stdlib.h>

void test(int* a, int* b)
{
	printf("%d %d", a, b);	// a, b �� ��ü�� �ּ��̱� ������ �״�� �����ϸ� �ȴ�
}

int main()
{
	int a;
	int b;
	
	scanf("%d %d", &a, &b);	// a, b�� �ּҴ� ���� &a, &b�� ǥ�� �ȴ�.
	test(&a, &b);
	return 0; 
}
