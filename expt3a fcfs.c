#include<stdio.h>
int main()
{
	int n,wt[10],bt[10],tt[10];
	printf("Enter the number of process:");
	scanf("%d",&n);
	printf("Enter burst times for each process:\n");
	for(int i=0;i<n;i++)
	{
		printf("Process %d:",i+1);
		scanf("%d",&bt[i]);
	}
	wt[0]=0;
	tt[0]=bt[0];
	for(int i=1;i<n;i++)
	{
		wt[i]=wt[i-1]+bt[i-1];
		tt[i]=wt[i]+bt[i];
	}
	int avgw=0,avgtt=0;
	for(int i=0;i<n;i++)
	{
		avgw+=wt[i];
		avgtt+=tt[i];
	}
	printf("\nPN\tBT\tWT\tTAT\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\n",i+1,bt[i],wt[i],tt[i]);
	}
	printf("The Average wait time=%.2f\n",(float)avgw/n);
	printf("The Average Turn around time=%.2f\n",(float)avgtt/n);
}
