#include<stdio.h>
int main()
{
    int t,n,j,i,s;
    long long int ans,div,power,cnt;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);cnt=0;
        for(i=0;i<=n/2;i++)
        {
            if(i<n-2*i){s=i;}else{s=n-2*i;}
            s=i;
            ans=div=power=1;
            for(j=n-i;j>=n-i-s+1;j--)
            {
                ans=ans*j;
            }

            for(j=s;j>=2;j--)
            {
                div=div*j;
            }

            for(j=0;j<n-i;j++)
            {
                power=power*2;
            }
            cnt=cnt+((ans/div)*power)/2;

        }
        printf("%lld\n",cnt%1000000007);
    }
    return 0;
}
