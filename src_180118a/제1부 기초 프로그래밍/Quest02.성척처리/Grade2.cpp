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
	
	total=0;	// 변수 초기화
	for(i=0; i<100; i++)	// 100번 반복하면서 배열에서 1개씩 꺼내서, total에 더해줌
	{
		total = total + data[i];
	}
	
	printf("total:%d\n", total);	// 출력하기 
}
