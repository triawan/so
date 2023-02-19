#include <stdio.h>
#include <stdlib.h>

struct node
{
     int pno;
     int at, bt, pc, tat, wt;
     struct node *link;
};
struct node *temp, *newnode, *start = NULL, *ready = NULL, *newnode1, *temp1, *temp2, *newnode2;
struct pr
{
     int at, bt, no;
};
void findDetails(struct node *root);
void printGantt(struct node *root, int n);
void displayDetails(struct node *root, int n);
void findprocess(int time);

int main()
{
     int n, i = 0, j = 0;
     int ch = 0;
     while (ch != 3)
     {
          printf("\n1.Pilih FCFS\n2.Pilih SJF\n3.Keluar\nMasukkan Pilihan : ");
          scanf("%d", &ch);
          switch (ch)
          {
          case 1:
          {
               printf("Masukkan jumlah proses : ");
               scanf("%d", &n);
               struct pr pp[n], tv;
               for (i = 0; i < n; i++)
               {
                    printf("Masukkan rincian proses %d", i + 1);
                    printf("\nWaktu Kedatangan : ");
                    scanf("%d", &pp[i].at);
                    printf("Burst Time : ");
                    scanf("%d", &pp[i].bt);
                    printf("\nNomor Proses : ");
                    scanf("%d", &pp[i].no);
               }

               for (i = 0; i < n; i++)
               {
                    for (j = 0; j < n; j++)
                    {
                         if (pp[j].at > pp[j + 1].at)
                         {
                              tv = pp[j];
                              pp[j] = pp[j + 1];
                              pp[j + 1] = tv;
                         }
                    }
               }
               for (i = 0; i < n; i++)
               {
                    newnode = (struct node *)malloc(sizeof(struct node));
                    newnode->link = NULL;
                    newnode->at = pp[i].at;
                    newnode->bt = pp[i].bt;
                    newnode->pno = pp[i].no;
                    if (start == NULL)
                    {
                         start = newnode;
                         temp = newnode;
                    }
                    else
                    {
                         temp->link = newnode;
                         temp = newnode;
                    }
               }
               findDetails(start);
               printGantt(start, n);
               displayDetails(start, n);
               break;
          }
          case 2:
          {
               int i, j, n, t, p[30], bt[30], wt[30], tat[30];
               float awt = 0, atat = 0;
               printf("Masukkan jumlah proses : ");
               scanf("%d", &n);
               printf("Masukkan nomor proses : ");
               for (i = 0; i < n; i++)
               {
                    scanf("%d", &p[i]);
               }
               printf("Masukkan Burst time proses  : ");
               for (i = 0; i < n; i++)
               {
                    scanf("%d", &bt[i]);
               }
               for (i = 0; i < n; i++)
               {
                    for (j = 0; j < n - i - 1; j++)
                    {
                         if (bt[j] > bt[j + 1])
                         {
                              t = bt[j];
                              bt[j] = bt[j + 1];
                              bt[j + 1] = t;
                              t = p[j];
                              p[j] = p[j + 1];
                              p[j + 1] = t;
                         }
                    }
               }
               for (i = 0; i < n; i++)
               {
                    wt[i] = 0;
                    tat[i] = 0;
                    for (j = 0; j < i; j++)
                    {
                         wt[i] = wt[i] + bt[j];
                    }
                    tat[i] = wt[i] + bt[i];
                    awt = awt + wt[i];
                    atat = atat + tat[i];
                    printf("\n");
                    printf(" p%d\t\t ", p[i]);
                    printf(" %d\t\t ", bt[i]);
                    printf(" %d\t\t ", wt[i]);
                    printf(" %d\t\t ", tat[i]);
                    printf("\n");
               }
               printf("\n\nGantt Chart\n");
               for (i = 0; i < n; i++)
               {
                    printf(".................");
               }
               printf("\n");
               for (i = 0; i < n; i++)
               {
                    printf("|\tP%d\t", p[i]);
               }
               printf("|");
               printf("\n");
               for (i = 0; i < n; i++)
               {
                    printf(".................");
               }
               printf("\n");
               printf("0");
               for (i = 0; i < n; i++)
               {
                    printf("\t\t%d", tat[i]);
               }
               awt = awt / n;
               atat = atat / n;
               printf("\nAverage Waiting time = %f", awt);
               printf("\nAverage Turn Around time = %f", atat);
               break;
          }
          case 3:
          {
               break;
          }
          default:
          {
               printf("\nInvalid Case");
               break;
          }
          }
     }
     return 0;
}

void displayDetails(struct node *root, int n)
{
     float avgtat = 0, avgwt = 0;
     printf("\n\nRincian Proses :");
     while (root != NULL)
     {
          printf("\n\nProses %d", root->pno);
          printf("\nTurn Around Time : %d", root->tat);
          printf("\nWaiting Time %d", root->wt);
          avgtat = avgtat + root->tat;
          avgwt = avgwt + root->wt;
          root = root->link;
     }
     avgtat = avgtat / n;
     avgwt = avgwt / n;
     printf("\nRata-rata Turn Around Time : %.2f", avgtat);
     printf("\nRata-rata Waiting Time : %.2f", avgwt);
}

void printGantt(struct node *root, int n)
{
     int i;
     for (i = 0; i < n; i++)
     {
          printf(".................");
     }
     printf("\n");
     temp = root;
     for (i = 0; i < n; i++)
     {
          printf("|\tP%d\t", temp->pno);
          temp = temp->link;
     }
     printf("|");
     printf("\n");
     for (i = 0; i < n; i++)
     {
          printf(".................");
     }
     printf("\n");
     printf("%d", start->at);
     temp = root;
     for (i = 0; i < n; i++)
     {
          printf("\t\t%d", temp->pc);
          temp = temp->link;
     }
}

void findDetails(struct node *root)
{
     int fr = 0, ad;
     while (root != NULL)
     {
          ad = fr - root->at;
          if (ad < 0)
          {
               fr = fr + (ad * -1);
          }
          root->pc = fr + root->bt;
          root->tat = root->pc - root->at;
          root->wt = root->tat - root->bt;
          fr = fr + root->bt;
          root = root->link;
     }
}