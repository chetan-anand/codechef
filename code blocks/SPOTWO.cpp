#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<string.h>
#define mod 1000000007
using namespace std;
/*inline void fastRead_int(long long int &x) {
    register long long int c = getchar_unlocked();
    x = 0;
    long long int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if(c=='-') {
    	neg = 1;
    	c = getchar_unlocked();
    }

    for(; c>47 && c<58 ; c = getchar_unlocked()) {
    	x = (x<<1) + (x<<3) + c - 48;
    }

    if(neg)
    	x = -x;
}*/

unsigned long long b[30];
unsigned long long power(unsigned long long n)
{
    if(n==0){return 1;}
    if(n==1){return 2;}
    unsigned long long temp;
    if(n%2==0)
    {
        temp=(power(n/2))%mod;
        return (temp*temp)%mod;
    }
    else
    {
        temp=(power(n/2))%mod;
        temp=(temp*temp)%mod;
        return (temp*2)%mod;
    }

}

unsigned long long con(unsigned long long n)
{
    unsigned long long i,temp;
    i=0;
    while(n!=0)
    {
        b[i]=n%2;
        n=n/2;
        i++;
    }
    temp=0;
    for(int j=i-1;j>=0;j--)
    {
        temp=10*temp+b[j];
    }
    //printf("temp=%lld\n",temp);
    return temp;
}

int main()
{

    unsigned long long i,j,k,t,ans,n;
    scanf("%llu",&t);
    //fastRead_int(t);
    //printf("t=%lld\n",t);
    while(t--)
    {
        scanf("%llu",&n);
        //fastRead_int(n);
        //printf("n=%lld\n",n);
        //printf("power=%lld\n",power(n));
        ans=(power(con(n)))%mod;
        ans=(ans*ans)%mod;
        printf("%llu\n",ans);
    }
    return 0;
}
