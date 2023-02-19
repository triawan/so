#include <stdio.h>
#include <stdlib.h>

void FCFS();
void SJF();
void RR();
void PS();

// The main function contains a switch statement that calls one of the scheduling functions based on the user's input.
int main()
{
    printf("\n\n 1. FCFS \n 2. SJF \n 3. Round Robin \n 4. Priority Scheduling \n 5. Keluar");
    printf("\n Masukkan pilihan Anda : ");
    int cho;
    scanf("%d", &cho);
    switch (cho)
    {
    case 1:
        FCFS();
        main();
        break;

    case 2:
        SJF();
        main();
        break;

    case 3:
        RR();
        main();
        break;

    case 4:
        PS();
        main();
        break;

    case 5:
        exit(0);
        break;

    default:
        printf("Invalid Choice");
        break;
    }
}

/**
In the FCFS function, the program prompts the user to enter the number of processes and their burst times. 
It calculates the waiting time and turnaround time for each process and displays them along with the average waiting time 
and average turnaround time for all processes. 
**/
void FCFS()
{
    int n, bt[20], wt[20], tat[20], avwt = 0, avtat = 0, i, j;
    printf(" Masukkan total jumlah proses : ");
    scanf("%d", &n);
    printf("\n Masukkan Proses Burst Time : ");
    for (i = 0; i < n; i++)
    {
        printf("\n P[%d] : ", i + 1);
        scanf("%d", &bt[i]);
    }
    wt[0] = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
        {
            wt[i] += bt[j];
        }
    }
    printf("\n Proses\tBurst Time\tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        avwt += wt[i];
        avtat += tat[i];
        printf("\n P[%d] \t\t\t %d \t\t %d \t\t %d", i + 1, bt[i], wt[i], tat[i]);
    }
    avwt /= i;
    avtat /= i;
    printf("\n\n Rata-rata Waiting Time:%d", avwt);
    printf("\n Rata-rata Turnaround Time:%d", avtat);
}


/*
In the SJF function, the program prompts the user to enter the number of processes and their burst times. 
It then sorts the processes in ascending order of their burst times using selection sort algorithm. 
The program then calculates the waiting time and turnaround time for each process and displays them along 
with the average waiting time and average turnaround time for all processes.
*/
void SJF()
{
    int bt[20], p[20], wt[20], tat[20], i, j, n, total = 0, pos, temp;
    float avg_wt, avg_tat;
    printf(" Masukkan jumlah proses:");
    scanf("%d", &n);
    printf("\n Masukkan Prosees Burst Time : ");
    for (i = 0; i < n; i++)
    {
        printf("\n P[%d] : ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (bt[j] < bt[pos])
            {
                pos = j;
            }
        }
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }
    wt[0] = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
        {
            wt[i] += bt[j];
            total += wt[i];
        }
    }
    avg_wt = (float)total / n;
    total = 0;
    printf("\nProses\t Burst Time \tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
        printf("\n p%d\t %d\t\t %d\t\t\t%d", p[i], bt[i], wt[i], tat[i]);
    }
    avg_tat = (float)total / n;
    printf("\n\n Rata-rata Waiting Time=%f", avg_wt);
    printf("\n Rata-rata Turnaround Time=%f\n", avg_tat);
}

/*
In the RR function, the program prompts the user to enter the number of processes, their arrival times and burst times, 
and the time quantum. It simulates the Round Robin scheduling algorithm by repeatedly allocating the time quantum to each process 
until all processes have completed execution. The program calculates the waiting time and turnaround time for each process 
and displays them along with the average waiting time and average turnaround time for all processes.
*/
void RR()
{
    int count, n, time, remain, flag = 0, time_quantum;
    int wait_time = 0, turnaround_time = 0, at[10], bt[10], rt[10];
    printf(" Masukkan jumlah proses:\t ");
    scanf("%d", &n);
    remain = n;
    printf("\n Masukkan proses Burst Time : ");
    for (count = 0; count < n; count++)
    {
        printf("\n P[%d] : ", count + 1);
        at[count] = count;
        scanf("%d", &bt[count]);
        rt[count] = bt[count];
    }
    printf(" Masukkan Time Quantum:\t");
    scanf("%d", &time_quantum);
    printf("\nProcess\t Turnaround Time \tWaiting Time\n");
    for (time = 0, count = 0; remain != 0;)
    {
        if (rt[count] <= time_quantum && rt[count] > 0)
        {
            time += rt[count];
            rt[count] = 0;
            flag = 1;
        }
        else if (rt[count] > 0)
        {
            rt[count] -= time_quantum;
            time += time_quantum;
        }
        if (rt[count] == 0 && flag == 1)
        {
            remain--;
            printf("P[%d]\t\t%d\t\t\t%d\n", count + 1, time - at[count], time - at[count] - bt[count]);
            wait_time += time - at[count] - bt[count];
            turnaround_time += time - at[count];
            flag = 0;
        }
        if (count == n - 1)
        {
            count = 0;
        }
        else if (at[count + 1] <= time)
        {
            count++;
        }
        else
        {
            count = 0;
        }
    }
    printf("\n Average Waiting Time= %f\n", wait_time * 1.0 / n);
    printf(" Avg Turnaround Time = %f", turnaround_time * 1.0);
}

/*
In the PS function, the program prompts the user to enter the number of processes, their burst times, and their priority levels. 
It sorts the processes in ascending order of their priority levels using selection sort algorithm. 
The program then calculates the waiting time and turnaround time for each process and displays them along with 
the average waiting time and average turnaround time for all processes.
*/
void PS()
{
    typedef struct
    {
        int pno;
        int pri;
        int btime;
        int wtime;
    } sp;
    int i, j, n;
    int tbm = 0, totwtime = 0, totttime = 0;
    sp *p, t;
    printf("\n Masukkan nomor proses : ");
    scanf("%d", &n);
    p = (sp *)malloc(sizeof(sp));
    printf(" Masukkan burst time and priority : ");
    for (i = 0; i < n; i++)
    {
        printf("\n P[%d] : ", i + 1);
        scanf("%d%d", &p[i].btime, &p[i].pri);
        p[i].pno = i + 1;
        p[i].wtime = 0;
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (p[i].pri > p[j].pri)
            {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }
    printf("\n Proses\tBursttime\tWaiting time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        totwtime += p[i].wtime = tbm;
        tbm += p[i].btime;
        printf("\n%d\t\t%d", p[i].pno, p[i].btime);
        printf("\t\t%d\t\t%d", p[i].wtime, p[i].wtime + p[i].btime);
    }
    totttime = tbm + totwtime;
    printf("\n Total waiting time:%d", totwtime);
    printf("\n Rata-rata waiting time:%f", (float)totwtime / n);
    printf("\n Total turnaround time:%d", totttime);
    printf("\n Rata-rata turnaround time:%f", (float)totttime / n);
}