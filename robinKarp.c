#include<stdio.h>
#include<string.h>
void main ()
{
	char txt[80], pat[80], flag=0;
	int q = 101;	// prime number
	int d = 256;
	printf ("Enter the text string \n");
	scanf ("%s", txt);
	printf ("Enter the pattern to be searched \n");
	scanf ("%s", pat);

	int M = strlen(txt);
	int N = strlen (pat);
	int i, j;
	int p = 0;	// hash value for pattern	
	int t = 0;	// hash value for text
	int h = 1;
   
	for (i = 0; i < N - 1; i++)
		h = (h * d) % q;
	for (i = 0; i < N; i++)
	{
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;
	}
	for (i = 0; i <= M - N; i++)
	{
		if (p == t)
		{
			for (j = 0; j < N; j++)
			{
				if (txt[i + j] != pat[j])
					break;
			}
			if (j == N)
			{
				printf ("Pattern found at index %d \n", i);
				flag=1;
			}
		}
		if (i < M - N)
		{
			t = (d * (t - txt[i] * h) + txt[i + N]) % q;
			if (t < 0)
				t = (t + q);
		}
   }
   if (flag==0)
   	printf("\n Pattern not found\n");
}