#include<stdio.h>
long long int power(int n)
{
    long long int temp;
    if(n==1){return 3;}
    if(n%2==0)
    {
        temp=power(n/2);
        return (temp*temp)%1000000007;
    }
    else
    {
        temp=power(n/2);
        return (temp*temp*3)%1000000007;
    }
}
int main()
{
    int t,i,j,k,n;
    long long int ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ans=power(n);
        if(n%2==0){ans=ans+3;}else{ans=ans-3;}
        printf("%lld\n",ans%1000000007);
    }
    return 0;
}
