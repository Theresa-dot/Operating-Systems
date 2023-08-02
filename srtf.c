#include <stdio.h> 

int main() {
    int bt[20], at[20], p[20], wt[20], tat[20], rt[20], i, j, n, total = 0, pos, temp;
    float avg_wt, avg_tat;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter Burst time and Arrival time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d:\n", i + 1);
        printf("Burst time: ");
        scanf("%d", &bt[i]);
        printf("Arrival time: ");
        scanf("%d", &at[i]);
        p[i] = i + 1;
        rt[i] = bt[i]; // Initialize remaining burst time with burst time
    }
    int completed = 0;
    int time = 0;
    while (completed != n) {
        int shortest = -1;
        int min_burst = 9999;
        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] < min_burst && rt[i] > 0) {
                min_burst = rt[i];
                shortest = i;
                
            }
            
        }
        if (shortest == -1) {
            time++;
            continue;
            
        }
        rt[shortest]--;
        time++;
        if (rt[shortest] == 0) {
            completed++;
            tat[shortest] = time - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];
            total += wt[shortest];
            
        }
        
    }
    avg_wt = (float)total / n;
    total = 0;
    printf("\nProcess\t\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++) {
        printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d", p[i], bt[i], at[i], wt[i], tat[i]);
        total += tat[i];
        
    }
    avg_tat = (float)total / n;
    printf("\nAverage Waiting time = %f", avg_wt);
    printf("\nAverage Turnaround time = %f\n", avg_tat);
    return 0;
    
}
