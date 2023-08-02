#define MAX 100

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>

void main()
{
    int i, n, sum = 0, count = 0, p, time_quantum, waiting_time = 0, turn_around_time = 0, at[MAX], bt[MAX], temp[MAX];
    float avg_waiting_time, avg_turn_around_time;
    printf("Enter total number of process: ");
    scanf("%d", &n);
    p = n;

    for (i = 0; i < n; i++)
    {
        printf("\nEnter the Arrival and Burst time of the Process %d :", i + 1);
        scanf("%d", &at[i]);
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }
    printf("\n");
    printf("Enter the Time time_quantumum for the process: \t");
    scanf("%d", &time_quantum);
    printf("\n Processes \t\t Burst Time \t\t turn_around_time \t\t Waiting Time ");
    for (sum = 0, i = 0; p != 0;)
    {
        if (temp[i] <= time_quantum && temp[i] > 0)
        {
            sum = sum + temp[i];
            temp[i] = 0;
            count = 1;
        }
        else if (temp[i] > 0)
        {
            temp[i] = temp[i] - time_quantum;
            sum = sum + time_quantum;
        }
        if (temp[i] == 0 && count == 1)
        {
            p--;
            printf("\nProcess %d \t\t %d\t\t\t\t %d\t\t\t %d", i + 1, bt[i], sum - at[i], sum - at[i] - bt[i]);
            waiting_time = waiting_time + sum - at[i] - bt[i];
            turn_around_time = turn_around_time + sum - at[i];
            count = 0;
        }
        if (i == n - 1)
        {
            i = 0;
        }
        else if (at[i + 1] <= sum)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }

    avg_waiting_time = waiting_time * 1.0 / n;
    avg_turn_around_time = turn_around_time * 1.0 / n;
    printf("\n Average Turn Around Time: %0.1f", avg_waiting_time);
    printf("\n Average Waiting Time: %0.1f", avg_turn_around_time);
    getch();
}
