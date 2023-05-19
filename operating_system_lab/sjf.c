#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int pid;
    int at;
    int bt;
    int rt;
    int ct;
    int wt;
    int tat;
    int completed;
} process;

int main()
{
    int i, j, t = 0, n, total = 0, min_index;
    float avg_wt = 0, avg_tat = 0;
    process *p;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    p = (process *)malloc(sizeof(process) * n);

    for (i = 0; i < n; i++)
    {
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &(p[i].at));
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &(p[i].bt));
        p[i].pid = i + 1;
        p[i].rt = p[i].bt;
        p[i].completed = 0;
        total += p[i].bt;
    }

    printf("\nGantt chart:\n");
    printf("0");
    for (i = 0; i < total; i++)
    {
        min_index = -1;
        for (j = 0; j < n; j++)
        {
            if (p[j].at <= t && p[j].completed == 0)
            {
                if (min_index == -1 || p[j].rt < p[min_index].rt)
                {
                    min_index = j;
                }
            }
        }
        if (min_index == -1)
        {
            printf("-- idle -- %d", t + 1);
            t++;
        }
        else
        {
            if (p[min_index].rt == p[min_index].bt)
            {
                p[min_index].ct = t + 1;
            }
            p[min_index].rt--;
            printf("-- P%d -- %d", p[min_index].pid, t + 1);
            t++;
            if (p[min_index].rt == 0)
            {
                p[min_index].completed = 1;
                p[min_index].tat = p[min_index].ct - p[min_index].at;
                p[min_index].wt = p[min_index].tat - p[min_index].bt;
                avg_tat += p[min_index].tat;
                avg_wt += p[min_index].wt;
            }
        }
    }

    printf("\n\nProcess Table:\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("\nAverage Waiting Time: %f", avg_wt);
    printf("\nAverage Turnaround Time: %f\n", avg_tat);

    free(p);
    return 0;
}
