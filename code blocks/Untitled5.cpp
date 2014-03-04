#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int a[100010];
int t[100010];

int main()
{
	int cases , n  , count , ind;
	bool flag;
	cin >> cases;
	while( cases-- )
	{
		count = 0;
		flag = false;
		memset( t , 0 , sizeof( t ));
		cin >> n;
		for( int i = 0 ; i < n ; i++ )
		{
			cin >> a[i];
			t[a[i]] = 1;
		}
	//	sort( a , a + n );
		for( int i = 0 ; i < n ; i++ )
		{
			if( t[a[i]] )
			{
			if( t[2 * a[i]] && t[2 * a[i] + 1] )
			{
				int ind1 = 2 * a[i] , ind2 = 2 * a[i] + 1;
				if(( t[ 2 * ind1] || t[ 2 * ind1+1] )  && ( t[2 * ind2] || t[ 2 * ind2 + 1 ] ))
				{
					if( t[ 2 * ind1] && t[ 2 * ind1+1] )	t[ind1] = 0;
					else if( t[2 * ind2] && t[ 2 * ind2 + 1 ] )	t[ind2] = 0;
					else t[ind1] = 0;
					count++;
					t[a[i]] = 0;
				}
				else if( (t[ 2 * ind1]) || t[ 2 * ind1 + 1] )
				{
					t[ind2] = 0;
					count++;
					t[a[i]] = 0;
				}
				else if( t[2 * ind2] || t[ 2 * ind2 + 1] )
				{
					t[ind1] = 0;
					count++;
					t[a[i]] = 0;
				}
				else  if(!( t[ 2 * ind1] || t[ 2 * ind1+1] )  || ( t[2 * ind2] || t[ 2 * ind2 + 1 ] ))
				{
					t[ind1] = t[ind2] = 0;
					count++;
					t[a[i]] = 0;
				}
			}
				else if( t[2*a[i]] ){ flag = true; ind = 2*a[i]; }
				else if ( t[ 2*a[i] + 1] ){ flag = true; ind = 2*a[i]+1;}
				if( flag ){ count++; t[ind] = 0; t[a[i]] = 0; flag = false; }
			}
		}
		cout << count << endl;
	}
	return 0;
}





