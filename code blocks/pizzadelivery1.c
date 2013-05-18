#include<stdio.h>
#include<limits.h>
#define min(a,b) a<b?a:b
int main()
{
    int i,j,n,t,maxh,ans;
    int h[502],x[502],dp[600];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&h[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&x[i]);
        }
        dp[0]=0;
        maxh=-1;
        for(i=0;i<n;i++)
        {
            if(h[i]>maxh){maxh=h[i];}
        }
        for(i=0;i<2*maxh+1;i++)
        {
            dp[i]=INT_MAX;
        }

        for(i=0;i<n;i++)
        {
            for(j=x[i];j<2*maxh;j++)
            {
                dp[j]=min(dp[j],1+dp[j-x[i]]);
            }
        }
        int ans=0;
        for(i=0;i<n;i++)
        {
            ans=ans+dp[2*h[i]];
        }
        printf("%d\n",ans);
        printf("%d\n",ans);

    }
    return 0;
}
