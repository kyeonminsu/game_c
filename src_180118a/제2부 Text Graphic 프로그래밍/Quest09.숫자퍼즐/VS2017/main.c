#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mtg.h"

#define MY_SIZE		3
#define MY_BLANK	MY_SIZE*MY_SIZE
#define MY_LEFT		75
#define MY_RIGHT	77
#define MY_UP		72
#define MY_DOWN		80

int g_data[MY_SIZE][MY_SIZE]={{1,2,3},{4,5,6},{7,8,9}};
int g_x=MY_SIZE-1;
int g_y=MY_SIZE-1;

void Draw()
{
	int x,y;
	char temp[10];
	
	for(y=0; y<MY_SIZE; y++)
	{
		for(x=0; x<MY_SIZE; x++) 
		{
			sprintf(temp, "%d", g_data[y][x]);
			if(MY_BLANK==g_data[y][x])
			{
				sprintf(temp,"*");
			}
			_DrawText(x*2,y*2,temp);
		}
	}
	
	_DrawText(23,2,"Puzzel ver 0.1");
}
void RunIni()
{
	int dir;
	int i;
	
	srand(time(NULL));
	for(i=0; i<100; i++)
	{
		dir=rand()%4;
		switch(dir)
		{
			case 0:
				if(0==Move(g_x-1,g_y,g_x,g_y))
				{
					g_x--;
				}
				break;
			case 1:
				if(0==Move(g_x+1,g_y,g_x,g_y))
				{
					g_x++;
				}
				break;
			case 2:
				if(0==Move(g_x,g_y-1,g_x,g_y))
				{
					g_y--;
				}
				break;
			case 3:
				if(0==Move(g_x,g_y+1,g_x,g_y))
				{
					g_y++;
				}
				break;
			default:
				break;
				
		}
	} 
	
	_Invalidate();
}
int Move(int sx, int sy, int dx, int dy)
{
	if(sx < 0 || sy < 0 || dx < 0 || dy < 0)
	{
		return -1;
	}
	
	if(MY_SIZE <= sx || MY_SIZE <= sy || MY_SIZE <= dx || MY_SIZE <= dy)
	{
		return -1;
	}
	
	if(MY_BLANK == g_data[dy][dx])
	{
		g_data[dy][dx]=g_data[sy][sx];
		g_data[sy][sx]=MY_BLANK;
		return 0;
	}
	
	return -1;
} 
int CheckGameOver()
{
	int x,y;
	int a;
	
	a=1;
	for(y=0;y<MY_SIZE;y++)
	{
		for(x=0;x<MY_SIZE;x++)
		{
			if(a != g_data[y][x])
			{
				return -1;
			}
			a++;
		}
	}
	return 0;
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
	else if(MY_LEFT == k)
	{
		if(0 == Move(g_x-1,g_y,g_x,g_y))
		{
			g_x--;
		}
	}
	else if(MY_RIGHT == k)
	{
		if(0 == Move(g_x+1,g_y,g_x,g_y))
		{
			g_x++;
		}
	}
	else if(MY_UP == k)
	{
		if(0 == Move(g_x,g_y-1,g_x,g_y))
		{
			g_y--;
		}
	}
	else if(MY_DOWN == k)
	{
		if(0 == Move(g_x,g_y+1,g_x,g_y))
		{
			g_y++;
		}
	}
	else
	{
		
	}
	
	if(0==CheckGameOver())
	{
		_Invalidate();
		_MessageBox(10,10,30,5,"Game Over!"); 
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
