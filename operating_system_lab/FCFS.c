#include<stdio.h>
int main()
{
    int n,i,j,time=0;
    printf("Enter number of times you want to input numbers: ");
    scanf("%d",&n);

    int at[n],bt[n],ft[n],wt[n],tat[n];
    float awt,atat;

    for ( i = 0; i < n; i++)
    {
      printf("For process %d :\n", i+1);
      printf("Ener arrival time :");
      scanf("%d",&at[n]);
      printf("Ener burst time :");
      scanf("%d",&bt[n]);  
    }

    printf("\n");
    printf("You've entered the following values: \n");
    printf("Process\tArrival\tBurst\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\n",i+1,at[i],bt[i]);
    }

    for ( i = 0; i < n; i++)
    {
        if(time<at[i])
        {
            time=at[i];
        }
        ft[i]=time+bt[i];
        time=ft[i];
           
    }

    for ( i = 0; i < n; i++)
    {
        wt[i] = ft[i]-at[i]-bt[i];
    }
    awt /= n;
    atat /= n;

    printf("\nGantt chart : \n");
    for ( i = 0; i < n; i++)
    {
        printf("p%d",i+1);
    }
    printf("\n");
    for ( i = 0; i < n; i++)
    {
        printf("---------");
    }
    printf("\n");
    printf("%2d",at[0]);
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < bt[i]; j++)
        {
            printf("-");
        }
        printf("%2d",ft[i]); 
        
    }

    printf("\n\nResult Table:\n");
    printf("Process\tArrival\tBurst\tStarting\tFinish\tWaiting\tTurnaround\n");
    for ( i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ft[i]-bt[i],ft[i],wt[i],tat[i]);
    }
    printf("Average Waiting Time");
    
    
    
    
}