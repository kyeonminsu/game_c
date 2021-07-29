#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InitGame()
{
	srand(time(NULL));
	printf("Baseball Game ver 0.1 by clccclcc\n");
}
int IsFind(int com[3], int index)
{
	int re;
	int i;
	
	re=0;
	for(i=0; i<index; i++)
	{
		if(com[i]==com[index])
		{
			return 1;
		}
	}
	
	return re;
}
void MakeComData(int com[3])
{
	int i;
	
	for(i=0; i<3; i++)
	{
		com[i]=rand()%10;
		if(1==IsFind(com,i))
		{
			i--;
		}
	}
}
void InputPlayer(int p[3])
{
	int i;
	
	printf("0~9까지 중복없이 숫자 3개를 넣으세요? ");
	for(i=0; i<3; i++)
	{
		scanf("%d", &p[i]);
	}
}
void CheckScore(int com[3], int p[3], int* s, int* b)
{
	int i;
	int j;
	int ts;
	int tb;
	
	ts=0;
	tb=0;
	
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			if(p[i]==com[j])
			{
				if(i==j)
				{
					ts++;
				}
				else
				{
					tb++;
				}
				
				break;
			}
		}
	}
	
	*s=ts;
	*b=tb;
}
int CheckNextGame()
{
	int go;
	int re;
	
	re=0;
	printf("-1: end else continue game ?");
	scanf("%d", &go);
	if(-1==go)
	{
		re=-1;
	}
	
	return re;
}
int main(int argc, char* argv[])
{
	int com[3];
	int p[3];
	int s;
	int b;
	
	int i;
	
	InitGame();
	
	while(1)
	{
		MakeComData(com);
		for(i=0; i<10; i++)
		{
			b=0;
			s=0;
			
			InputPlayer(p);
			CheckScore(com, p, &s, &b);
			if(3==s)
			{
				break;
			}
			else
			{
				printf("strike:%d, ball:%d\n", s, b);
			}
		}
		
		if(3==s)
		{
			printf("3 STRIKE !! You WIN....\n");
		}
		else
		{
			printf("You LOSE....\n");
			printf("com => %d %d %d\n", com[0], com[1], com[2]);
		}
		
		if(-1==CheckNextGame())
		{
			printf("Thank You ! ...\n");
			break;
		}
	}
	
	return 0;
}
