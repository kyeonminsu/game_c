#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char msg1[80]={"haha"};
	char msg2[80];
	int len;
	int i;
	
	strcpy(msg2, msg1);
	
	len=strlen(msg1);
	for(i=0; i<len; i++)
	{
		msg2[i]=msg1[i];
	}
	msg2[i]='\0';
}
