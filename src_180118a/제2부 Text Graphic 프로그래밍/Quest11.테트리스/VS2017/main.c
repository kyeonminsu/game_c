#include <stdio.h>
#include <stdlib.h>
#include "mtg.h"

#define MY_W		10 + 2
#define MY_H		20 + 2
#define MY_WALL		0
#define MY_BLANK	1
#define MY_BLOCK	2

#define MY_PATSIZE	2
#define MY_LEFT		75
#define MY_RIGHT	77
#define MY_UP		72
#define MY_DOWN		80
#define MY_SPACE	32

typedef struct
{
	int x;
	int y;
} S_POINT;

int g_data[MY_H][MY_W];
S_POINT g_type[MY_PATSIZE][4][4]={
	{
		{0,0,1,0,2,0,3,0}
		,{1,0,1,1,1,2,1,3}
		,{0,0,1,0,2,0,3,0}
		,{1,0,1,1,1,2,1,3}
	},
	{
		{1,1,2,1,1,2,2,2}
		,{1,1,2,1,1,2,2,2}	
		,{1,1,2,1,1,2,2,2}
		,{1,1,2,1,1,2,2,2}
	}
};
int g_dir=0;
int g_patindex=0;
S_POINT g_pos={1,1};

void DataIni();
void DrawData();
void DrawBlock();
void DrawHelp();

int CheckBlockMove(int dx, int dy, int dir);
int MoveBlockToData();
void CopyBlockToData();
void GetNewBlock();

void MoveToEnd();

void DownBlock(int y);
void CheckSameBlock();

void DrawData()
{
	int x,y;
	
	for(y=0; y<MY_H; y++)
	{
		for(x=0; x<MY_W; x++)
		{
			if(MY_WALL==g_data[y][x])
			{
				_DrawText(x*2,y,"бр");
			}
			else if(MY_BLANK == g_data[y][x])
			{
				_DrawText(x*2,y,".");
			}
			else
			{
				_DrawText(x*2,y,"бс");
			}
		}
	}
}
void DrawBlock()
{
	int x,y,i;
	
	for(i=0; i<4; i++)
	{
		x=g_pos.x + g_type[g_patindex][g_dir][i].x;
		y=g_pos.y + g_type[g_patindex][g_dir][i].y;
		_DrawText(x*2,y,"бс");
	}
}
void DrawHelp()
{
	_DrawText(32,10,"Tetris ver 0.1");
	_DrawText(32,11,"q: exit / left,right: move / up,down: rotation");
}
void Draw()
{
	DrawData();
	DrawBlock();
	DrawHelp();
}

void DataIni()
{
	int x,y;
	
	for(y=0; y<MY_H; y++)
	{
		for(x=0; x<MY_W; x++)
		{
			if(0==x || y == 0 || MY_W == (x+1) || MY_H == (y+1))
			{
				g_data[y][x]=MY_WALL;
			}
			else
			{
				g_data[y][x]=MY_BLANK;
			}
		}
	}
}
void RunIni()
{
	DataIni();
	_Invalidate();
}

int CheckBlockMove(int dx, int dy, int dir)
{
	int x,y;
	int i;
	
	for(i=0; i<4; i++)
	{
		x=dx + g_type[g_patindex][dir][i].x;
		y=dy + g_type[g_patindex][dir][i].y;
		if(MY_BLANK != g_data[y][x])
		{
			return -1;
		}
	}
	
	return 0;
}
int MoveBlockDown()
{
	if(0==CheckBlockMove(g_pos.x,g_pos.y+1,g_dir))
	{
		g_pos.y++;
		return 0;
	}
	return -1;
}
void CopyBlockToData()
{
	int x,y;
	int i;
	
	for(i=0; i<4; i++)
	{
		x=g_pos.x + g_type[g_patindex][g_dir][i].x;
		y=g_pos.y + g_type[g_patindex][g_dir][i].y;
		
		g_data[y][x]=MY_BLOCK;
	}
}
void GetNewBlock()
{
	g_pos.x = 1+rand()%(MY_W-5);
	g_pos.y = 1;
	g_dir=rand()%4;
	g_patindex=rand()%MY_PATSIZE;
}
void DownBlock(int y)
{
	int x;
	
	for( ; 1<=y; y--)
	{
		for(x=1; x<MY_W-1; x++)
		{
			if(1==y)
			{
				g_data[y][x]=MY_BLANK;
			}
			else
			{
				g_data[y][x]=g_data[y-1][x];
			}
		}
	}
}
void CheckSameBlock()
{
	int x,y;
	
	for(y=MY_H-2; 0<y; y--)
	{
		int same=0;
		for(x=1; x<MY_W-1; x++)
		{
			if(MY_BLOCK != g_data[y][x])
			{
				same=-1;
				break;
			}
		}
		
		if(0==same)
		{
			DownBlock(y);
			y++;
		}
	}
}
void MoveToEnd()
{
	while(1)
	{
		if(-1==MoveBlockDown())
		{
			CopyBlockToData();
			CheckSameBlock();
			
			GetNewBlock();
			
			break;
		}
	}
}
void RunTimer()
{
	static long oldT=0;
	long newT;
	static int killTimer=0;
	
	if(-1==killTimer)
		return;
		
	newT=_GetTickCount();
	if(abs(newT - oldT) < 100)
	{
		return;
	}
	else
	{
		oldT=newT;
	}
	
	if(-1==MoveBlockDown())
	{
		CopyBlockToData();
		CheckSameBlock();
		
		GetNewBlock();
		
		if(-1==MoveBlockDown())
		{
			_Invalidate();
			killTimer=-1;
			_MessageBox(40,10,20,10,"Game Over!");
		}
	}
	
	_Invalidate();
}
int RunKey()
{
	char k;
	
	k=_GetKey();
	
	if(-1==k) return 0;
	if('q'==k)
	{
		return -1;
	}
	else
	{
		
	}
	
	if(MY_LEFT == k)
	{
		if(0==CheckBlockMove(g_pos.x-1, g_pos.y, g_dir))
		{
			g_pos.x--;
		}
	}
	else if(MY_RIGHT == k)
	{
		if(0==CheckBlockMove(g_pos.x+1, g_pos.y, g_dir))
		{
			g_pos.x++;
		}
	}
	else if(MY_SPACE == k)
	{
		MoveToEnd();
	}
	else if(MY_UP == k)
	{
		int dir=g_dir;
		
		dir++;
		if(3 < dir) dir=0;
		if(0==CheckBlockMove(g_pos.x, g_pos.y, dir))
		{
			g_dir=dir;
			
			_Invalidate();
		}
	}
	else if(MY_DOWN == k)
	{
		int dir=g_dir;
		
		dir--;
		if(dir < 0) dir=3;
		if(0==CheckBlockMove(g_pos.x, g_pos.y, dir))
		{
			g_dir=dir;
			
			_Invalidate();
		}
	}
	
	_Invalidate();
	
	return 0;
		
}
void GameMain()
{
	RunIni();
	while(1)
	{
		RunTimer();
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
