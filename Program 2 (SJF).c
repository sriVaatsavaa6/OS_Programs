#include <stdio.h>

int main() {
  int n, i, j, bt[20], p[20], wt[20]={0}, tat[20], pos, t; 
  float awt=0, atat=0;

  printf("Enter number of process: "); scanf("%d",&n);
  printf("\nEnter Burst Time:\n");
  for(i=0;i<n;i++){ 
      printf("p%d: ",i+1); 
      scanf("%d",&bt[i]); 
      p[i]=i+1; 
      
  }

  for(i=0;i<n;i++){                    // sort by burst time (SJF)
    pos=i; 
    for(j=i+1;j<n;j++) 
    if(bt[j]<bt[pos]) pos=j;
    t=bt[i]; bt[i]=bt[pos]; bt[pos]=t; 
    t=p[i]; p[i]=p[pos]; p[pos]=t;
  }

  for(i=1;i<n;i++){ 
      wt[i]=wt[i-1]+bt[i-1]; 
      awt+=wt[i]; 
  }

  printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for(i=0;i<n;i++){
    tat[i]=bt[i]+wt[i]; atat+=tat[i];
    printf("p%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
  }
  printf("\nAverage Waiting Time=%f", awt/n);
  printf("\nAverage Turnaround Time=%f\n", atat/n);
  return 0;
}
