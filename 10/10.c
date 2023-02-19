#include <stdio.h>
#include <stdlib.h>
int m, n;
void Safety(int Available[], int Max[][m], int Allocation[][m])
{
    int Work[m], Finish[n], Need[n][m];
    for (int i = 0; i < m; i++)
    {
        Work[i] = Available[i];
    }
    for (int i = 0; i < n; i++)
    {
        Finish[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }
    printf("\nKebutuhan\n");
    printf("====\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", Need[i][j]);
            printf("\n");
        }
    }
    int s = 0;
    int safeSequence[n];
    int count = 0;
    while (count != n)
    {
        for (int i = 0; i < n; i++)
        {
            int counter = 0;
            for (int j = 0; j < m; j++)
            {
                if (Need[i][j] <= Work[j] && Finish[i] == 0)
                {
                    counter++;
                }
                else
                {
                    break;
                }
            }
            if (counter == m)
            {
                for (int j = 0; j < m; j++)
                {
                    Work[j] = Work[j] + Allocation[i][j];
                }
                Finish[i] = 1;
                safeSequence[s] = i;
                s++;
            }
        }
        count++;
    }
    int flag = 0;
    for (int i = 0; i < s; i++)
    {
        if (Finish[i] == 1)
        {
            flag++;
        }
    }
    if (flag == n)
    {
        printf("\nSistem dalam kondisi aman!\n");
        printf("Urutan aman:");
        for (int i = 0; i < s; i++)
        {
            printf("P%d ", safeSequence[i]);
        }
        printf("\n");
    }
    else
    {
        printf("\nSistem tidak dalam keadaan aman");
    }
}
void input()
{
    int i, j;
    printf("Total sumber daya sistem:");
    scanf("%d", &m);
    printf("Masukkan jumlah proses:");
    scanf("%d", &n);
    int Available[m], Max[n][m], Allocation[n][m];
    printf("\nMasukkan sumber daya yang tersedia:\n");
    for (i = 0; i < m; i++)
    {
        printf(":");
        scanf("%d", &Available[i]);
    }
    printf("\nTersedia\n");
    printf("=========\n");
    for (i = 0; i < m; i++)
    {
        printf("%d ", Available[i]);
    }
    printf("\nMasukkan sumber daya yang saat ini dialokasikan untuk setiap proses:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf(":");
            scanf("%d", &Allocation[i][j]);
        }
    }
    printf("\nAlokasi\n");
    printf("==========\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", Allocation[i][j]);
        }
        printf("\n");
    }
    printf("\nMasukkan sumber daya yang dialokasikan maksimum untuk setiap proses:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf(":");
            scanf("%d", &Max[i][j]);
        }
    }
    printf("\nMaksimum\n");
    printf("===\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", Max[i][j]);
        }
        printf("\n");
    }
    Safety(Available, Max, Allocation);
}

int main()
{
    input();
    return 0;
}
