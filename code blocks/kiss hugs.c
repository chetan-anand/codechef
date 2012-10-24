#include<stdio.h>
int modpow(int b,int e)
{
    int result,mod;
    mod=1000000007;
    result=1;
    while(e>0)
    {
        if(e%2==1)
        {
            result=(result*b)%mod;
        }
        e=e>>1;
        b=(b*b)%mod;
        return result;
    }

}
int main()
{
    int t,n,i;
    int temp,cnt;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n%2==0)
        {
            temp=modpow(2,(n/2)-1);
            cnt=3*temp-2;
        }
        else
        {
            temp=modpow(2,((n+3)/2)-1);
            cnt=temp-2;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
