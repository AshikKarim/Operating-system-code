#include <stdio.h>

int main()
{
    int n, i, j, time = 0;
    printf("Enter the number of times you want to input numbers: ");
    scanf("%d", &n);
    int arrival[n], burst[n], completion[n], waiting[n], turnaround[n];
    float avg_waiting, avg_turnaround;
    for (i = 0; i < n; i++)
    {
        printf("For process %d    :\n", i + 1);
        printf("Enter arrival time: ");
        scanf("%d", &arrival[i]);
        printf("Enter burst time  : ");
        scanf("%d", &burst[i]);
    }
    // Print entered values
    printf("\n");
    printf("You entered the following values:\n");
    printf("Number\tArrival\tBurst\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\n", i + 1, arrival[i], burst[i]);
    }
    // Calculate completion time for each process
    for (i = 0; i < n; i++)
    {
        if (time < arrival[i])
        {
            time = arrival[i];
        }
        completion[i] = time + burst[i];
        time = completion[i];
    }
    // Calculate waiting time for each process
    for (i = 0; i < n; i++)
    {
        waiting[i] = completion[i] - arrival[i] - burst[i];
    }
    // Calculate turnaround time for each process
    for (i = 0; i < n; i++)
    {
        turnaround[i] = completion[i] - arrival[i];
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
        for (j = 0; j < burst[i]; j++)
        {
            printf("-");
        }
        printf("%2d", completion[i]);
    }
    // Print results
    printf("\n\nResults:\n");
    printf("Number\tArrival\tBurst\tStarting\tCompletion\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\t%d\n", i + 1, arrival[i], burst[i], completion[i] - burst[i], completion[i], waiting[i], turnaround[i]);
    }
    printf("Average waiting time: %.2f\n", avg_waiting);
    printf("Average turnaround time: %.2f\n", avg_turnaround);
    return 0;
}
/*
You entered the following values:
Number  Arrival Burst
1       2       1
2       4       5
3       2       1
4       2       3
5       4       4

Gantt chart:
   P1      P2      P3      P4      P5   
----------------------------------------
 2- 3----- 9-10---13----17

Results:
Number  Arrival Burst   Starting        Completion      Waiting Turnaround
1       2       1       2               3               0       1
2       4       5       4               9               0       5
3       2       1       9               10              7       8
4       2       3       10              13              8       11
5       4       4       13              17              9       13
Average waiting time: 4.80
Average turnaround time: 7.60
*/