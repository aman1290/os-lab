#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 3

void calculateNeed(int need[MAX_PROCESSES][MAX_RESOURCES], int max[MAX_PROCESSES][MAX_RESOURCES], int alloc[MAX_PROCESSES][MAX_RESOURCES], int processes) {
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < MAX_RESOURCES; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
}

int isSafe(int processes, int avail[], int max[][MAX_RESOURCES], int alloc[][MAX_RESOURCES]) {
    int need[MAX_PROCESSES][MAX_RESOURCES];
    calculateNeed(need, max, alloc, processes);

    int work[MAX_RESOURCES];
    for (int i = 0; i < MAX_RESOURCES; i++) {
        work[i] = avail[i]; // Initialize work = available resources
    }

    int finish[MAX_PROCESSES] = {0}; // All processes are initially not finished
    int safeSequence[MAX_PROCESSES];
    int count = 0;

    while (count < processes) {
        int found = 0;
        for (int p = 0; p < processes; p++) {
            if (finish[p] == 0) {
                int j;
                for (j = 0; j < MAX_RESOURCES; j++) {
                    if (need[p][j] > work[j]) {
                        break;
                    }
                }

                if (j == MAX_RESOURCES) {
                    for (int k = 0; k < MAX_RESOURCES; k++) {
                        work[k] += alloc[p][k];
                    }
                    safeSequence[count++] = p;
                    finish[p] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0) {
            printf("System is not in a safe state!\n");
            return 0; // No safe sequence found
        }
    }

    printf("System is in a safe state. Safe sequence is: ");
    for (int i = 0; i < processes; i++) {
        printf("P%d ", safeSequence[i]);
    }
    printf("\n");
    return 1;
}

int main() {
    int processes; // Number of processes
    int avail[MAX_RESOURCES]; // Available resources A, B, C

    printf("Enter the number of processes (max 10): ");
    scanf("%d", &processes);

    // Maximum resources available
    printf("Enter the available instances of resources A, B, C: ");
    for (int i = 0; i < MAX_RESOURCES; i++) {
        scanf("%d", &avail[i]);
    }

    int max[MAX_PROCESSES][MAX_RESOURCES]; // Maximum demand of each process
    int alloc[MAX_PROCESSES][MAX_RESOURCES]; // Resources currently allocated to each process

    // Input maximum demand and current allocation for each process
    for (int i = 0; i < processes; i++) {
        printf("Enter the allocated and max resources (A, B, C) for process P%d: ", i);
        for (int j = 0; j < MAX_RESOURCES; j++) {
            scanf("%d", &alloc[i][j]);
        }

        //printf("Enter the maximum resources (A, B, C) for process P%d: ", i);
        for (int j = 0; j < MAX_RESOURCES; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Check if the system is in a safe state
    isSafe(processes, avail, max, alloc);

    return 0;
}

