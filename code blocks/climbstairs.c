#include<stdio.h>
#define mod 1000000007
int dp[1000003];
int main()
{
    int i,temp,n,g,t,ans;
    dp[0]=0;dp[1]=1;
    for(i=2;i<=1000000;i++)
    {
        dp[i]=((dp[i-1])%mod+(dp[i-2])%mod)%mod;
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&g);
        temp=dp[n+1];ans=0;
        while(temp>0)
        {
            if(temp%2==1){ans++;}
            temp=temp/2;
        }
        if(ans==g){printf("CORRECT\n");}
        else{printf("INCORRECT\n");}
    }

    return 0;
}
