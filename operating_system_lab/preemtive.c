#include <stdio.h>
#include <stdlib.h>

struct process
{
    int pid;
    int at;
    int bt;
    int rt;
    int ct;
    int wt;
    int tat;
    int completed;
    int pt;
};

void calculate_completion_times(struct process *p, int n)
{
    int i, j, t = 0, total = 0, min_index;
    float avg_wt = 0, avg_tat = 0;
    for (i = 0; i < n; i++)
    {
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
                if (min_index == -1 || p[j].pt < p[min_index].pt)
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
            if (p[min_index].pt == p[min_index].bt)
            {
                p[min_index].ct = t + 1;
            }
            p[min_index].pt++;
            printf("-- P%d -- %d", p[min_index].pid, t + 1);
            t++;
            if (p[min_index].pt == 0)
            {
                p[min_index].completed = 1;
                p[min_index].tat = p[min_index].ct - p[min_index].at;
                p[min_index].wt = p[min_index].tat - p[min_index].bt;
                avg_tat += p[min_index].tat;
                avg_wt += p[min_index].wt;
            }
        }
    }

    printf("\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
     avg_wt /= n;
    avg_tat /= n;

    printf("\nAverage Waiting Time: %f", avg_wt);
    printf("\nAverage Turnaround Time: %f\n", avg_tat);
}

int main()
{
    int n, i;
    float avg_wt = 0, avg_tat = 0;
    struct process *p;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    p = (struct process *)malloc(n * sizeof(struct process));
    for (i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("Enter arrival time and burst time and priority for P[%d]: ", i + 1);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].pt);
        p[i].rt = p[i].bt;
        p[i].completed = 0;
    }
   

    calculate_completion_times(p, n);

    return 0;
}