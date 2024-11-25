#include <stdio.h>

int search(int page, int frames[], int numFrames) {
    for (int i = 0; i < numFrames; i++) {
        if (frames[i] == page) {
            return i;  // Return index if the page is found
        }
    }
    return -1;  // Return -1 if page is not found
}

int findLRU(int time[], int numFrames) {
    int minTime = time[0], pos = 0;
    for (int i = 1; i < numFrames; i++) {
        if (time[i] < minTime) {
            minTime = time[i];
            pos = i;
        }
    }
    return pos;  // Return the position of the least recently used page
}

int main() {
    int numFrames, numReferences, pageFaults = 0, counter = 0;
    
    printf("Enter the number of frames: ");
    scanf("%d", &numFrames);
    
    printf("Enter the number of references: ");
    scanf("%d", &numReferences);
    
    int frames[numFrames], time[numFrames], reference[numReferences];
    
    // Initialize frames and time arrays
    for (int i = 0; i < numFrames; i++) {
        frames[i] = -1;  // Initialize frames to -1 (empty)
        time[i] = 0;     // Initialize time array for tracking usage
    }

    printf("Enter the reference list: ");
    for (int i = 0; i < numReferences; i++) {
        scanf("%d", &reference[i]);
    }

    // Start processing the reference list
    for (int i = 0; i < numReferences; i++) {
        int page = reference[i];
        int pos = search(page, frames, numFrames);  // Check if the page is in frames
        
        if (pos != -1) {
            printf("No page fault for reference %d\n", page);
            counter++;
            time[pos] = counter;  // Update time for the page in frames
        } else {
            pageFaults++;
            int lruPos = findLRU(time, numFrames);  // Find the least recently used page
            frames[lruPos] = page;  // Replace the LRU page with the new page
            counter++;
            time[lruPos] = counter;  // Update time for the new page
            printf("Page fault for reference %d\n", page);
        }

        // Print the current state of frames
        printf("Current frames: ");
        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == -1)
                printf("empty ");
            else
                printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
    return 0;
}
