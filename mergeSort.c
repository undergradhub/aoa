#include<stdio.h>

void mergesort(int[],int,int);
void combine(int[],int,int,int);

void main()
{
	int a[10],n,i;
	printf("\n Enter no of elements ");
	scanf("%d",&n);
	printf("\n Enter the elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	mergesort(a,0,n-1);
	printf("\nSorted array is \n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}

void mergesort(int a[10],int low, int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		combine(a,low,mid,high);
	}
}

void combine(int a[10],int low,int mid, int high)
{
	int i,j,k,temp[10];
	i=low;
	j=mid+1;
	k=low;

	while(i<=mid && j<=high)
	{
		if(a[i]<a[j])
		{
			temp[k]=a[i];
			k++;
			i++;
		}
		else
		{
			temp[k]=a[j];
			k++;
			j++;
		}
	}
	while(i<=mid)
	{
		temp[k]=a[i];
		k++;
		i++;
	}
	while(j<=high)
	{
		temp[k]=a[j];
		k++;
		j++;
	}
	for(i=low;i<=high;i++)
		a[i]=temp[i];
}