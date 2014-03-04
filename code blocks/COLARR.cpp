#include<bits/stdc++.h>
using namespace std;

///////////////////////////////////////////////////
inline void fastRead_int(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if(c=='-') {
    	neg = 1;
    	c = getchar_unlocked();
    }

    for(; c>47 && c<58 ; c = getchar_unlocked()) {
    	x = (x<<1) + (x<<3) + c - 48;
    }

    if(neg)
    	x = -x;
}
//////////////////////////////////////////////////////


int main()
{
	int t,n,m,k,a[1010],b[1010][1010],c[1010][1010],cnt,i,j,temp[1100],d[1100][1100];
	fastRead_int(t);
	while(t--)
	{
		cnt=0;
		memset(temp,0,sizeof(temp));
		fastRead_int(n);
		fastRead_int(m);
		fastRead_int(k);
		for(i=0;i<n;i++)
		{
			fastRead_int(a[i]);
			a[i]--;
		}
		for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
				fastRead_int(b[i][j]);
			}
        }
		for(i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				fastRead_int(c[i][j]);
				b[i][j]-=c[i][j];
				if(b[i][j]>temp[i])
					temp[i]=b[i][j];
			}
		}
		for(int i=0;i<n;i++)
		{
			cnt+=b[i][a[i]];
			temp[i]-=b[i][a[i]];
		}
		sort(temp,temp+n);
		for(int i=n-1;i>=n-k;i--)
			cnt+=temp[i];
		printf("%d\n",cnt);
	}
	return 0;
}
