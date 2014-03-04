#include<stdio.h>
#define mod 1000000007

long long int power(long long int a,long long int b)
{
    if(a==0){return 0;}
    if(b==0){return 1;}
    if(b==1){return a;}
    long long int foo;
    if(b%2==0)
    {
        foo=(power(a,b/2))%mod;
        return ((foo%mod)*(foo%mod))%mod;
    }
    else
    {
        foo=power(a,b/2);
        foo=((foo%mod)*(foo%mod))%mod;
        return ((foo%mod)*(a%mod))%mod;
    }
}

int main()
{
    long long int i,j,k,n,m,q,t;
    scanf("%lld",&t);
    while(t--)
    {
        long long int ans,temp;
        scanf("%lld %lld %lld %lld",&n,&m,&q,&k);
        if(n==1 || m==1){printf("0\n");continue;}
        //printf("%lld\n",power(4,4));
        ans = ( power(q+1,n)%mod + power(q-1,n)%mod ) %mod;
        //printf("%lld\n",ans);
        ans = (ans - (2*power(q,n))%mod +mod)%mod;
        //printf("%lld\n",ans);
        if(m<=q){printf("0\n");continue;}
        temp=(m%mod - q%mod + mod)%mod;
        //printf("%lld\n",temp);
        ans= ((ans%mod)*(temp%mod))%mod;
        printf("%lld\n",ans);


        /*(   (((power(q+1,n)%mod)+(power(q-1,n)%mod))%mod)-(2*power(q,n))%mod + mod)%mod;
        ans=((ans%mod)*(((m%mod)-(q%mod)+mod)%mod))%mod;*/

    }
    return 0;
}
