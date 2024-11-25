#include<stdio.h>
#include<stdlib.h>
int mutex=1;
int full=0;
int empty=10,x=0;
void producer()
{
	--mutex;
	++full;
	--empty;
	x++;
	printf("\nProducer produces item %d",x);
	++mutex;
}
void consumer()
{
	--mutex;
	--full;
	++empty;
	printf("\nConsumer consumes item%d",x);
	x--;
	++mutex;
}
int main()
{
	int n,i=1;
	printf("\n1. Press 1 for Producer\n2. Press 2 for Consumer\n3. Press 3 fro Exit");
	while(i==1)
	{
		printf("\nEnter your choice\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1: 
				if(empty==0)
				printf("Buffer Overflow\n");
				else
				producer();
				break;
			case 2:
				if(full==0)
				printf("Buffer underflow\n");
				else
				consumer();
				break;
			case 3:
				i=0;
				break;
			default:
				printf("Incorrect option chosen\n");
		}
	}
	return 0;
}
