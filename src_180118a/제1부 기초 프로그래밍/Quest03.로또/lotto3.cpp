#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	// 변수 선언
	int i;
	int j;
	int data[6];
	
	// 초기화
	srand(time(NULL));
	
	// 숫자 만들기
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
	
	// 만든 숫자 출력하기
	for(i=0; i<6; i++)
	{
		printf("%d\t", data[i]);
	}
	printf("\n");
	 
	return 0;
}
