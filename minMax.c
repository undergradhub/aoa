// Experiment No.5: Find min & max element using divide and conquer */

#include <stdio.h>
int a[10],max,min;

void maxmin(int i, int j)
{
	int newmax,newmin,mid;
	if (i==j)
		max=min=a[i];
	else
	{
		if (i==j-1)
		{
			if (a[i] < a[j])
			{
				max = a[j];
				min = a[i];
			}
			else
			{
				max = a[i];
				min = a[j];
			}
		}
		else
		{
			mid = (i+j)/2;
			maxmin(i,mid);
			newmax=max;
			newmin=min;
			maxmin(mid+1,j);
			if(max < newmax)
				max = newmax;
			if(min > newmin)
				min = newmin;
		}
	}
}

void main()
{
	int n,i;
    	printf("\nEnter number of elements ");
   	scanf("%d",&n);

   	printf("\nEnter the elements ");
   	for (i=0;i<n;i++ )
		scanf("%d",&a[i]);

   	maxmin(0,n-1);
   	printf("\nMaximum element is : %d ",max);
   	printf("\nMinimum element is : %d ",min);
}