#include<stdio.h>
#define mod 1000000007;

int main()
{
    int i,j,k,t,n,g,cnt;
    static int dp[1000006];
    int ans;
    dp[0]=0;dp[1]=1;
    for(i=2;i<=1000001;i++)
    {
        dp[i]=(dp[i-1]+dp[i-2])%mod;
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&g);
        ans=dp[n+1];
        cnt=0;
        printf("%d\n",ans);
        while(ans>0)
        {
            if(ans%2==1)
            {
                cnt++;
            }
            ans=ans/1;
        }
        if(cnt==g){printf("CORRECT\n");}
        else{printf("INCORRECT\n");}
    }
}
