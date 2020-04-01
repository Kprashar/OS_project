//it is the final proper working project
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
printf("\n\n\n");
printf("///////////////////////Applying the SJF///////////////////////\n\n");
printf("\n\n\n");
printf("//////////////////////sorted according to arival time///////////////////////\n\n");
for(int i=0;i<no_of_process;i++)
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
printf("\t\t\t_____________________________________________________________________\n");
printf("\t\t\t|	Process	|	Arival Time	|	Burst Time	|\n");
printf("\t\t\t_____________________________________________________________________\n");
for(int i=0;i<no_of_process;i++)//print the values
	{
	
	printf("\t\t\t|	P%d	|	%0.00lf		|	%0.00lf		|\n",process[i], arival_time[i], burst_time[i]);
	printf("\t\t\t_____________________________________________________________________\n");
	}
long int k = 1;//doing sjf for waiting time
  double b_time = 0;

  for(int j=0;j<no_of_process;j++)
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
complition_time[0]=arival_time[0]+burst_time[0];
for(int i=1;i<no_of_process;i++){
complition_time[i]=complition_time[i-1]+burst_time[i];
}
for(int i=0;i<no_of_process;i++){
turnaround_time[i]=complition_time[i]-arival_time[i];
}
for(int i=0;i<no_of_process;i++){
 waiting_time[i]=turnaround_time[i]-burst_time[i];
}

 
  for(int i=0;i<no_of_process;i++)
  {
 wait_final += waiting_time[i];
    turnaround_final += turnaround_time[i];
  }
 wait_avg = wait_final/no_of_process;
  turnaround_avg=turnaround_final/no_of_process;
printf("///////////////////////SJF schedule///////////////////////\n\n");
printf("\n\n\n");
printf("\t\t\t__________________________________________________________________________________________________________________\n");
printf("\t\t\t|	Process	|	Arival Time	|	Burst Time	|	Turnaound Time	|	Waiting Time	|\n");
printf("\t\t\t___________________________________________________________________________________________________________________\n");
for(int i=0;i<no_of_process;i++)//print the values
	{
	
	printf("\t\t\t|	P%d	|	%0.00lf		|	%0.00lf		|	%0.00lf		|	%0.00lf		|\n",process[i], arival_time[i], burst_time[i], turnaround_time[i], waiting_time[i]);
	printf("\t\t\t___________________________________________________________________________________________________________________\n");
	}
print("////////////////////////////priority of process are following/////////////////////////")
 for(int i=0;i<no_of_process;i++)
  {
    priority[i] = 1+waiting_time[i]/burst_time[i];
    printf("P%d->> %lf\n",process[i],priority[i]);
}
printf("average waiting time is: %lf\n",wait_avg);
printf("averge turnaround is: %lf\n",turnaround_avg);	
for(int i=0;i<no_of_process;i++)
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
      
	temp = priority[j+1];
        priority[j+1] = priority[j];
        priority[j] = temp;
      }
    }
  }
printf("\n\n\n");
printf("//////////////////////sorted according to arival time///////////////////////\n\n");
printf("\n\n\n");
printf("\t\t\t_____________________________________________________________________\n");
printf("\t\t\t|	Process	|	Arival Time	|	Burst Time	|\n");
printf("\t\t\t_____________________________________________________________________\n");
for(int i=0;i<no_of_process;i++)//print the values
	{
	
	printf("\t\t\t|	P%d	|	%0.00lf		|	%0.00lf		|\n",process[i], arival_time[i], burst_time[i]);
	printf("\t\t\t_____________________________________________________________________\n");
	}
printf("\n\n\n");
long int k2 = 1;//scheduling acording to priority
  double b_time2 = 0;
  for(int j=0;j<no_of_process;j++)
  {
    b_time2 = b_time2 + burst_time[j];
    max = priority[k2];

    for(int i=k2;i<no_of_process;i++)
    {
      if((b_time2 >= arival_time[i])&&(priority[i]>max))
      {
        temp = burst_time[k2];
        burst_time[k2] = burst_time[i];
        burst_time[i] = temp;
	
	temp = priority[k2];
        priority[k2] = priority[i];
        priority[i] = temp;

        temp = arival_time[k2];
        arival_time[k2] = arival_time[i];
        arival_time[i] = temp;

        temp = process[k2];
        process[k2] = process[i];
        process[i] = temp;
      }
    }
    k2++;
  }

   complition_time[0]=arival_time[0]+burst_time[0];
for(int i=1;i<no_of_process;i++){
complition_time[i]=complition_time[i-1]+burst_time[i];
}
for(int i=0;i<no_of_process;i++){
turnaround_time[i]=complition_time[i]-arival_time[i];
}
for(int i=0;i<no_of_process;i++){
 waiting_time[i]=turnaround_time[i]-burst_time[i];
}
  
  for(int i=0;i<no_of_process;i++)
  {
wait_final2 += waiting_time[i]; 
    turnaround_final2 += turnaround_time[i];
  }
  wait_avg2 = wait_final2/no_of_process;
  turnaround_avg2=turnaround_final2/no_of_process;
printf("\n\n\n");
printf("//////////////////////sorted according to priority///////////////////////\n\n");
printf("\n\n\n");
printf("\t\t__________________________________________________________________________________________________________________\n");
printf("\t\t|	Process	|	Arival Time	|	Burst Time	|	Turnaound Time	|	Waiting Time	|	Piority	|\n");
printf("\t\t___________________________________________________________________________________________________________________\n");
for(int i=0;i<no_of_process;i++)//print the values
	{
	
	printf("\t\t|	P%d	|	%0.00lf		|	%0.00lf		|	%0.00lf		|	%0.00lf		|	%lf	|\n",process[i], arival_time[i], burst_time[i], turnaround_time[i], waiting_time[i], priority[i]);
	printf("\t\t___________________________________________________________________________________________________________________\n");
	}

printf("average new waiting time is: %lf\n",wait_avg2);
printf("averge new turnaround is: %lf\n",turnaround_avg2);
}
