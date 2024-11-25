#include<stdio.h>
int main()
{
	int pc,m_block;
	printf("Enter the number of memory blocks and the number of process:\n");
	scanf("%d %d", &m_block,&pc);
	int mem[m_block];
	printf("Enter %d number of block size of the memory: ",m_block);
	for(int i=0;i<m_block;i++)
	{
		scanf("%d",&mem[i]);
	}
	int p_size[pc], p_alloc[pc];
	printf("Enter the process size");
	for(int i=0;i<pc;i++){
		scanf("%d",&p_size[i]);
		p_alloc[i]=-1;
	}
	for(int i=0;i<pc;i++)
	{
		for(int j=0;j<m_block;j++)
		{
			if(mem[j]>=p_size[i])
			{
				p_alloc[i]=j+1;
				mem[j]-=p_size[i];
				break;
			}
		}
	}
	printf("Process_number\tProcess_Memory\tMem_allocation\n");
	for(int i=0;i<pc;i++)
	{
		printf("%d\t\t%d\t\t%d\n",i+1,p_size[i],p_alloc[i]);
	}
	return 0;
}