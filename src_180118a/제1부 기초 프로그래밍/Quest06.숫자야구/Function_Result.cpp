#include <stdio.h>
#include <stdlib.h>

int Add(int a, int b)
{
	int c;
	
	c=a+b;
	return c;
}
void Add1(int a,int b, int* c)
{
	*c=a+b;
	
	return;
}
int Add2(int a, int b, int* c)
{
	int re;
	
	re=1;
	*c=a+b;
	return re;
 } 
int main()
{
	int a;
	int b;
	int c;
	
	a=2;
	b=3;
	
	c=Add(a,b);	// 리턴값으로 c에서 받기
	
	Add1(a,b,&c);	// 주소(포인터)를 이용해 c에서 받기
	
	if(-1==Add2(a,b,&c))	// 결과 값은 함수 인자로, 에러 여부는 리턴값으로 받기 
	{
		printf("Add2 function error!\n"); 
	}
	
	return 0;
}
