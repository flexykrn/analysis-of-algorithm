#include<stdio.h>
#include<conio.h>
void job(int jobIDs[], int deadlines[], int profits[], int n)
{
int temp, i, j, result[20], totalProfit = 0, maxDeadline=0;
for (i = 0; i < n-1; i++)
{
for (j = i+1; j < n; j++)
{
if (profits[i] < profits[j])
{
temp = profits[i];
profits[i] = profits[j];
profits[j] = temp;
temp = jobIDs[i];
jobIDs[i] = jobIDs[j];
jobIDs[j] = temp;
temp = deadlines[i];
deadlines[i] = deadlines[j];
deadlines[j] = temp;
}
}
}
for (i = 0; i < n; i++)
{
if (deadlines[i] > maxDeadline)
{ maxDeadline = deadlines[i]; }
}
for (i = 0; i < maxDeadline; i++)
{ result[i] = -1; }
for (i = 0; i < n; i++)
{
for (j = deadlines[i] - 1; j >= 0; j--)
{
if (result[j] == -1)
{result[j] = jobIDs[i];
totalProfit = totalProfit+profits[i];
break;
}
}
}
printf("Job Sequence: ");
for (i = 0; i < maxDeadline; i++)
{
if (result[i] != -1)
{ printf("Job %d ", result[i]); }
}
printf("\nTotal Profit: %d\n", totalProfit);
}
int main()
{
int n, i, jobIDs[20], profits[20], deadlines[20];
printf("Enter the number of jobs: ");
scanf("%d", &n);
printf("Enter the deadline and profit of jobs\n");
for (i = 0; i < n; i++)
{
jobIDs[i] = i + 1;
printf("Job %d: ", i + 1);
scanf("%d %d", &deadlines[i], &profits[i]);
}
job(jobIDs, deadlines, profits, n);
// getch();
return 0;
}
