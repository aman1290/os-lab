#include<stdio.h>
#include<stdlib.h>

#define DISK_SIZE 200  // Define the size of the disk (maximum cylinder)

void sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main() {
    int s;       // number of requests
    int t = 0;   // total seek time
    int h;       // head position

    // Input for number of requests
    printf("Enter the number of requests: ");
    scanf("%d", &s);

    int req[s];  // array to hold the requests

    // Input for request locations
    printf("Enter the location of the requests: ");
    for (int i = 0; i < s; i++) {
        scanf("%d", &req[i]);
    }

    // Input for initial head position
    printf("Enter the head position: ");
    scanf("%d", &h);

    // Sort the request array in ascending order
    sort(req, s);

    // Find the first request greater than the head position
    int a;
    for (a = 0; a < s; a++) {
        if (req[a] > h) {
            break;
        }
    }

    printf("Seek sequence: ");

    // First, service all requests to the right of the head
    for (int i = a; i < s; i++) {
        printf("%d ", req[i]);
        t += abs(req[i] - h);
        h = req[i];
    }

    // Move the head to the end of the disk and then wrap around to the start (C-SCAN behavior)
    if (h != DISK_SIZE - 1) {
        t += abs(DISK_SIZE - 1 - h);  // Move to the end of the disk
        h = 0;  // Jump back to the beginning
        t += DISK_SIZE - 1;  // Seek time for jumping back to 0
        printf("%d 0 ", DISK_SIZE - 1);  // Reaching the end of the disk and returning to 0
    }

    // Now, service the remaining requests to the left of the initial head position
    for (int i = 0; i < a; i++) {
        printf("%d ", req[i]);
        t += abs(req[i] - h);
        h = req[i];
    }

    // Output the total seek time
    printf("\nTotal seek time = %d\n", t);

    return 0;
}
