#include <stdio.h>

void findWaitingTime(int n, int bt[], int wt[]) {
    wt[0] = 0; // First process always has 0 waiting time
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

void findTurnAroundTime(int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void printGanttChart(int processes[], int n, int bt[]) {
    printf("\n=== GANTT CHART ===\n ");
    
    // Top bar of the chart
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bt[i]; j++) printf("--");
        printf(" ");
    }
    printf("\n|");

    // Process IDs inside the chart
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bt[i] - 1; j++) printf(" ");
        printf("P%d", processes[i]);
        for (int j = 0; j < bt[i] - 1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");

    // Bottom bar of the chart
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bt[i]; j++) printf("--");
        printf(" ");
    }
    printf("\n0");

    // Timeline numbers below the chart
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        current_time += bt[i];
        for (int j = 0; j < bt[i]; j++) printf("  ");
        printf("%d", current_time);
    }
    printf("\n");
}

int main() {
    int n;

    // Accept user input for number of processes
    printf("Enter the number of processes: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of processes.\n");
        return 1;
    }

    int processes[n];
    int burst_time[n];
    int wt[n], tat[n];

    // Accept user input for burst times
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1; // Automatically assigns P1, P2, P3...
        printf("Enter burst time for Process P%d: ", processes[i]);
        if (scanf("%d", &burst_time[i]) != 1 || burst_time[i] < 0) {
            printf("Invalid burst time.\n");
            return 1;
        }
    }

    // Calculate times
    findWaitingTime(n, burst_time, wt);
    findTurnAroundTime(n, burst_time, wt, tat);

    // Print results table
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("P%d\t\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], wt[i], tat[i]);
    }

    // Print Averages
    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    // Print Gantt Chart
    printGanttChart(processes, n, burst_time);

    return 0;
}
