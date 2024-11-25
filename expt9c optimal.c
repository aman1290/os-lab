#include <stdio.h>

int search(int page, int frames[], int numFrames) {
    for (int i = 0; i < numFrames; i++) {
        if (frames[i] == page) {
            return i;  // Return index if the page is found
        }
    }
    return -1;  // Return -1 if the page is not found
}

int predict(int reference[], int frames[], int numFrames, int currentIndex, int numReferences) {
    int pos = -1, farthest = currentIndex;
    
    for (int i = 0; i < numFrames; i++) {
        int j;
        for (j = currentIndex; j < numReferences; j++) {
            if (frames[i] == reference[j]) {
                if (j > farthest) {
                    farthest = j;
                    pos = i;
                }
                break;
            }
        }
        if (j == numReferences) {  // Page not used again
            return i;
        }
    }
    
    return (pos == -1) ? 0 : pos;  // Return index of the page to replace
}

int main() {
    int numFrames, numReferences, pageFaults = 0;

    printf("Enter the number of frames: ");
    scanf("%d", &numFrames);

    printf("Enter the number of references: ");
    scanf("%d", &numReferences);

    int frames[numFrames], reference[numReferences];

    // Initialize frames to -1 (empty)
    for (int i = 0; i < numFrames; i++) {
        frames[i] = -1;
    }

    printf("Enter the reference list: ");
    for (int i = 0; i < numReferences; i++) {
        scanf("%d", &reference[i]);
    }

    // Process each reference
    for (int i = 0; i < numReferences; i++) {
        int page = reference[i];
        int pos = search(page, frames, numFrames);  // Check if the page is in frames

        if (pos != -1) {
            printf("No page fault for reference %d\n", page);
        } else {
            pageFaults++;

            if (i < numFrames) {
                frames[i] = page;  // Fill empty frames first
            } else {
                int replaceIndex = predict(reference, frames, numFrames, i + 1, numReferences);  // Optimal replacement
                frames[replaceIndex] = page;  // Replace the optimal page
            }

            printf("Page fault for reference %d\n", page);
        }

        // Display current state of the frames
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
