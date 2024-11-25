#include<stdio.h>
#include<stdlib.h>
void sort(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				int t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
}
int find(int a[],int n,int d)
{
	for(int i=0;i<n;i++)
	if(a[i]>d)
	return i;
	return n;
}
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
	int p;
	printf("Enter 0 for left, 1 for right: ");
	scanf("%d",&p);
	sort(req,s);
	int a=find(req,s,h);
	if(p==0)
	{
		for(int i=a-1;i>=0;i--)
		{
			t+=abs(req[i]-h);
			h=req[i];
		}
		t+=req[0];
		h=0;
		for(int i=a;i<s;i++)
		{
			t+=abs(req[i]-h);
			h=req[i];
		}
	}
	else
	{
	for(int i=a;i<s;i++)
		{
			t+=abs(req[i]-h);
			h=req[i];
		}
		t+=abs(200-req[a-1]);
		h=0;
		for(int i=a-1;i>=0;i--)
		{
			t+=abs(req[i]-h);
			h=req[i];
		}
		
	
	}
	printf("The total seek time =%d",t);	
	return 0;
}
