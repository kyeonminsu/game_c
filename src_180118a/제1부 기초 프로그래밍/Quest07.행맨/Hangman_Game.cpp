#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MY_DIC_SIZE	5
#define MY_WORD_LEN	20

char g_dic[MY_DIC_SIZE][MY_WORD_LEN]={
	"father"
	,"mother"
	,"wonderful"
	,"security"
	,"hello"
};

int g_step=0;

void IniGame(char* com, char* p)
{
	int index;
	int i;
	int len;
	
	srand(time(NULL));
	index=rand()%MY_DIC_SIZE;
	strcpy(com,g_dic[index]);
	len=strlen(com);
	for(i=0; i<len; i++)
	{
		p[i]='*';
	}
	p[i]='\0';
}
int InputChar(char com[MY_WORD_LEN], char p[MY_WORD_LEN])
{
	char msg[5];
	char key;
	
	int len;
	int check;
	int i;
	
	printf("Hint:%s \n",p);
	printf("input char:");
	scanf("%s",msg);
	key=msg[0];
	
	len=strlen(p);
	check=0;
	for(i=0; i<len; i++)
	{
		if(com[i]==key && p[i]=='*')
		{
			p[i]=key;
			check=1;
		}
	}
	
	return check;
}

void GoNextStep()
{
	g_step++;
	printf("hang man step:%d\n", g_step);
}
void ShowHangman()
{
	switch(g_step)
	{
		case 0:
			printf("   旨收旬\n");
			printf("       早\n");
			printf("	   早\n");
			printf("       早\n");
			printf("       早\n");
			printf("       早\n");
			break;
		case 1:
			printf("   旨收旬\n");
			printf("   ≒  早\n");
			printf("       早\n");
			printf("       早\n");
			printf("       早\n");
			printf("       早\n");
			break;
		case 2:
			printf("   旨收旬\n");
			printf("   ≒  早\n");
			printf(" 旨朱旬早\n");
			printf("       早\n");
			printf("       早\n");
			printf("       早\n");
			break;
		case 3:
			printf("   旨收旬\n");
			printf("   ≒  早\n");
			printf(" 旨朱旬早\n");
			printf("   早  早\n");
			printf("       早\n");
			printf("       早\n");
			break;
		case 4:
			printf("   旨收旬\n");
			printf("   ≒  早\n");
			printf(" 旨朱旬早\n");
			printf("   早  早\n");
			printf(" 旨朴旬早\n");
			printf("       早\n");
			break;
		default:
			break;
	}
}
int CheckGameOver(char* com, char* p)
{
	if(4==g_step)
	{
		return 1;
	}
	
	if(0==strcmp(com,p))
	{
		return 1;
	}
	
	return 0;
}
int main()
{
	char com[MY_WORD_LEN];
	char p[MY_WORD_LEN];
	
	IniGame(com,p);
	
	while(1)
	{
		if(0==InputChar(com,p))
		{
			GoNextStep();
			ShowHangman();
		}
		
		if(1==CheckGameOver(com,p))
		{
			break;
		} 
	}
	
	return 0;
}
