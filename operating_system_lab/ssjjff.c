#include <stdio.h>
#include <stdlib.h>

void sort(int at[], int bt[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
            }
        }
    }
}

void printGanttChart(int pid[], int n, int ct[]) {
    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("------");
    }

    printf("\n| ");

    for (int i = 0; i < n; i++) {
        printf("P%d  | ", pid[i]);
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        printf("------");
    }

    printf("\n0\t");

    for (int i = 0; i < n; i++) {
        printf("%d\t", ct[i]);
    }

    printf("\n");
}

void SJF(int at[], int bt[], int n) {
    int pid[n], ct[n], tat[n], wt[n], rt[n];
    float awt = 0, atat = 0;

    sort(at, bt, n);

    int time = 0;

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;

        if (time < at[i]) {
            time = at[i];
        }

        rt[i] = bt[i];
        ct[i] = time + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        time = ct[i];
    }
    printGanttChart(pid, n, ct);

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
        awt += wt[i];
        atat += tat[i];
    }

    awt /= n;
    atat /= n;

    printf("\nAverage Waiting Time: %f", awt);
    printf("\nAverage Turnaround Time: %f\n", atat);

   
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n];

    printf("Enter the arrival time and burst time for each process:\n");

    for (int i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    SJF(at, bt, n);

    return 0;
}


/*Enter the number of processes: 5
Enter the arrival time and burst time for each process:
P1: 3 2
P2: 1 2
P3: 2 2
P4: 4 1
P5: 1 5

------------------------------
| P1  | P2  | P3  | P4  | P5  | 
------------------------------
0       5       7       9       11      16

PID     AT      BT      CT      TAT     WT
P1      4       1       5       1       0
P2      1       2       7       6       4
P3      2       2       9       7       5
P4      3       2       11      8       6
P5      1       5       16      15      10

Average Waiting Time: 5.000000
Average Turnaround Time: 7.400000*/