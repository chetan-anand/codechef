#include<stdio.h>
int main()
{
	int n,i,j,k,cnt1;
	long long int cnt;
	while(1)
	{
	    scanf("%d",&n);
	    if(n==0){break;}
	    cnt=0;
	    for(i=n;i>=3;i--)
	    {
	        cnt1=3;
	        for(;cnt1<i;cnt1+=2)
	        {
	            cnt=cnt+i-cnt1;
	        }
	    }
	    printf("%lld\n",cnt);
	}
	return 0;
}
