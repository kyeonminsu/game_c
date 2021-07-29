#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main()
{	
	int i;
	int maxindex;
	
	int kor[10];
	int eng[10];
	int math[10];
	
	int total[10];
	float avr[10];
	
	srand(time(NULL));
	
	for(i=0; i<10; i++)
	{
		kor[i]=rand()%101;
		eng[i]=rand()%101;
		math[i]=rand()%101;
	}
	
	for(i=0; i<10; i++)
	{
		total[i]=kor[i]+eng[i]+math[i];
		avr[i]=total[i]/3.0;
	}
	
	maxindex=0;
	for(i=0; i<10; i++)
	{
		if(total[maxindex] < total[i])
		{
			maxindex=i;
		}
	}
	
	for(i=0; i<10; i++)
	{
		printf("%d] %d\t %d\t %d\t %d\t %.2f\n", i, kor[i], eng[i], math[i], total[i], avr[i]);
	}
	printf("max index:%d\n", maxindex);
	
	return 0;
}
