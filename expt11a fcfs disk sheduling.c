#include<stdio.h>
#include<stdlib.h>
int main()
{
	int s;
	int t=0;
	int h;
	printf("Enter the no of requests: ");
	scanf("%d",&s);
	int req[s];
	printf("Enter the location of the requests: ");
	for(int i=0;i<s;i++)
	scanf("%d",&req[i]);
	printf("Enter the head position: ");
	scanf("%d",&h);
	for(int i=0;i<s;i++)
	{
		t+=abs(h-req[i]);
		h=req[i];
	}
	printf("The final request time =%d\n",t);
	return 0;
}
