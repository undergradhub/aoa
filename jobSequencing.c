// Experiment No.9: Job sequencing with deadlines

#include <stdio.h>

typedef struct Job 
{
	int id, deadline, profit;
}Job;

void main()
{
  	int i, j, k, maxprofit, n;
	int timeslot[100], filledTimeSlot = 0, dmax = 0;
	Job jobs[100];

	printf("\nEnter the no. of jobs: ");
	scanf("%d",&n);
	
	printf("\nEnter the deadlines and profits of each job: ");
	for (i = 1; i <= n; i++)
	{
		jobs[i].id = i;
		scanf("%d %d",&jobs[i].deadline,&jobs[i].profit);
	}
	Job temp;

	//sort the jobs profit wise in descending order
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			if(jobs[i].profit > jobs[j].profit)
			{
				temp = jobs[i];
				jobs[i] = jobs[j];
				jobs[j] = temp;
			}
		}
	}

	// find dmax
	for(i = 1; i <= n; i++)
	{
		if(jobs[i].deadline > dmax)
			dmax = jobs[i].deadline;
	}
	printf("dmax: %d", dmax);

	// initialise all the time slots to -1 [-1 denotes EMPTY]
	for(i = 1; i <= dmax; i++)
		timeslot[i] = -1;

	// allocate timeslots to jobs
	for(i = 1; i <= n; i++)
	{
		if (dmax < jobs[i].deadline)
			k = dmax;
		else
			k = jobs[i].deadline;	
		while(k >= 1)
		{
			if(timeslot[k] == -1)
			{
				timeslot[k] = i;
				filledTimeSlot++;
				break;
			}
			k--;
		}
    	// if all time slots are filled then stop
		if(filledTimeSlot == dmax)
			break;
	}

	// required jobs
	printf("\nRequired Jobs: ");
	for(i = 1; i <= dmax; i++)
		printf("j%d ", jobs[timeslot[i]].id);

	//required profit
	maxprofit = 0;
	for(i = 1; i <= dmax; i++)
		maxprofit += jobs[timeslot[i]].profit;
	printf("\nMax Profit: %d\n", maxprofit);
}

