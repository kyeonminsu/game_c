#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mtg.h"

#define MY_KEY_F4		64
#define MY_KEY_LEFT		75
#define MY_KEY_RIGHT	77
#define MY_KEY_GUN		32

#define ENEMY_COUNT		4
#define ENEMY_TYPE_COUNT	4

#define MAX_BULLET_COUNT	50
#define MAX_BOMB_COUNT		50

#define PLAYER_YPOS		24

struct S_OBJECT
{
	int x;
	int y;
	int life;
	int type;
	int dir;
};

int g_game=0;
struct S_OBJECT g_Enemy[ENEMY_COUNT];
struct S_OBJECT g_player;

struct S_OBJECT g_bullet[MAX_BULLET_COUNT];	
struct S_OBJECT g_bomb[MAX_BOMB_COUNT];	

char* g_Enemy_type[]={"<-#->","Oo!oO",":;@;:","vWTWv"}; 

void ShowHelp();
void ShowPlayer();
void ShowEnemy();
void IniEnemy();
void IniPlayer();

void MovePlayer(char k);
void MoveEnemy();
void RunEnemyTimer();

void IniBullet();
void ShowBullet();
void Fire(char k);
void RunBulletTimer();	
void MoveBullet();
void CheckBulletCollision();
void IniBomb();
void ShowBomb();

void DownBomb(int x,int y);
void MoveBomb();
void RunBombTimer();

void CheckBombCollision();
int CheckGameOver();
 
void ShowBullet()
{
	int i;
	
	for(i=0; i<MAX_BULLET_COUNT; i++)
	{
		if(g_bullet[i].life <= 0) continue;
		
		_DrawText(g_bullet[i].x, g_bullet[i].y, "#");
	}
}
void ShowBomb()
{
	int i;
	for(i=0; i<MAX_BOMB_COUNT; i++)
	{
		if(g_bomb[i].life <= 0) continue;
		
		_DrawText(g_bomb[i].x, g_bomb[i].y, "@");
	}
}
void ShowHelp()
{
	_DrawText(60,20,"°¶·¯±× ver0.1");
	_DrawText(60,21,"F4:exit");
}
void ShowPlayer()
{
	char temp[80];
	
	_DrawText(g_player.x, g_player.y, "__^__");
	sprintf(temp,"Life:%d",g_player.life);
	_DrawText(0,0,temp); 
}
void ShowEnemy()
{
	int i;
	
	for(i=0; i<ENEMY_COUNT; i++)
	{
		if(g_Enemy[i].life <= 0) continue;
		
		_DrawText(g_Enemy[i].x, g_Enemy[i].y, g_Enemy_type[g_Enemy[i].type]);
	}
}

void Draw()
{
	ShowHelp();
	ShowPlayer();
	ShowEnemy();
	
	ShowBullet();
	ShowBomb();
}

void IniBullet()
{
	int i;
	
	for(i=0; i<MAX_BULLET_COUNT; i++)
	{
		g_bullet[i].life=0;
	}
} 
void IniBomb()
{
	int i;
	
	for(i=0; i<MAX_BOMB_COUNT; i++)
	{
		g_bomb[i].life=0;
		g_bomb[i].dir=1;
	}
}
void IniPlayer()
{
	g_player.x=40;
	g_player.y=23;
	g_player.life=10;
}
void IniEnemy()
{
	int i;
	
	for(i=0; i<ENEMY_COUNT; i++)
	{
		g_Enemy[i].x=rand()%70;
		g_Enemy[i].y=rand()%5;
		g_Enemy[i].life=10;
		g_Enemy[i].type=rand()%ENEMY_TYPE_COUNT;
		g_Enemy[i].dir=1;
	}
}
void RunIni()
{
	srand(time(NULL));
	IniPlayer();
	IniEnemy();
	
	IniBullet(); 
	IniBomb();
	
	_Invalidate();
}

void Fire(char k)
{
	int i;
	
	if(MY_KEY_GUN==k)
	{
		for(i=0; i<MAX_BULLET_COUNT; i++)
		{
			if(0 < g_bullet[i].life) continue;
			
			g_bullet[i].x = g_player.x + 2;
			g_bullet[i].y = g_player.y - 1;
			g_bullet[i].life = 10;
			break;
		}
	}
}
void MovePlayer(char k)
{
	switch(k)
	{
		case MY_KEY_LEFT:
			g_player.x = g_player.x - 1;
			if(g_player.x < 0)
			{
				g_player.x = 0;
			}
			break;
		case MY_KEY_RIGHT:
			g_player.x = g_player.x + 1;
			if(70 < g_player.x)
			{
				g_player.x = 70;
			}
			break;
		default:
			break;
	}
}
int RunKey()
{
	char k;
	
	k=_GetKey();
	
	if(-1==k) return 0;
	if('q'==k || MY_KEY_F4==k)
	{
		return -1;
	}
	else
	{
		
	}
	
	MovePlayer(k);
	Fire(k);
	
	_Invalidate();
	
	return 0;
	
}

