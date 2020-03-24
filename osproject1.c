// It is first phase of my project it is taking intial values and printing them.
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
int main(){
int no_of_process, estimated_run_time;//declaring the vaibles
printf("Enter the no. of processes which should be performed->> ");
scanf("%d",&no_of_process); //asking value from user
int process[no_of_process];//declaring the vaibles
double priority[no_of_process], complition_time[no_of_process], turnaround_time[no_of_process], waiting_time[no_of_process], arival_time[no_of_process], burst_time[no_of_process];//declaring the vaibles
printf("\n\n\n");
for(int i=0;i<no_of_process;i++)//asking burst time and arival time from user
	{
	printf("Enter the value of arival time for process %d->> ",i);
	scanf("%lf",&arival_time[i]);
	printf("Enter the value of burst time for process %d->> ",i);
	scanf("%lf",&burst_time[i]);
	process[i]=i+1; 
	}
printf("///////////////////////values that are enterd///////////////////////\n\n");
printf("\t\t\t_____________________________________________________________________\n");
printf("\t\t\t|	Process	|	Burst Time	|	Arival Time	|\n");
printf("\t\t\t_____________________________________________________________________\n");
for(int i=0;i<no_of_process;i++)//printong the values
	{
	
	printf("\t\t\t|	P%d	|	%0.00lf		|	%0.00lf		|\n",process[i], arival_time[i], burst_time[i]);
	printf("\t\t\t_____________________________________________________________________\n");
	}
}
