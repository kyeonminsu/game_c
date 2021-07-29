#include <stdio.h>
#include <stdlib.h>
#include "mtg.h"
#include "mtgsound.h"

char g_key =0;

void Draw()
{
	char temp[20];
	
	sprintf(temp," q: exit , key:%d",g_key);
	_DrawText(10,10,temp);
}
void RunIni()
{
	MTGOpen("back.mp3");
	MTGPlay();

	_Invalidate();
}
int RunKey()
{
	char k;

	k=_GetKey();
	g_key = k;
	
	if(-1==k) return 0;
	if('q'==k) 
	{
		return -1;
	}	
	else
	{

	}

	_Invalidate();

	return 0;
}
void GameMain()
{
	RunIni();
	while(1)
	{
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