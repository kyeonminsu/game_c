#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	int data[100];
	int max;
	
	for(i=0; i<100; i++)
	{
		data[i]=rand()%101;
		printf("%d\n", data[i]);
	}
	
	max=data[0];
	for(i=0; i<100; i++)
	{
		if(max < data[i])
		{
			max=data[i];
		}
	}
	
	printf("�ִ밪:%d\n", max);
}
