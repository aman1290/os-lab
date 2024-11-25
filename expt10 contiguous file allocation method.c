#include <stdio.h>
#include <string.h>
#define MAX_FILES 10    //Maximum no of processes
#define MAX_BLOCKS 100   //Number of blocks
#define FILENAME_LENGTH 10  //Process Name

int main() 
{
    struct File 
{
        char name[FILENAME_LENGTH]; // Name of file
        int startBlock;  //Starting block number
        int noOfBlocks;  // Number of blocks
        int allocated;  // Allocated status
 } files[MAX_FILES];

    int blocks[MAX_BLOCKS] = {0};  // 0 indicates free, 1 indicates occupied
    int i;
    int numFiles;
	for(i=0;i<MAX_FILES;i++)    //Initially all blocks are empty
	files[i].allocated = 0;
    // Input number of files
    printf("Enter number of files: ");
    scanf("%d", &numFiles);

    // Input file details
	for (i = 0; i < numFiles; i++) 
	{
        printf("Enter file name %d: ", i + 1);
        scanf("%s", files[i].name);
        printf("Enter starting block of file %d: ", i + 1);
        scanf("%d", &files[i].startBlock);
        printf("Enter number of blocks in file %d: ", i + 1);
        scanf("%d", &files[i].noOfBlocks);

        // Check for contiguous allocation
        int canAllocate = 1;
        for (int j = 0; j < files[i].noOfBlocks; j++) 
        {
            if (files[i].startBlock + j >= MAX_BLOCKS || blocks[files[i].startBlock + j] == 1) {
                canAllocate = 0;
                 break;
            }
        }
        // Allocate blocks if possible
        if (canAllocate) 
         {
            for (int j = 0; j < files[i].noOfBlocks; j++) {
                blocks[files[i].startBlock + j] = 1;  // Mark as occupied
                files[i].allocated=1;  //Allocated 
            }
            printf("File '%s' allocated successfully from block %d.\n", files[i].name, files[i].startBlock);
            
        } else
       {
            printf("Cannot allocate file '%s': insufficient contiguous space.\n", files[i].name);
            files[i].allocated=0;  //Not allocated
       }
         
    }

    // Output the allocation status
    printf("\nFILE ALLOCATION STATUS:\n");
    printf("FILE NAME\tSTART BLOCK\tNO OF BLOCKS\tBLOCKS OCCUPIED\n");
    for (int i = 0; i < numFiles; i++) 
    {
        if( files[i].allocated==1)
        {
        printf("%-10s\t%-10d\t%-10d\t", files[i].name, files[i].startBlock, files[i].noOfBlocks);
        for (int j = 0; j < files[i].noOfBlocks; j++) 
        {
            printf("%d", files[i].startBlock + j);
            if (j < files[i].noOfBlocks - 1) 
            {
                printf(",");
            }
        }
        printf("\n");
        }
    }

    return 0;
}
