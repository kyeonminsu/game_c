#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int IsFind(int data[6], int index)
{
	int re;
	int i;
	
	re=0;	// not find
	
	for(i=0; i<index; i++)
	{
		if(data[i] == data[index])
		{
			re=1;	// find
			break;
		}
	}
}

void MakeData(int data[6])
{
	int i;
	
	srand(time(NULL));
	
	for(i=0; i<6; i++)
	{
		data[i]=rand()%46+1;
		if(1==IsFind(data, i))
		{
			i--;
		}
	}
}

void Show(int data[6])
{
	int i;
	
	for(i=0; i<6; i++)
	{
		printf("%d\t", data[i]);
	}
	printf("\n");
}

int main()
{
	int i;
	int data[6];
	
	MakeData(data);
	
	Show(data);
	
	return 0;
}
