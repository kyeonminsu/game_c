#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	// ���� ����
	int i;
	int j;
	int data[6];
	
	// �ʱ�ȭ
	srand(time(NULL));
	
	// ���� �����
	for(i=0; i<6; i++)
	{
		data[i]=rand()%45 + 1;
		for(j=0; j<i; j++)
		{
			if(data[i] == data[j])
			{
				i--;
				break;
			}
		}
	}
	
	// ���� ���� ����ϱ�
	for(i=0; i<6; i++)
	{
		printf("%d\t", data[i]);
	}
	printf("\n");
	 
	return 0;
}
