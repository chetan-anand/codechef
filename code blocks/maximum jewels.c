#include <stdio.h>
#define M 4
#define N 4

int result[M][N];
int apples[M][N] ={
			{0, 23,-56, -32},
			{13, 14,-32,-44},
			{23,19,-3,-35},
			{46,27 , 20, 0}
		};

int getMax(int i, int j)
{
	if( (i<M) && (j<N) )
	{
		if( result[i][j] != 0 )
			return result[i][j];
		else
		{
			int right = getMax(i, j+1);
			int down = getMax(i+1, j);

			result[i][j] = ( (right>down) ? right : down )+apples[i][j];
			return result[i][j];
		}
	}
	else
		return 0;
}

int main()
{
	printf("\n\nMax Apples = %d\n\n", getMax(0, 0));
}
