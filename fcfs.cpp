#include <iostream>
#include <stdlib.h>

using namespace std;

class Process {
    int id, burstTime, arrivalTime, completionTime, turnaroundTime, waitingTime;

public:
    void input(Process*, int);
    void calculateTimes(Process*, int);
    void sort(Process*, int);
    void show(Process*, int);
};

int main() {
    int n;
    cout << "Enter the total number of processes: ";
    cin >> n;

    Process* processes = new Process[n];
    Process p;
    p.input(processes, n);
    p.sort(processes, n);
    p.calculateTimes(processes, n);
    p.show(processes, n);
    delete[] processes;

    return 0;
}

void Process::input(Process* processes, int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nEnter arrival time for process " << i+1 << ": ";
        cin >> processes[i].arrivalTime;
        cout << "Enter burst time for process " << i+1 << ": ";
        cin >> processes[i].burstTime;
        processes[i].id = i+1;
    }
}

void Process::calculateTimes(Process* processes, int n) {
    int sum = processes[0].arrivalTime;
    for (int i = 0; i < n; i++) {
        sum = sum + processes[i].burstTime;
        processes[i].completionTime = sum;
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
        if (i < n-1 && sum < processes[i+1].arrivalTime) {
            int t = processes[i+1].arrivalTime - sum;
            sum = sum + t;
        }
    }
}

void Process::sort(Process* processes, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1; j++) {
            if (processes[j].arrivalTime > processes[j+1].arrivalTime) {
                int temp;
                // Swapping burst times
                temp = processes[j].burstTime;
                processes[j].burstTime = processes[j+1].burstTime;
                processes[j+1].burstTime = temp;
                // Swapping arrival times
                temp = processes[j].arrivalTime;
                processes[j].arrivalTime = processes[j+1].arrivalTime;
                processes[j+1].arrivalTime = temp;
                // Swapping process ids
                temp = processes[j].id;
                processes[j].id = processes[j+1].id;
                processes[j+1].id = temp;
            }
        }
    }
}

void Process::show(Process* processes, int n) {
    cout << "\nProcess\tArrival\tBurst\tWaiting\tTurnaround\tCompletion\n";
    for (int i = 0; i < n; i++) {
        cout << "P[" << processes[i].id << "]\t" << processes[i].arrivalTime << "\t"
             << processes[i].burstTime << "\t" << processes[i].waitingTime << "\t"
             << processes[i].turnaroundTime << "\t" << processes[i].completionTime << "\n";
    }
}
