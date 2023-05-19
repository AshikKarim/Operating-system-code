#include <stdio.h>

int main() {
    int n, i, j, time = 0, idle_time = 0;
    printf("Enter the number of times you want to input numbers: ");
    scanf("%d", &n);
    int arrival[n], burst[n], completion[n], waiting[n], turnaround[n];
    float avg_waiting, avg_turnaround;
    for (i = 0; i < n; i++) {
        printf("For process %d:\n", i + 1);
        printf("Enter arrival time: ");
        scanf("%d", &arrival[i]);
        printf("Enter burst time: ");
        scanf("%d", &burst[i]);
    }
    // Calculate completion time for each process
    for (i = 0; i < n; i++) {
        if (time < arrival[i]) {
            idle_time += arrival[i] - time;
            time = arrival[i];
        }
        completion[i] = time + burst[i];
        time = completion[i];
    }
    // Calculate waiting time for each process
    for (i = 0; i < n; i++) {
        waiting[i] = completion[i] - arrival[i] - burst[i];
    }
    // Calculate turnaround time for each process
    for (i = 0; i < n; i++) {
        turnaround[i] = completion[i] - arrival[i];
    }
    // Calculate average waiting time and average turnaround time
    avg_waiting = 0;
    avg_turnaround = 0;
    for (i = 0; i < n; i++) {
        avg_waiting += waiting[i];
        avg_turnaround += turnaround[i];
    }
    avg_waiting /= n;
    avg_turnaround /= n;
    // Determine the total running time and maximum burst time
    int total_time = completion[n - 1];
    int max_burst = burst[0];
    for (i = 1; i < n; i++) {
        if (burst[i] > max_burst) {
            max_burst = burst[i];
        }
    }
    // Print Gantt chart in a box
    printf("+");
    for (i = 0; i < total_time + n + 1; i++) {
        printf("-");
    }
    printf("+\n|");
    printf(" ");
    printf("Gantt chart");
    printf(" ");
    printf("|\n+");
    for (i = 0; i < total_time + n + 1; i++) {
        printf("-");
    }
    printf("+\n|");
    printf(" ");
    printf("%2d", 0);
    for (i = 0; i < n; i++) {
        printf(" | P%d", i + 1);
        for (j = 0; j < burst[i]; j++) {
            printf(" ");
        }
        printf("%2d", completion[i]);
    }
    for (i = total_time; i < total_time + max_burst + n; i++) {
        printf(" ");
    }
    printf(" |\n+");
    for (i = 0; i < total_time + n + 1; i++) {
        printf("-");
    }
    printf("+\n");
    // Print results
    printf("\nResults:\n");
    printf("Number\tArrival\tBurst\tStarting\tCompletion\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\t%d\n", i + 1, arrival[i], burst[i], completion[i] - burst[i], completion[i], waiting[i], turnaround[i]);
    }
    printf("Idle time: %d\n", idle_time);
    printf("Average waiting time: %.2f\n", avg_waiting);
    printf("Average turnaround time: %.2f\n", avg_turnaround);
    return 0;
}
