
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n], remaining[n];
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time of process %d: ", i + 1);
        scanf("%d", &at[i]);

        printf("Enter burst time of process %d: ", i + 1);
        scanf("%d", &bt[i]);

        remaining[i] = bt[i];
    }

    int st = 0, total_wt = 0, total_tat = 0, completed = 0;

    printf("\nGantt Chart");
    printf("\n-----------\n");

    while (completed != n)
        {
        int shortest = -1;
        for (int i = 0; i < n; i++)
        {
            if (at[i] <= st && remaining[i] > 0) {
                if (shortest == -1 || remaining[i] < remaining[shortest]) {
                    shortest = i;
                }
            }
        }

        if (shortest == -1) {
            st++;
            continue;
        }

        ct[shortest] = st + remaining[shortest];
        st += remaining[shortest];
        remaining[shortest] = 0;
        completed++;

        printf("%d | P%d | %d\n", st - remaining[shortest], shortest + 1, st);

        tat[shortest] = ct[shortest] - at[shortest];
        wt[shortest] = tat[shortest] - bt[shortest];

        total_wt += wt[shortest];
        total_tat += tat[shortest];
    }

    printf("\n");

    float avg_wt = (float) total_wt / n;
    float avg_tat = (float) total_tat / n;

    printf("Process\t AT\t BT\t FT\t TAT\t WT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t %d\t %d\t %d\t %d\t %d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage waiting time: %.2f\n", avg_wt);
    printf("Average turnaround time: %.2f\n", avg_tat);

    return 0;
}







// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     int n;
//     printf("Enter the number of Jobs: ");
//     scanf("%d", &n);

//     printf("\n");

//     int at[n], bt[n], ft[n], tat[n], wt[n], remaining[n];
//     for (int i = 0; i < n; i++) {
//         printf("Enter arrival time of Jobs %d: ", i + 1);
//         scanf("%d", &at[i]);

//         printf("Enter burst time of Jobs %d: ", i + 1);
//         scanf("%d", &bt[i]);

//         remaining[i] = bt[i];
//     }

//     int st = at[n], total_wt = 0, total_tat = 0, completed = 0;

//     printf("\n'Gantt Chart'");
//     printf("\n----------------------------------------------------------------------------\n");

//     while (completed != n)
//         {
//         int shortest = -1;
//         for (int i = 0; i < n; i++)
//         {
//             if (at[i] <= st && remaining[i] > 0) {
//                 if (shortest == -1 || remaining[i] < remaining[shortest]) {
//                     shortest = i;
//                 }
//             }
//         }

//         if (shortest == -1) {
//             st++;
//             continue;
//         }

//         ft[shortest] = st + remaining[shortest];
//         st += remaining[shortest];
//         remaining[shortest] = 0;
//         completed++;


//         printf("J%d |%d\t\t",shortest + 1, st);

//         tat[shortest] = ft[shortest] - at[shortest];
//         wt[shortest] = tat[shortest] - bt[shortest];

//         total_wt += wt[shortest];
//         total_tat += tat[shortest];
//     }
//     printf("\n--------------------------------------------------------------------------------\n");

//     printf("\n");

//     printf("Table:\n\n");

//     float avg_wt = (float) total_wt / n;
//     float avg_tat = (float) total_tat / n;

//     printf("Job\t AT\t BT\t FT\t TAT\t WT\n");
//     for (int i = 0; i < n; i++)
//     {
//         printf("J%d\t %d\t %d\t %d\t %d\t %d\n", i + 1, at[i], bt[i], ft[i], tat[i], wt[i]);
//     }

//     printf("\nAverage waiting time: %.2f\n", avg_wt);
//     printf("Average turnaround time: %.2f\n", avg_tat);

//     return 0;
// }
