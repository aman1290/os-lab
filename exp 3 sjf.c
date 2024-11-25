#include<stdio.h>

// Function to calculate waiting time and turnaround time
void calculateTimes(int n, int bt[], int quantum, int wt[], int tat[]) {
    int rem_bt[n]; // Remaining burst time
    for (int i = 0; i < n; i++)
        rem_bt[i] = bt[i];

    int t = 0; // Current time

    while (1) {
        int done = 1; // Flag to check if all processes are done

        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0; // There is a pending process

                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t += rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }

        if (done == 1)
            break;
    }

    // Calculate turnaround time
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

// Function to calculate average time
void findavgTime(int n, int bt[], int quantum) {
    int wt[n], tat[n];
    int total_wt = 0, total_tat = 0;

    calculateTimes(n, bt, quantum, wt, tat);

    printf("\nPN\tBT\tWT\tTAT\n");

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    printf("Average WT = %.2f\n", (float)total_wt / n);
    printf("Average TAT = %.2f\n", (float)total_tat / n);
}

// Driver code
int main() {
    int n, quantum;
    // User inputs number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int burst_time[n];

    // User inputs burst times
    printf("Enter burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    // User inputs time quantum
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    findavgTime(n, burst_time, quantum);
    return 0;
}


