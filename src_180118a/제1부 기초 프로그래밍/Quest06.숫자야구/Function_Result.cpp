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
	
	c=Add(a,b);	// ���ϰ����� c���� �ޱ�
	
	Add1(a,b,&c);	// �ּ�(������)�� �̿��� c���� �ޱ�
	
	if(-1==Add2(a,b,&c))	// ��� ���� �Լ� ���ڷ�, ���� ���δ� ���ϰ����� �ޱ� 
	{
		printf("Add2 function error!\n"); 
	}
	
	return 0;
}
