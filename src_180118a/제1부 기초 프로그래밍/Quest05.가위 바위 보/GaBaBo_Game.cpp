#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MY_END	-1
#define MY_GA	0
#define MY_BA	1
#define MY_BO	2

#define MY_WIN	0
#define MY_LOSE	1
 
void MyIni(int* count, int* wcount)
{
	*count=0;
	*wcount=0;
	srand(time(NULL));
}
int ComPlay()
{
	return rand()%3;
}
int ManPlay()
{
	int you;
	
	printf("-1(종료),0(가위),1(바위),2(보) : ");
	scanf("%d", &you);
	
	return you; 
}
int MyCheck(int com, int you)
{
	if(MY_GA==you && MY_BO==com)
	{
		return MY_WIN;
	}
	
	if(MY_BA==you && MY_GA==com)
	{
		return MY_WIN;
	}
	
	if(MY_BO==you && MY_BA==com)
	{
		return MY_WIN;
	}
	
	return MY_LOSE;
}
void ShowWRate(int count, int wcount)
{
	float wrate;
	
	wrate=(float)wcount/count;
	printf("Win Rate:%.2f\n", wrate);
}
int main(int argc, char* argv[])
{
	int you;
	int com;
	int re;
	int count;
	int wcount;
	
	MyIni(&count, &wcount);
	
	while(1)
	{
		com=ComPlay();
		you=ManPlay();
		
		if(MY_END == you)
		{
			break;
		}
		
		count++;
		re=MyCheck(com, you);
		if(MY_WIN == re)
		{
			wcount++;
			printf("You Win! com:%d you:%d\n", com, you);
		}
		else
		{
			printf("You Lose! com:%d you:%d\n", com, you);
		}
	}
	
	ShowWRate(count, wcount);
	
	return 0;
}
