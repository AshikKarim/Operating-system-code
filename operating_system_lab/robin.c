#include <stdio.h>

#define MAX_PROCESSES 100
#define TIME_QUANTUM 2

int main()
{
    int n, i, j, time = 0, remaining = 0, completed = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int arrival[MAX_PROCESSES], burst[MAX_PROCESSES], completion[MAX_PROCESSES], waiting[MAX_PROCESSES], turnaround[MAX_PROCESSES], remaining_burst[MAX_PROCESSES];
    float avg_waiting, avg_turnaround;
    for (i = 0; i < n; i++)
    {
        printf("For process %d:\n", i + 1);
        printf("Enter arrival time: ");
        scanf("%d", &arrival[i]);
        printf("Enter burst time: ");
        scanf("%d", &burst[i]);
        remaining_burst[i] = burst[i];
    }
    // Print entered values
    printf("\nYou entered the following values:\n");
    printf("Number\tArrival\tBurst\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\n", i + 1, arrival[i], burst[i]);
    }
    // Run Round Robin algorithm
    while (completed < n)
    {
        for (i = 0; i < n; i++)
        {
            if (arrival[i] <= time && remaining_burst[i] > 0)
            {
                if (remaining_burst[i] <= TIME_QUANTUM)
                {
                    time += remaining_burst[i];
                    remaining = 0;
                }
                else
                {
                    time += TIME_QUANTUM;
                    remaining_burst[i] -= TIME_QUANTUM;
                }
                if (remaining_burst[i] == 0)
                {
                    completion[i] = time;
                    waiting[i] = completion[i] - arrival[i] - burst[i];
                    turnaround[i] = completion[i] - arrival[i];
                    completed++;
                }
            }
            else
            {
                remaining++;
            }
        }
        if (remaining == n)
        {
            time++;
        }
    }
    // Calculate average waiting time and average turnaround time
    avg_waiting = 0;
    avg_turnaround = 0;
    for (i = 0; i < n; i++)
    {
        avg_waiting += waiting[i];
        avg_turnaround += turnaround[i];
    }
    avg_waiting /= n;
    avg_turnaround /= n;
    // Print Gantt chart
    printf("\nGantt chart:\n");
    for (i = 0; i < n; i++)
    {
        printf("   P%d   ", i + 1);
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("--------");
    }
    printf("\n");
    printf("%2d", arrival[0]);
    for (i = 0; i < n; i++)
    {
        if (completion[i] == 0)
        {
            printf("   idle ");
        }
        else
        {
            printf("   P%d   ", i + 1);
        }
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        if (completion[i] == 0)
        {
            printf("%2d", arrival[i + 1]);
        }
        else
        {
            printf("%2d", completion[i]);
        }
    }
    printf("%7d\n", time);
    // Print waiting time and turnaround time
    printf("\n\nProcess\tArrival\tBurst\tCompletion\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n", i + 1, arrival[i], burst[i], completion[i], waiting[i], turnaround[i]);
    }
    printf("\nAverage waiting time: %.2f", avg_waiting);
    printf("\nAverage turnaround time: %.2f", avg_turnaround);
    return 0;
}