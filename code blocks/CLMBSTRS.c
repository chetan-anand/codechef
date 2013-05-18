#include<stdio.h>
/*int dp[1000000]={0};
int fib(int n)
{
    if(n==0){return 0;}
    if(n==1){return 1;}
    if(dp[n]!=0){return dp[n];}
    dp[n]=fib(n-1)+fib(n-2);
    return dp[n];
}*/
int main()
{
    int i,t,n,g,cnt;
    int temp;
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        scanf("%d %d",&n,&g);
        n=n+1;
        //temp=fib(n);
        temp=temp%1000000007;
        while(temp!=0)
        {
            if(temp%2!=0){cnt++;}
            temp=temp>>1;
        }
        if(cnt==g){printf("CORRECT\n");}
        else{printf("INCORRECT\n");}
    }

    return 0;
}
