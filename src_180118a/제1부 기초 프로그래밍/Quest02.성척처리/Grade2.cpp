#include <stdio.h>
#include <stdlib.h>

int main()
{
	int total;
	int i;
	int data[100];
	
	for(i=0; i<100; i++)
	{
		data[i]=rand()%101;
	}
	
	total=0;	// ���� �ʱ�ȭ
	for(i=0; i<100; i++)	// 100�� �ݺ��ϸ鼭 �迭���� 1���� ������, total�� ������
	{
		total = total + data[i];
	}
	
	printf("total:%d\n", total);	// ����ϱ� 
}
