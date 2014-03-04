#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#define max(a,b) a>b?a:b
#define mod 1000000007

using namespace std;

long long int power(long long int n)
{
    if(n==0){return 1;}
    if(n==1){return 2;}
    if(n%2==0)
    {
        long long int temp=(power(n/2))%mod;
        return (((temp)%mod)*((temp)%mod))%mod;
    }
    else
    {
        long long int temp=(power(n/2))%mod;
        temp=(((temp)%mod)*((temp)%mod))%mod;
        return (temp*2)%mod;
    }
}

int main()
{
    long long int t,i,j,k,n,m;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        long long int ans=power(n);
        printf("%lld\n",ans-1);
    }

	return 0;
}
