#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	int j;
	int data[10];
	
	for(i=0; i<10; i++)
	{
		data[i]=rand()%20;
		for(j=0; j<i; j++)
		{
			if(data[i] == data[j])
			{
				i--;	// 반복 횟수를 다시 감소시킴 
				break;
			}
		}
	}
	
	for(i=0; i<10; i++)
	{
		printf("%d\n", data[i]);
	}
}
