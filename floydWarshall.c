// Experiment No.6: Find all pair shortest path using Floyd-Warshall algorithm

#include <stdio.h>
#define n 4
#define INF 999

int main()
{
	int A[n][n] = 	{{0, 5, 9, INF},
					{INF, 0, 1, INF},
					{INF, INF, 0, 2},
					{INF, 3, INF, 0}};
	int i, j, k;

	for (k = 0; k < n; k++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (A[i][k] + A[k][j] < A[i][j])
					A[i][j] = A[i][k] + A[k][j];
			}
    	}
	}

	printf("\n The shortest distances from every pair of vertices are:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (A[i][j] == INF)
				printf("%s\t", "INF");
			else
				printf("%d\t", A[i][j]);
		}
		printf("\n");
	}
}