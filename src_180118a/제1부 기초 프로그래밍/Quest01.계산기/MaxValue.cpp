#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a;	// �Է¿�
	int b;	// �Է¿�
	int max;	// ū ���� ������ ����
	
	printf("�� ���� �Է� �ϼ���: ");
	scanf("%d %d", &a, &b);
	
	if( a < b)
	{
		max = b;	
	} 
	else
	{
		max = a;
	}
	printf("ū ���� %d �Դϴ�.\n", max);
}
