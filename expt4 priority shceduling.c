#include <stdio.h>

void sort(int n, int p[], int at[], int bt[], int pr[]) {
    int tmp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j] ||
                (at[i] == at[j] && pr[i] > pr[j]) ||
                (at[i] == at[j] && pr[i] == pr[j] && p[i] > p[j])) {
                
                tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;

                tmp = at[i];
                at[i] = at[j];
                at[j] = tmp;

                tmp = bt[i];
                bt[i] = bt[j];
                bt[j] = tmp;

                tmp = pr[i];
                pr[i] = pr[j];
                pr[j] = tmp;
            }
        }
    }
}

void priority_sched(int n, int p[], int at[], int bt[], int pr[], int st[], int ct[], int tat[], int wt[]) {
    int curr_time = 0;

    sort(n, p, at, bt, pr);
    
    for (int i = 0; i < n; i++) {
        if (at[i] > curr_time) {
            curr_time = at[i];
        }
        st[i] = curr_time;
        ct[i] = curr_time + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        curr_time += bt[i];
    }
}


void print_proc(int n, int p[], int at[], int bt[], int pr[], int st[], int ct[], int tat[], int wt[]) {
    printf("PID\tArr\tBurst\tPrio\tStart\tComp\tTurn\tWait\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", 
               p[i], at[i], bt[i], pr[i], st[i], ct[i], tat[i], wt[i]);
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int p[n], at[n], bt[n], pr[n];
    int st[n], ct[n], tat[n], wt[n];
    
    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter arrival time, burst time, and priority for process %d: ", p[i]);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
    }
    
    int avgtt = 0, avgbt = 0;
    priority_sched(n, p, at, bt, pr, st, ct, tat, wt);
    
    for (int i = 0; i < n; i++) {
        avgtt += tat[i];  // Corrected from tat[n] to tat[i]
        avgbt += bt[i];   	
    }
    
    print_proc(n, p, at, bt, pr, st, ct, tat, wt);
    printf("The avg TNT = %.2f\n", (float)avgtt / n);
    printf("The avg BT = %.2f\n", (float)avgbt / n);
    
    return 0;
}

