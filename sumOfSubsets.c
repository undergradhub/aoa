#include <stdio.h>

void subsetSum(int set[], int subSet[], int n, int subSize, int total, int nodeCount ,int sum)
{
	int i;
	if(total==sum && subSize >1)
	{
		printf("\n");
		for(i = 0; i < subSize; i++)
			printf(" %d",subSet[i]);
		subsetSum(set,subSet,n,subSize-1,total-set[nodeCount],nodeCount+1,sum);     //for other subsets
		return;
	}
	else
	{
		for(i=nodeCount; i < n; i++ )
		{     //find node along breadth
			subSet[subSize] = set[i];
			subsetSum(set,subSet,n,subSize+1,total+set[i],i+1,sum);     //do for next node in depth
		}
	}
}

void main()
{
	int weights[50], size, sum,i,n;
	int subSet[50];     //create subset array to pass parameter of subsetSum

	printf("\n Enter the sum : ");
	scanf("%d",&sum);

	printf("\n Enter the no. of elements: ");
	scanf("%d",&n);
	printf("\n Enter the of elements: ");
	for(i=0;i<size;i++)
		scanf("%d",&weights[i]);
   
	subsetSum(weights, subSet, n, 0, 0, 0, sum);
}