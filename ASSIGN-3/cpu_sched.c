#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int pid;
	int start;
	int arr;
	int burst;
	int rem;
	int wait;
	int turn;
	int flag;
}job;

void gantt(job arr[], int n, int tot_time)
{
	if(n <= 0)
	return;
	
	printf("\n\n\tGANTT CHART");
	
	int i, j;
	// printing the top bar
	printf("\n\n\t ");
	for(i=0; i<n-1; i++)
	{
	for(j=arr[i].start; j<arr[i+1].start; j++)
	printf("--");
	printf(" ");
	}
	
	for(j=0; j<tot_time - arr[n-1].start; j++)
	printf("--");
	printf(" ");
	
	printf("\n\t|");
	
	// printing the process id in the middle
	for(i=0; i<n-1; i++)
	{
	for(j=arr[i].start; j<arr[i+1].start - 1; j++)
	printf(" ");
	printf("P%d", arr[i].pid);
	
	for(j=arr[i].start; j<arr[i+1].start - 1; j++)
	printf(" ");
	printf("|");
	}
	
	for(j=0; j<tot_time - arr[n-1].start - 1; j++)
	printf(" ");
	printf("P%d", arr[n-1].pid);
	for(j=0; j<tot_time - arr[n-1].start - 1; j++)
	printf(" ");
	printf("|");
	
	printf("\n\t ");
	
	// printing the bottom bar
	for(i=0; i<n-1; i++)
	{
	for(j=arr[i].start; j<arr[i+1].start; j++)
	printf("--");
	printf(" ");
	}
	
	for(j=0; j<tot_time - arr[n-1].start; j++)
	printf("--");
	printf(" ");
	
	printf("\n\t");
	
	// printing the time line
	for(i=0; i<n-1; i++)
	{
	printf("%d", arr[i].start);
	for(j=arr[i].start; j<arr[i+1].start; j++)
	printf("  ");
	if(arr[i].start > 9)
	printf("\b"); // backspace : remove 1 space
	
	}
	
	printf("%d", arr[n-1].start);
	for(j=0; j<tot_time - arr[n-1].start; j++)
	printf("  ");
	if(tot_time > 9)
	printf("\b%d", tot_time); // backspace : remove space for two digit time instances
	   
     else
         printf("%d", tot_time);
      printf("\n");
}

void display(job ar[],int n)
{
	float avgturn=0,avgwait=0;
	job temp;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(ar[j].pid<ar[i].pid)
			{
				temp=ar[j];
				ar[j]=ar[i];
				ar[i]=temp;
			}
		
		}
	}
	
         printf("-----------------------------------------------------------------------------------------------------------------"); 
	 printf("\n|\t ProcessId \t|\tArrival \t|\tBurst \t\t|\t Turnaround \t|\tWaiting |\n");    
         printf("-----------------------------------------------------------------------------------------------------------------");
	    for(int i = 0; i < n; i++)
	   {
		printf("\n|\t P%d \t\t|\t %d \t\t|\t %d \t\t|\t %d \t\t|\t %d  \t|\n",ar[i].pid,ar[i].arr,ar[i].burst,ar[i].turn,ar[i].wait);
                avgturn+=ar[i].turn;
		avgwait+=ar[i].wait;
	   }
         printf("-----------------------------------------------------------------------------------------------------------------\n");

         printf("|\t\t\t\t\t\t\t\t\t| \t\t\t|\t\t|\n| Average \t\t\t\t\t\t\t\t|\t%.2f\t\t|\t%.2f\t|",avgturn/n,avgwait/n);
      printf("\n-----------------------------------------------------------------------------------------------------------------\n");
	 printf("\n");

}

