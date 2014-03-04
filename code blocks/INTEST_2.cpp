#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;

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



int main()
{
	int n,k,i,j,cnt;
	cnt=0;int temp;
	fastRead_int(n);
	fastRead_int(k);
	//scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	{
		fastRead_int(temp);
		if(temp%k==0){cnt++;}
	}
    printf("%d\n",cnt);
	return 0;
}
