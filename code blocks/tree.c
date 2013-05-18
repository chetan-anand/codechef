#include<stdio.h>
#define mod 1000000007
long long int power(int b,int e)
{
    if(e<0){return 0;}
    if(e==1){return b;}
    if(e==0){return 1;}
    if(e%2==0)
    {
        long long int temp=(power(b,e/2))%mod;
        return temp*temp;
    }
    else
    {
        long long int temp=(power(b,e/2))%mod;
        return temp*temp*b;
    }
}

int main()
{
    int n,k,ans;
    //ans=power(100,100);
    scanf("%d %d",&n,&k);
    ans=power(k*n,n-2);
    ans=ans*power(k*(n-1),(k-1)*n);
    printf("%d\n",ans%mod);
    return 0;
}
