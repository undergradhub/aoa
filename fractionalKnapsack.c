// Experiment No.8: Fractional knapsack

# include<stdio.h>

void main()
{
	float weight[20], profit[20], capacity;
	int n, i, j;
	float ratio[20], fract=1.0, tp=0, temp;
	
	printf("\nEnter the capacity of knapsack:- ");
	scanf("%f",&capacity);	
 
	printf("\nEnter the no. of items:- ");
	scanf("%d",&n);
	
	printf("\nEnter the weights and profits of each item:- ");
	for (i = 0; i < n; i++)
		scanf("%f %f",&weight[i],&profit[i]);


	for (i = 0; i < n; i++)
		ratio[i] = profit[i] / weight[i];

	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (ratio[i] < ratio[j])
         	{
				temp = ratio[j];
				ratio[j] = ratio[i];
				ratio[i] = temp;
 
				temp = weight[j];
				weight[j] = weight[i];
				weight[i] = temp;
 
				temp = profit[j];
				profit[j] = profit[i];
				profit[i] = temp;
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		if (weight[i] > capacity)
			break;
		else
		{
			tp = tp + profit[i];
			capacity = capacity - weight[i];
		}
	}
	printf("%f ",tp); 
	if (i < n)
		fract = capacity / weight[i];
 
	tp = tp + (fract * profit[i]);
 
	printf("\nMaximum profit is:- %f ", tp);
}