#include<stdio.h>
#include<conio.h>


int numImpCells = 0;
int output[6][6] = { 0 };


int countImpCells( int a[][6], int n, int m )
{
    //printf("countImpCells\n");
	int result = 0;
	bool temp[6][6] = { false };
	for(int i = 0; i < n; i++ )
	{
		for( int j = 0; j < m; j++ )
		{
			if( ( i == 0 ) && ( j== 0 ) )
			{
				temp[i][j] = true;
			}

			bool imp = true;
			if( ( i > 0 ) && temp[i-1][j] )
			{
				if( a[i][j] <= a[i-1][j] )
					imp = false;

				if( ( i > 1 ) && ( a[i][j] <= a[i-2][j] ) )
					imp = false;

				if( ( j > 0 ) && ( a[i][j] <= a[i-1][j-1] ) )
					imp = false;

				if( ( j < (m-1) ) && ( a[i][j] <= a[i-1][j+1] ) )
					imp = false;

				temp[i][j] = (imp || temp[i][j]);
			}

			if( ( j < (m-1) ) && temp[i][j+1] )
			{
				if( a[i][j] <= a[i][j+1] )
					imp = false;

				if( ( j < (m-2) ) && ( a[i][j] <= a[i][j+2] ) )
					imp = false;

				if( ( i > 0 ) && ( j < (m-1) ) && ( a[i][j] <= a[i-1][j+1] ) )
					imp = false;
				temp[i][j] = (imp || temp[i][j]);
			}

			if( ( i < (n-1) ) && temp[i+1][j] )
			{
				if( a[i][j] <= a[i+1][j] )
					imp = false;

				if( ( i < ( n-1)) && ( j < ( m - 1) ) && ( a[i][j] <= a[i+1][j+1] ) )
					imp = false;

				if( ( i < (n-2) ) && ( a[i][j] <= a[i+2][j] ) )
					imp = false;

				if( ( j > 0 ) && ( i < (n-1) ) && ( a[i][j] <= a[i+1][j-1] ) )
					imp = false;
				temp[i][j] = (imp || temp[i][j]);
			}

			if( ( j > 0 ) && temp[i][j-1] )
			{
				if( a[i][j] <= a[i][j-1] )
					imp = false;

				if( ( j > 1 ) && ( a[i][j] <= a[i][j-2] ) )
					imp = false;

				if( ( i > 0 ) && ( a[i][j] <= a[i-1][j-1] ) )
					imp = false;

				if( ( j > 0 ) && ( i < (n-1) ) && ( a[i][j] <= a[i+1][j-1] ) )
					imp = false;
				temp[i][j] = (imp || temp[i][j]);
			}
		}

	}

	for(int i = 0; i < n; i++ )
	{
		for( int j = 0; j < m; j++ )
		{
			if( temp[i][j] )
				result ++;
		}
	}

	return result;
}

void processsolution(int a[][6], int n, int m, bool usedNumbers[])
{
    //printf("processsolution\n");
	int count = countImpCells( a, n , m) ;
	if( count > numImpCells )
	{
		numImpCells = count;

		for(int i = 0; i < n; i++ )
		{
			for( int j = 0; j < m; j++ )
			{
				output[i][j] = a[i][j];
			}
		}
	}

}

void backtracking(int a[][6], int n, int m, bool usedNumbers[])
{
    printf("backtracking\n");
	bool finished = true;
	for( int i = 1; i <= n*m; i++ )
	{
		if( usedNumbers[i] == false )
			finished = false;
	}

	if( finished == true )
		processsolution( a, n, m, usedNumbers );

	for(int i = 0; i < n; i++ )
	{
		for( int j = 0; j < m; j++ )
		{
			if( a[i][j] == -1 )
			{
				for( int k = 1; k <= n*m; k++ )
				{
					if( usedNumbers[k] == false )
					{
						a[i][j] = k;
						usedNumbers[k] = true;

						backtracking( a, n, m, usedNumbers );

						usedNumbers[k] = false;
						a[i][j] = -1;
					}
				}

			}
		}
	}

}

int main(int argc, char* argv[])
{

	int n, m;
	scanf("%d %d", &n, &m);
	int a[6][6];
	bool usedNumbers[37] = {false};

	for(int i = 0; i < n; i++ )
	{
		for( int j = 0; j < m; j++ )
		{
			int result = scanf("%d", &a[i][j]);
			if( result <= 0 )
			{
				char c;
				scanf("%c", &c);
				a[i][j] = -1;
			}
			else
			{
				usedNumbers[a[i][j]] = true;
			}
		}
	}

	backtracking(a, n, m, usedNumbers);

	printf("\nResult: %d\n", numImpCells);
	for(int i = 0; i < n; i++ )
	{
		for( int j = 0; j < m; j++ )
		{
			printf("%d ", output[i][j]);
		}
		printf("\n");
	}

	getch();
	return 0;
}
