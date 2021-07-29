#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a;	// 입력용
	int b;	// 입력용
	int max;	// 큰 수를 저장할 변수
	
	printf("두 수를 입력 하세요: ");
	scanf("%d %d", &a, &b);
	
	if( a < b)
	{
		max = b;	
	} 
	else
	{
		max = a;
	}
	printf("큰 수는 %d 입니다.\n", max);
}
