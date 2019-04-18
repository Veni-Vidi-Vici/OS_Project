/*
Made by: Mridul Krishn Rawat,
Uname: Chiku,
timestamp: 16/04/19
*/
#include<stdio.h> 
#include<stdlib.h>
#define in scanf
#define out printf
#define itr for

void cal_wait_time(int processes[], int n, int bt[], int wt[], int quantum) 
{ 
	int rem_bt[n],i; 
	itr ( i = 0 ; i < n ; i++) 
		rem_bt[i] = bt[i]; 

	int t = 0;
	while (1) 
	{ 
		int flagg = 1; 
		itr (i = 0 ; i < n; i++) 
		{ 
			if (rem_bt[i] > 0) 
			{ 
				flagg = 0;

				if (rem_bt[i] > quantum) 
				{ 
					t += quantum; 
					rem_bt[i] -= quantum; 
				} 
				else
				{ 
					t = t + rem_bt[i]; 
					wt[i] = t - bt[i]; 
					rem_bt[i] = 0; 
				} 
			} 
		} 
		if (flagg == 1) 
		break; 
	} 
} 


void cal_TAT(int processes[], int n, int bt[], int wt[], int tat[]) 
{ int p;
	itr (p = 0; p < n ; p++) 
		tat[p] = bt[p] + wt[p]; 
} 


void findavgTime(int processes[], int n, int bt[], int quantum) 
{ 
	int wt[n], tat[n], total_wt = 0, total_tat = 0; 
	
	cal_wait_time(processes, n, bt, wt, quantum); 
	
	cal_TAT(processes, n, bt, wt, tat); 
	
	out("Process \t Burst_time \t Wait_time \t TAT\n" );
	int k;
	itr (k=0; k<n; k++)
	{ 
		total_wt = total_wt + wt[k]; 
		total_tat = total_tat + tat[k]; 
		out("\n%d \t\t %d \t\t %d\t\t%d ",k+1, bt[k], wt[k], tat[k]);
	} 

	out("\n\nAvg waiting time: %.3f", (float)total_wt/(float)n);
	out("\nAvg waiting time: %.3f", (float)total_tat/(float)n);

} 


int main() 
{ 
	int n;
	out("Enter total  no. of process:");
	in("%d",&n);
	int processes[n];
	int burst_time[n];
	int j;
	itr(j = 0;j < n;j++)
	{
		out("Enter process :");
		in("%d",&processes[j]);
		
		out("Enter burst time :");
		in("%d",&burst_time[j]);
	}
	int quantum;  
	out("Enter timequantum :");
	in("%d",&quantum);
	
	findavgTime(processes, n, burst_time, quantum); 
	
	return 0; 
} 



