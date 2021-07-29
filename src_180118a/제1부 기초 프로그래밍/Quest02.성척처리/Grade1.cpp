#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	int a[10];
	
	for (i=0; i<10; i++)
	{
		a[i]=rand()%101;
		printf("%d\n", a[i]);
	}
	// 실행시 이것은 아래와 같다.
	// i=0 -> a[0]=rand()%101 
	// i=1 -> a[1]=rand()%101
	// ...
	// i=9 -> a[9]=rand()%101
}
