/*#include<stdio.h>

int main()
{
    int i, j, n, temp, total = 0;
    float average_waiting_time;
    printf("Enter total number of processes: ");
    scanf("%d", &n);

    int arrival_time[n], burst_time[n], priority[n], waiting_time[n], turnaround_time[n], process[n];

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of process[%d]\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &arrival_time[i]);
        printf("Burst Time: ");
        scanf("%d", &burst_time[i]);
        printf("Priority: ");
        scanf("%d", &priority[i]);
        process[i] = i+1;
    }

    for(i = 0; i < n; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(priority[i] > priority[j])
            {
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;

                temp = arrival_time[i];
                arrival_time[i] = arrival_time[j];
                arrival_time[j] = temp;

                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }

    waiting_time[0] = 0;

    for(i = 1; i < n; i++)
    {
        waiting_time[i] = 0;
        for(j = 0; j < i; j++)
            waiting_time[i] += burst_time[j];

        total += waiting_time[i];
    }

    average_waiting_time = (float) total / n;
    total = 0;

    printf("\nProcess\t  Arrival Time\t  Burst Time\t  Priority\t  Waiting Time\t  Turnaround Time\n");

    for(i = 0; i < n; i++)
    {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        total += turnaround_time[i];
        printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process[i], arrival_time[i], burst_time[i], priority[i], waiting_time[i], turnaround_time[i]);
    }

    printf("\nAverage Waiting Time = %0.2f\n", average_waiting_time);
    printf("Average Turnaround Time = %0.2f\n", (float) total / n);

    printf("\nGantt Chart:\n");
    int time = 0;
    printf("|");
    for(i = 0; i < n; i++)
    {
        printf("  P%d  |", process[i]);
        time += burst_time[i];
        printf("%d", time);
        if(i == n-1)
            printf("|\n");
        else
            printf("  ");
    }

    return 0;
}
*/












#include <stdio.h>
 
//Function to swap two variables
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    int n;
    printf("Enter Number of Processes: ");
    scanf("%d",&n);
 
    // b is array for burst time, p for priority and index for process id
    int b[n],p[n],index[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter Burst Time and Priority Value for Process %d: ",i+1);
        scanf("%d %d",&b[i],&p[i]);
        index[i]=i+1;
    }
    for(int i=0;i<n;i++)
    {
        int a=p[i],m=i;
 
        //Finding out highest priority element and placing it at its desired position
        for(int j=i;j<n;j++)
        {
            if(p[j] > a)
            {
                a=p[j];
                m=j;
            }
        }
 
        //Swapping processes
        swap(&p[i], &p[m]);
        swap(&b[i], &b[m]);
        swap(&index[i],&index[m]);
    }
 
    // T stores the starting time of process
    int t=0;
 
    //Printing scheduled process
    printf("Order of process Execution is\n");
    for(int i=0;i<n;i++)
    {
        printf("P%d is executed from %d to %d\n",index[i],t,t+b[i]);
        t+=b[i];
    }
    printf("\n");
    printf("Process Id\tBurst Time\tWait Time\tTurnAround Time\n");
    int wait_time=0;
    for(int i=0;i<n;i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\n",index[i],b[i],wait_time,wait_time + b[i]);
        wait_time += b[i];
    }
    return 0;
}
/*
Enter Number of Processes: 5
Enter Burst Time and Priority Value for Process 1: 3 2
Enter Burst Time and Priority Value for Process 2: 2 1
Enter Burst Time and Priority Value for Process 3: 3 3
Enter Burst Time and Priority Value for Process 4: 4 2
Enter Burst Time and Priority Value for Process 5: 4 1
Order of process Execution is
P3 is executed from 0 to 3
P1 is executed from 3 to 6
P4 is executed from 6 to 10
P2 is executed from 10 to 12
P5 is executed from 12 to 16

Process Id      Burst Time      Wait Time       TurnAround Time
P3              3               0               3
P1              3               3               6
P4              4               6               10
P2              2               10              12
P5              4               12              16
*/















/*
#include<stdio.h>

int main()
{
    int i, j, n, temp, total = 0;
    float average_waiting_time, average_turnaround_time;
    printf("Enter total number of processes: ");
    scanf("%d", &n);

    int arrival_time[n], burst_time[n], priority[n], waiting_time[n], turnaround_time[n], process[n];

    for(i = 0; i < n; i++)
    {
        printf("\nEnter details of process[%d]\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &arrival_time[i]);
        printf("Burst Time: ");
        scanf("%d", &burst_time[i]);
        printf("Priority: ");
        scanf("%d", &priority[i]);
        process[i] = i+1;
    }

    for(i = 0; i < n; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(priority[i] > priority[j])
            {
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;

                temp = arrival_time[i];
                arrival_time[i] = arrival_time[j];
                arrival_time[j] = temp;

                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }

    waiting_time[0] = 0;

    for(i = 1; i < n; i++)
    {
        waiting_time[i] = 0;
        for(j = 0; j < i; j++)
            waiting_time[i] += burst_time[j];

        total += waiting_time[i];
    }

    average_waiting_time = (float) total / n;
    total = 0;

    printf("\nProcess\t  Arrival Time\t  Burst Time\t  Priority\t  Waiting Time\t  Turnaround Time\n");

    for(i = 0; i < n; i++)
    {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        total += turnaround_time[i];
        printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process[i], arrival_time[i], burst_time[i], priority[i], waiting_time[i], turnaround_time[i]);
    }

    average_turnaround_time = (float) total / n;

    printf("\nAverage Waiting Time = %0.2f\n", average_waiting_time);
    printf("Average Turnaround Time = %0.2f\n", average_turnaround_time);

    printf("\nGantt Chart:\n");
    int time = 0;
    printf("+");
    for(i = 0; i < n; i++)
    {
        
        for(j = 0; j < burst_time[i]; j++)
            printf("-");
        printf("+");
        time += burst_time[i];
    }
    printf("\n|");

    time = 0;
    
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < burst_time[i]; j++)
            printf(" ");
        printf("|");
        time += burst_time[i];
        if(time < 10)
            printf("0%d", time);
        else
            printf("%d", time);
    }
    printf("|\n");

    return 0;
}
*/