void MoveBullet()
{
	int i;
	
	for(i=0; i<MAX_BULLET_COUNT; i++)
	{
		if(g_bullet[i].life <= 0) continue;
		g_bullet[i].life = g_bullet[i].life - 1;
		g_bullet[i].y = g_bullet[i].y - 1;
	}
}
void CheckBulletCollision()
{
	int i,j;
	
	for(i=0; i<MAX_BULLET_COUNT; i++)
	{
		if(g_bullet[i].life <= 0) continue;
		
		for(j=0; j<ENEMY_COUNT; j++)
		{
			if(g_Enemy[j].life <= 0) continue;
			
			if(g_Enemy[j].y == g_bullet[i].y)
			{
				if(g_Enemy[j].x <= g_bullet[i].x && g_bullet[i].x <= g_Enemy[j].x + 4)
				{
					g_bullet[i].life=0;
					g_Enemy[j].life--;
					break;
				}
			}
		}
	}
}
void RunBulletTimer()
{
	static long old_bulletT=0;
	long new_bulletT;
	
	new_bulletT=_GetTickCount();
	if(abs(new_bulletT - old_bulletT) < 50)
	{
		return;
	}
	else
	{
		old_bulletT=new_bulletT;
	}
	
	MoveBullet();
	CheckBulletCollision();
	
	_Invalidate();
}

void DownBomb(int x,int y)
{
	int i;
	
	for(i=0; i<MAX_BOMB_COUNT; i++)
	{
		if(g_bomb[i].life <= 0)
		{
			g_bomb[i].life=1;
			g_bomb[i].x = x;
			g_bomb[i].y = y;
			break;
		}
	}
}
void MoveEnemy()
{
	int i;
	
	for(i=0; i<ENEMY_COUNT; i++)
	{
		if(g_Enemy[i].life <= 0) continue;
		g_Enemy[i].y = g_Enemy[i].y + g_Enemy[i].dir;
		
		if(15 <= g_Enemy[i].y)
		{
			g_Enemy[i].dir = g_Enemy[i].dir * -1;
		}
		else if(g_Enemy[i].y <= 0)
		{
			g_Enemy[i].dir = g_Enemy[i].dir * -1;
		}
		
		if(g_Enemy[i].dir < 0 && g_Enemy[i].y <= 15 && 12 <= g_Enemy[i].y)
		{
			DownBomb(g_Enemy[i].x+2, g_Enemy[i].y);
		}
	}
}
void MoveBomb()
{
	int i;
	
	for(i=0; i<MAX_BOMB_COUNT; i++)
	{
		if(g_bomb[i].life <= 0) continue;
		
		g_bomb[i].y++;
		if(g_player.y < g_bomb[i].y)
		{
			g_bomb[i].life=0;
		}
	}
}
int CheckGameOver()
{
	if(g_player.life <= 0)
	{
		_Invalidate();
		_MessageBox(0,0,20,10,"Game Over!");
		return -1;
	}
	
	return 0;
}
void CheckBombCollision()
{
	int i;
	
	for(i=0; i<MAX_BOMB_COUNT; i++)
	{
		if(g_bomb[i].y == g_player.y && g_player.x <= g_bomb[i].x && g_bomb[i].x <= g_player.x+2)
		{
			g_player.life--;
			g_bomb[i].life=0;
		}
	}
}
void RunBombTimer()
{
	static long old_bombT=0;
	long new_bombT;
	
	new_bombT=_GetTickCount();
	
	if(abs(new_bombT - old_bombT) < 100)
	{
		return;
	}
	else
	{
		old_bombT=new_bombT;
	}
	
	MoveBomb();
	CheckBombCollision();
	
	_Invalidate();
}
void RunEnemyTimer()
{
	static long old_enemyT=0;
	long new_enemyT;
	
	new_enemyT=_GetTickCount();
	if(abs(new_enemyT - old_enemyT) < 1000)
	{
		return;
	}
	else
	{
		old_enemyT=new_enemyT;
	}
	
	MoveEnemy();
	
	_Invalidate();
}
void GameMain()
{
	RunIni();
	while(1)
	{
		RunEnemyTimer();
		RunBulletTimer();
		RunBombTimer();
		
		if(-1==RunKey())
		{
			break;
		}
		if(-1==CheckGameOver())
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
