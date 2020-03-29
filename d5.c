//in this we are finding the priority
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
char q;
int process[no_of_process];//declaring the vaibles
double priority[no_of_process], complition_time[no_of_process], turnaround_time[no_of_process], waiting_time[no_of_process], arival_time[no_of_process], burst_time[no_of_process],min,max,sum=0,sum2=0,sum3=0,sum4=0,wait_final, turnaround_final, wait_avg, turnaround_avg,avg_waiting,avg_turnaround,wait_final2, turnaround_final2, wait_avg2, turnaround_avg2,avg_waiting2,avg_turnaround2, temp;//declaring the vaibles
printf("\n\n\n");
enter:
for(int i=0;i<no_of_process;i++)//asking burst time and arival time from user
	{
	printf("Enter the value of arival time for process %d->> ",i);
	scanf("%lf",&arival_time[i]);
	printf("Enter the value of burst time for process %d->> ",i);
	scanf("%lf",&burst_time[i]);
	printf("\n");
	process[i]=i+1; 
	}
printf("///////////////////////values that are enterd///////////////////////\n\n");
printf("\t\t\t_____________________________________________________________________\n");
printf("\t\t\t|	Process	|	Arival Time	|	Burst Time	|\n");
printf("\t\t\t_____________________________________________________________________\n");
for(int i=0;i<no_of_process;i++)//print the values
	{
	
	printf("\t\t\t|	P%d	|	%0.00lf		|	%0.00lf		|\n",process[i], arival_time[i], burst_time[i]);
	printf("\t\t\t_____________________________________________________________________\n");
	}
printf("\n\n\n");
/*printf("The entery is correct Y/N->> ");
invalid:
scanf("%d",&q);
int p=q;
if (p==156){goto enter;}
else if(p==116){goto enter;}
else if(p==171){printf("ok\n\n");}
else if(p==131){printf("ok\n\n");}
else goto invalid;*/
printf("\n\n\n");
printf("///////////////////////Applying the SJF///////////////////////\n\n");
printf("\n\n\n");
printf("//////////////////////sorted according to arival time///////////////////////\n\n");
for(int i=0;i<no_of_process;i++)//sorted according to arival time
  {
    for(int j=0;j<no_of_process-1;j++)
    {
      if(arival_time[j]>arival_time[j+1])
      {
        
        temp = burst_time[j+1];
        burst_time[j+1] = burst_time[j];
        burst_time[j] = temp;
	
	      temp = process[j+1];
        process[j+1] = process[j];
        process[j] = temp;

	      temp = arival_time[j];
        arival_time[j] = arival_time[j+1];
        arival_time[j+1] = temp;
      
      }
    }
  }
printf("\t\t\t_____________________________________________________________________\n");//printing the table
printf("\t\t\t|	Process	|	Arival Time	|	Burst Time	|\n");
printf("\t\t\t_____________________________________________________________________\n");
for(int i=0;i<no_of_process;i++)//print the values
	{
	
	printf("\t\t\t|	P%d	|	%0.00lf		|	%0.00lf		|\n",process[i], arival_time[i], burst_time[i]);
	printf("\t\t\t_____________________________________________________________________\n");
	}
long int k = 1;
  double b_time = 0;

  for(int j=0;j<no_of_process;j++)//sorted according to sjf
  {
    b_time = b_time + burst_time[j];
    min = burst_time[k];
    for(int i=k;i<no_of_process;i++)
    {
      if((b_time >= arival_time[i])&&(burst_time[i]<min))
      {
        temp = burst_time[k];
        burst_time[k] = burst_time[i];
        burst_time[i] = temp;

        temp = arival_time[k];
        arival_time[k] = arival_time[i];
        arival_time[i] = temp;

        temp = process[k];
        process[k] = process[i];
        process[i] = temp;
      }
    }

    k++;
  
}
  waiting_time[0] = 0;
  for(int i=1;i<no_of_process;i++)
  {
    sum += burst_time[i-1];
    waiting_time[i] = sum - arival_time[i];
    wait_final += waiting_time[i]; 
  }
  wait_avg = wait_final/no_of_process;
  for(int i=0;i<no_of_process;i++)
  {
    sum2 += burst_time[i];
    turnaround_time[i] = sum2 - arival_time[i];
    turnaround_final += turnaround_time[i];
  }
  turnaround_avg=turnaround_final/no_of_process;
printf("///////////////////////SJF schedule///////////////////////\n\n");//printing the table
printf("\n\n\n");
printf("\t\t\t__________________________________________________________________________________________________________________\n");
printf("\t\t\t|	Process	|	Arival Time	|	Burst Time	|	Turnaound Time	|	Waiting Time	|\n");
printf("\t\t\t___________________________________________________________________________________________________________________\n");
for(int i=0;i<no_of_process;i++)//print the values
	{
	
	printf("\t\t\t|	P%d	|	%0.00lf		|	%0.00lf		|	%0.00lf		|	%0.00lf		|\n",process[i], arival_time[i], burst_time[i], turnaround_time[i], waiting_time[i]);
	printf("\t\t\t___________________________________________________________________________________________________________________\n");
	}
printf("average waiting time is: %lf\n",wait_avg);
printf("averge turnaround is: %lf\n",turnaround_avg);
