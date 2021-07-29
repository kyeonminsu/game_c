#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Ini(int kor[10], int eng[10], int math[10])
{
	int i;
	
	srand(time(NULL));
	
	for(i=0; i<10; i++)
	{
		kor[i]=rand()%101;
		eng[i]=rand()%101;
		math[i]=rand()%101;
	}
}

void MakeTotalAvr(int kor[10], int eng[10], int math[10], int total[10], float avr[10])
{
	int i;
	
	for(i=0; i<10; i++)
	{
		total[i]=kor[i]+eng[i]+math[i];
		avr[i]=total[i]/3.0;
	}
}

void MakeMaxIndex(int total[10], int* maxindex)
{
	int i;
	
	*maxindex=0;
	for(i=0; i<10; i++)
	{
		if(total[*maxindex] < total[i])
		{
			*maxindex=i;
		}
	}
}

void MyPrint(int kor[10], int eng[10], int math[10], int total[10], float avr[10], int maxindex)
{
	int i;
	
	for(i=0; i<10; i++)
	{
		printf("%d] %d\t %d\t %d\t %d\t %.2f\n", i, kor[i], eng[i], math[i], total[i], avr[i]);
	}
	printf("max index:%d\n", maxindex);
}

int main()
{
	int maxindex;
	
	int kor[10];
	int eng[10];
	int math[10];
	
	int total[10];
	float avr[10];
	
	Ini(kor, eng, math);
	
	MakeTotalAvr(kor, eng, math, total, avr);
	
	MakeMaxIndex(total, &maxindex);
	
	MyPrint(kor, eng, math, total, avr, maxindex);
	
	return 0;
}
