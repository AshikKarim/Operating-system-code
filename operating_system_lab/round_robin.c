#include <stdio.h>

int main()
{
/*This initializes the main function and declares 
    integer variables n, i, quantam_time, time, and
     count and float variables avg_wait_time and 
     avg_turnaround_time. It also initializes integer
      arrays burst_time, run_time, arrival_time,
       turnaround_time, waiting_time, and temp_burst_time.*/
    int n, i, quantam_time, time = 0, count = 0;
    float avg_wait_time = 0, avg_turnaround_time = 0;
    int burst_time[20], run_time[20], arrival_time[20], turnaround_time[20], 
        waiting_time[20], temp_burst_time[20];


/*These lines ask the user to input the number of 
processes n, and then request for the arrival time and
 burst time for each process. It stores the values in 
 the respective arrays arrival_time and burst_time. It
  also stores the values of burst_time in run_time and 
  temp_burst_time arrays.*/
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the arrival time and burst time for each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("P[%d]: ", i + 1);
        scanf("%d%d", &arrival_time[i], &burst_time[i]);
        run_time[i] = burst_time[i];//assigning burst time into run time
        temp_burst_time[i] = burst_time[i];//assigning burst time into temporary burst time
    }


/*This line asks the user to input the time quantum 
value and stores it in the quantam_time variable.*/
    printf("Enter the time quantum: ");
    scanf("%d", &quantam_time);


/*These lines generate the Gantt chart for the 
round-robin scheduling algorithm by iterating through
 each process and checking whether the run_time value 
 for each process is greater than zero. If it is, it 
 prints the process number, P[i], in the Gantt chart
  and updates the time variable. It also updates the
   run_time array and calculates the turnaround_time 
   and waiting_time values for the respective process.
    Finally, it increments the count variable.*/
// Print Gantt chart
    printf("\nGantt Chart:\n");

    while (1)
    {
        int done = 1;

        for (i = 0; i < n; i++)
        {
            if (run_time[i] > 0)//if run time is greater than 0
            {
                done = 0;

                if (run_time[i] > quantam_time)//if run time is greater than quantam time
                {
                    printf("P[%d] | ", i + 1);
                    time += quantam_time;//time = time+ quantam time
                    run_time[i] -= quantam_time;//run time = run time - quantam time
                }
                else
                {
                    printf("P[%d] | ", i + 1);
                    time += run_time[i];// time = time+ run time
                    turnaround_time[i] = time - arrival_time[i];
                    waiting_time[i] = turnaround_time[i] - temp_burst_time[i];
                    run_time[i] = 0;
                    count++;
                }
            }
        }

        if (done == 1)
            break;
    }

    printf("\n\nProcess\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++)
    {
        // Calculate average waiting time and average turnaround time
        avg_wait_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
        //-----------------------------------------------------------
        printf("P[%d]\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrival_time[i], temp_burst_time[i], turnaround_time[i], waiting_time[i]);
    }

    avg_wait_time /= n;
    avg_turnaround_time /= n;

    printf("\nAverage Waiting Time: %.2f", avg_wait_time);
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);
    sleep(10);

    return 0;
}


/*Give inputs as shown below here:
Enter the number of processes: 4
Enter the arrival time and burst time for each process:
P[1]: 0 8
P[2]: 1 5
P[3]: 2 10
P[4]: 3 11
Enter the time quantum: 6

Gantt Chart:
P[1] | P[2] | P[3] | P[4] | P[1] | P[3] | P[4] | 

Process Arrival Time    Burst Time      Turnaround Time Waiting Time
P[1]    0               8               25              17
P[2]    1               5               10              5
P[3]    2               10              27              17
P[4]    3               11              31              20

Average Waiting Time: 14.75
Average Turnaround Time: 23.25
*/