void fcfs(job ar[],int n)
{
	int time=0;
	float avgturn=0,avgwait=0;
	int min=9999;
	int index;
	job temp;
	job g[10];
	int count=0;
	printf("\n\n\t\tFIRST COME FIRST SERVE (FCFS)\n");
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(ar[j].arr<ar[i].arr)
			{
				temp=ar[j];
				ar[j]=ar[i];
				ar[i]=temp;
			}
		
		}
	
	}
	
	for(int i=0;i<n;i++)
	{
		time+=ar[i].burst;
	}
	
	printf("\n");
	int i=0;
	for(int t=0;t<time;)
	{
		if(i<n)
		{
			ar[i].wait=t-ar[i].arr;
			ar[i].start=t;
			g[count++]=ar[i];
			t+=ar[i].burst;
			ar[i].turn=t-ar[i].arr;
		
			i++;
		}
		else
			break;
	}
	display(ar,n);
	gantt(g,count,time);
}

void sfnp(job ar[],int n)
{
	int time=0;
	float avgturn=0,avgwait=0;
	int min;
	int index;
	job g[10];
	int count=0;
	
	printf("\n\n\t\tSHORTEST JOB FIRST (non pre emptive)\n");
	time=0;
	for(int i=0;i<n;i++)
	{
		time+=ar[i].burst;
	}
	
	for(int t=0;t<time;)
	{
		min=9999;
		for(int i=0;i<n;i++)
		{
			if(ar[i].arr<=t && ar[i].burst<min && ar[i].flag==0)
			{
				min=ar[i].burst;
				index=i;
			}
		}
		ar[index].flag=1;
		ar[index].wait=t-ar[index].arr;
		ar[index].start=t;
		g[count++]=ar[index];
		
		t+=ar[index].burst;
		
		ar[index].turn=t-ar[index].arr;
	}
	display(ar,n);
	gantt(g,count,time);
	printf("\n");
}

void sfp(job ar[],int n)
{
	int time=0;
	float avgturn=0,avgwait=0;
	int min;
	int index;
	printf("\n\n\t\tSHORT REMAINING TIME FIRST (Pre Emptive)\n");
	time=0;
	int remain=0,endtime;
	job g[10];
	int count=0;
	
	for(int i=0;i<n;i++)
	{
		time+=ar[i].burst;
	}
	
	for(int t=0;remain!=n;t++)
	{
		min=9999;
		for(int i=0;i<n;i++)
		{
			if( ar[i].arr<=t && ar[i].rem<min && ar[i].rem>0)
			{
				min=ar[i].rem;
				index=i;
			}
		}
		if(count!=0 && g[count-1].pid != ar[index].pid)
		{
			ar[index].start=t;
			g[count++]=ar[index];
		}
		else if(count==0 && t==0)
		{
			ar[index].start=t;
			g[count++]=ar[index];
		}
		ar[index].rem-=1;
		
		if(ar[index].rem==0)
		{
			remain++;
			endtime=t+1;
			ar[index].turn=endtime-ar[index].arr;
			ar[index].wait=endtime-ar[index].burst-ar[index].arr;
		}	
	}
	display(ar,n);
	gantt(g,count,time);
	
}

void input(job ar[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("\nEnter PID : ");
		scanf("%d",&ar[i].pid);
		printf("Enter Arrival Time : ");
		scanf("%d",&ar[i].arr);
		printf("Enter Burst Time : ");
		scanf("%d",&ar[i].burst);
		ar[i].rem=ar[i].burst;
		ar[i].flag=0;
	}
	printf("\n");
}

int main()
{
	job ar[10];
	int n;
	int choice=3;
	while(choice!=0)
	{
		printf("\n\n\t\tCPU SCHEDULING ALGORITHMS\n");
		printf("1.FCFS\n2.SJF\n0.EXIT\nEnter Choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:			
				printf("\t\tFCFS CPU SCHEDULER\n");
				printf("Enter Number of Processes : ");
				scanf("%d",&n);
				input(ar,n);
				fcfs(ar,n);
				break;
			case 2:
				printf("\t\tSFJ CPU SCHEDULER\n");
				printf("1. Non Preemptive SJF\n2. Pre emptive SJF\nEnter your option : ");
				scanf("%d",&choice);
				printf("Enter Number of Processes : ");
				scanf("%d",&n);
				input(ar,n);
				if(choice==1)
					sfnp(ar,n);
				else if(choice==2)
					sfp(ar,n);
				else
					printf("Invalid Choice !!!\n");
				break;
		}
	}
	return 0;
}
