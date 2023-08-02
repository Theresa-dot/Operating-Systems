#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    int parent_id[15];
    int burst_t[15];
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter process id and burst time for %d process : ", i + 1);
        scanf("%d", &parent_id[i]);
        scanf("%d", &burst_t[i]);
    }

    int i, waiting_t[n];
    waiting_t[0] = 0;

    for (i = 1; i < n; i++)
    {
        waiting_t[i] = burst_t[i - 1] + waiting_t[i - 1];
    }

    printf("Process ID     Burst Time     Waiting Time     TurnAround Time\n");
    float twt = 0;
    float tat = 0;
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t", parent_id[i]);
        printf("%d\t\t", burst_t[i]);
        printf("%d\t\t", waiting_t[i]);
        printf("%d\t\t", burst_t[i] + waiting_t[i]);
        printf("\n");

        twt += waiting_t[i];

        tat += (waiting_t[i] + burst_t[i]);
    }

    float average_wait_t = twt / n;
    float average_turn_a_t = tat / n;
    printf("Average waiting time= %0.1f\n", average_wait_t);
    printf("Average turnaround time= %0.1f", average_turn_a_t);
}
