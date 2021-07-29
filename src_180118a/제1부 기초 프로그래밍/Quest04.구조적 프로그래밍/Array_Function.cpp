#include <stdio.h>
#include <stdlib.h>

void test(int data[5])
{
	int i;
	
	for(i=0; i<5; i++)
	{
		data[i]=data[i]*2;
	}
}

int main()
{
	int i;
	int my[5]={1,2,3,4,5};
	
	test(my);
	
	for(i=0; i<5; i++)
	{
		printf("%d->%d\n", i, my[i]);
	}
	
	return 0;
}
