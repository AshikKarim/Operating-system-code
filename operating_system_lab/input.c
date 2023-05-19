// #include <stdio.h>

// int main() {
//     int n, i;
//     printf("Enter the number of jobs you want to input: ");
//     scanf("%d", &n);
//     int arr[n];
//     for (i = 0; i < n; i++) {
//         printf("Enter number %d: ", i + 1);
//         scanf("%d", &arr[i]);
//     }
    
//     return 0;
// }
/*
#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the number of times you want to input numbers: ");
    scanf("%d", &n);
    int arrival[n], burst[n];
    for (i = 0; i < n; i++) {
        printf("For number %d:\n", i + 1);
        printf("Enter arrival time: ");
        scanf("%d", &arrival[i]);
        printf("Enter burst time: ");
        scanf("%d", &burst[i]);
    }
    printf("You entered the following values:\n");
    printf("Number\tArrival\tBurst\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", i + 1, arrival[i], burst[i]);
    }
    return 0;
}
*/
#include <stdio.h>

int main() {
    int n, i, j, time = 0;
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
        printf("You entered the following values:\n");
        printf("Number\tArrival\tBurst\n");
        for (i = 0; i < n; i++) {
            printf("%d\t%d\t%d\n", i + 1, arrival[i], burst[i]);
        }
    // Calculate completion time for each process
    for (i = 0; i < n; i++) {
        if (time < arrival[i]) {
            time = arrival[i];
        }
        time += burst[i];
        completion[i] = time;
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
    // Print Gantt chart
    printf("\nGantt chart:\n");
    for (i = 0; i < time; i++) {
        printf("-");
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("|");
        for (j = 0; j < burst[i]; j++) {
            printf(" ");
        }
    }
    printf("|\n");
    for (i = 0; i < time; i++) {
        printf("-");
    }
    // Print results
    printf("\n\nResults:\n");
    printf("Number\tArrival\tBurst\tCompletion\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\n", i + 1, arrival[i], burst[i], completion[i], waiting[i], turnaround[i]);
    }
    printf("Average waiting time: %.2f\n", avg_waiting);
    printf("Average turnaround time: %.2f\n", avg_turnaround);
    return 0;
}
