#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mtg.h"

#define MY_KEY_F4			62
#define MY_KEY_ENTER		13
#define MY_KEY_BACKSPACE	8

#define MY_MAX_X	50
#define MY_MAX_Y	20
#define MY_MAX_WORD	100
#define MY_MAX_LEN	15

typedef struct
{
	char word[MY_MAX_LEN];
	int x;
	int y;
	int index;
} S_WORD;

int g_max_words_size=0;
char g_words[MY_MAX_WORD][MY_MAX_LEN];

S_WORD g_word;
S_WORD g_key;

int g_play=0;
int g_score=0;

int LoadWords();
int GetNextWord();

void ShowHelp();
void ShowScore();
void ShowInput();
void ShowWord();

void RunTimer();
int CheckGameOver();

void ShowScore()
{
	char temp[20];
	
	sprintf(temp,"score: %d",g_score);
	_DrawText(0,0,temp);
}
void ShowHelp()
{
	_DrawText(MY_MAX_X + 10,10,"»ê¼ººñ ver0.1");
	_DrawText(MY_MAX_X + 10,11,"F4: exit");
}
void ShowWord()
{
	_DrawText(g_word.x, g_word.y, g_word.word);
}
void ShowInput()
{
	_DrawText(g_key.x, g_key.y, g_key.word);
}
void Draw()
{
	ShowHelp();
	ShowWord();
	ShowInput();
	ShowScore();
}
int LoadWords()
{
	int index;
	char temp[80];
	FILE* fp;
	char* token;
	
	fp=fopen("words.txt", "r");
	if(NULL == fp)
		return -1;
	
	index=0;
	while(1)
	{
		if(NULL==fgets(temp,sizeof(temp),fp))
		{
			break;
		}
		token=strtok(temp,",\n");
		while(1)
		{
			strcpy(g_words[index],token);
			index++;
			
			token=strtok(NULL,",\n");
			if(NULL == token)
			{
				break;
			}
		}
	}
	g_max_words_size=index;
	fclose(fp);
	
	return 0;
}
int GetNextWord()
{
	if(g_max_words_size <= g_word.index)
	{
		return -1;
	}
	else
	{
		g_word.x=rand()%MY_MAX_X;
		g_word.y=1;
	}
	strcpy(g_word.word, g_words[g_word.index]);
	g_word.index++;
	
	return 0;
}
void RunIni()
{
	if(-1==LoadWords())
	{
		_MessageBox(0,0,30,20,"File Load Error");
	}
	g_word.index=0;
	GetNextWord();
	
	g_key.index=0;
	g_key.x=10;
	g_key.y=MY_MAX_Y+1;
	g_key.word[0]='\0'; 
	
	_Invalidate();
}

int RunKey()
{
	char k;
	
	k=_GetKey();
	
	if(-1==k) return 0;
	if('q'==k || MY_KEY_F4 == k)
	{
		return -1;
	}
	else
	{
		
	}
	
	if(MY_KEY_ENTER == k)
	{
		if(0==strcmp(g_key.word, g_word.word))
		{
			g_score = g_score + 100;
			if(-1==GetNextWord())
			{
				g_play=-1;
				return 0;
			}
		}
		
		g_key.index=0;
		g_key.word[g_key.index]='\0';
	}
	else if(MY_KEY_BACKSPACE == k)
	{
		g_key.index--;
		if(g_key.index < 0)
		{
			g_key.index=0;
		}
		g_key.word[g_key.index]='\0';
	}
	else
	{
		g_key.word[g_key.index++]=k;
		g_key.word[g_key.index]='\0';
	}
	
	_Invalidate();
	
	return 0;
	
}

void RunTimer()
{
	static long oldT=0;
	long newT;
	
	if(-1==g_play) return;
	
	newT=_GetTickCount();
	if(abs(newT - oldT) < 1000)
	{
		return;
	}
	else
	{
		oldT=newT;
	}
	
	if(MY_MAX_Y < (g_word.y + 1))
	{
		if(-1==GetNextWord())
		{
			g_play=-1;
		}
	}
	else
	{
		g_word.y++;
	}
	
	_Invalidate();
}
int CheckGameOver()
{
	if(-1==g_play)
	{
		_Invalidate();
		_MessageBox(0,0,20,5,"Game Over!");
		return -1;
	}
	
	return 0;
}
void GameMain()
{
	RunIni();
	while(1)
	{
		RunTimer();
		if(-1==CheckGameOver())
		{
			break;
		}
		if(-1==RunKey())
		{
			break;
		}
	}
}
int main() 
{
	_BeginWindow();
	GameMain();
	_EndWindow();
	
	return 0;
}
