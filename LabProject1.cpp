#include<iostream>
#include <algorithm>
#include <iomanip>
#include <string.h>
using namespace std;
void fcfs(){
struct pro{
    int pid;
    int burstTime;
    int waitingTime;
};
    int n,sum=0;
    cout<<"Enter the number of processes:"<<endl;
    cin>>n;
    pro p[n];

    for(int i=0;i<n;i++){
        cout<<"Enter the process Id and burst time of P"<<i+1<<" :"<<endl;
        cin>>p[i].pid;
        cin>>p[i].burstTime;
    }
    p[0].waitingTime=0;
    for(int i=0;i<n;i++){
        p[i+1].waitingTime=p[i].waitingTime+p[i].burstTime;

    }
    cout<<"Process execution:"<<endl;
    for(int i=0;i<n;i++){
        cout<<p[i].pid<<" ";
    }
    cout<<endl;
    cout<<"Waiting time:"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Waiting time of process P"<<i+1<<" is:"<<p[i].waitingTime<<"ms"<<endl;
    }
    for(int i=0;i<n;i++){
        sum=sum+p[i].waitingTime;
    }
    float avg;
    avg=(float)sum/n;
    cout<<"Average waiting time: "<<avg<<"ms"<<endl;
    cout<<endl;
}
void sjf(){
    struct process{
    int pid;
    int burstTime;
    int waitingTime;
};
    int n,sum=0;
    cout<<"Enter number of processes:"<<endl;
    cin>>n;
    process p[n];

    for(int i=0;i<n;i++){
        cout<<"Enter the process Id and burst time of P"<<i+1<<" :"<<endl;
        cin>>p[i].pid;
        cin>>p[i].burstTime;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(p[i].burstTime>p[j].burstTime){
                process temp= p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    cout<<"Process execution serial:"<<endl;
    for(int i=0;i<n;i++){
        cout<<"P"<<p[i].pid<<" ";
    }
    cout<<endl;
    p[0].waitingTime=0;
    for(int i=0;i<n;i++){
        p[i+1].waitingTime=p[i].waitingTime+p[i].burstTime;

    }
    cout<<"Waiting time:"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Waiting time of process P"<<p[i].pid<<" is:"<<p[i].waitingTime<<"ms"<<endl;
    }
    for(int i=0;i<n;i++){
        sum=sum+p[i].waitingTime;
    }
    float avg;
    avg=(float)sum/n;
    cout<<"Average waiting time: "<<avg<<"ms"<<endl;
    cout<<endl;
}
void srtf(){
    struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int waiting_time;
};
    int n;
    struct process p[100];
    float avg_waiting_time;
    int total_waiting_time = 0;
    int burst_remaining[100];
    int is_completed[100];
    memset(is_completed,0,sizeof(is_completed));

    cout << setprecision(2) << fixed;

    cout<<"Enter the number of processes: ";
    cin>>n;

    for(int i = 0; i < n; i++) {
        cout<<"Enter arrival time of process "<<i+1<<": ";
        cin>>p[i].arrival_time;
        cout<<"Enter burst time of process "<<i+1<<": ";
        cin>>p[i].burst_time;
        p[i].pid = i+1;
        burst_remaining[i] = p[i].burst_time;
        cout<<endl;
    }

    int current_time = 0;
    int completed = 0;
    int prev = 0;

    while(completed != n) {
        int idx = -1;
        int mn = 10000000;
        for(int i = 0; i < n; i++) {
            if(p[i].arrival_time <= current_time && is_completed[i] == 0) {
                if(burst_remaining[i] < mn) {
                    mn = burst_remaining[i];
                    idx = i;
                }
                if(burst_remaining[i] == mn) {
                    if(p[i].arrival_time < p[idx].arrival_time) {
                        mn = burst_remaining[i];
                        idx = i;
                    }
                }
            }
        }

        if(idx != -1) {
            if(burst_remaining[idx] == p[idx].burst_time) {
                p[idx].start_time = current_time;
            }
            burst_remaining[idx] -= 1;
            current_time++;
            prev = current_time;

            if(burst_remaining[idx] == 0) {
                p[idx].waiting_time = (current_time-p[idx].arrival_time) - p[idx].burst_time;
                total_waiting_time += p[idx].waiting_time;

                is_completed[idx] = 1;
                completed++;
            }
        }
        else {
             current_time++;
        }
    }

    avg_waiting_time = (float) total_waiting_time / n;


    cout<<"Average Waiting Time = "<<avg_waiting_time<<"ms"<<endl;
    cout<<endl;
}
void priority(){
    struct process{
    int pid;
    int priority;
    int bt;
    int wt;
};
    int n,sum=0;
    cout<<"Enter the number of processes:"<<endl;
    cin>>n;
    process p[n];
    for(int i=0;i<n;i++){
        cout<<"Enter Burst time and priority of process "<<i+1<<":"<<endl;
        cin>>p[i].bt;
        cin>>p[i].priority;
        p[i].pid=i+1;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(p[i].priority>p[j].priority){
                process temp = p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    p[0].wt=0;
    for(int i=0;i<n;i++){
        p[i+1].wt=p[i].wt+p[i].bt;

    }
    cout<<"Process execution serial:";
    for(int i=0;i<n;i++){
        cout<<"P"<<p[i].pid<<" ";
        sum+=p[i].wt;
    }
    cout<<endl;
    float avgwt;
    avgwt=(float)sum/n;
    cout<<"Average waiting time:"<<avgwt<<"ms"<<endl<<endl;
}
int main(){
    while(true){
        cout<<"Press 1 for FCFS\t\t\tPress 2 for SJF\nPress 3 for SRTF"
                "\t\t\tPress 4 for Round Robin\nPress 5 for Priority Scheduling\t\tPress 6 for Priority Scheduling with Round Robin\nPress 0 to exit\n";
        cout<<"Enter choice:";
        int n;
        cin>>n;
        if(n==1){
          fcfs();
        }
        else if(n==2){
            sjf();
        }
        else if(n==3){
            srtf();
        }
        else if(n==4){

        }
        else if(n==5){
            priority();
        }
        else if(n==6){

        }
        else if(n==0){
            break;
        }
    }
return 0;
}
