#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<string.h>
#define MAX(a,b) a>b?a:b
#define max 1000004

using namespace std;


bool isPrime[max];

void initsow()
{
    long long int i,j,k;
    memset(isPrime,false,sizeof(isPrime));
    for(i=2;i<=sqrt(max);i++)
    {
        if(!(isPrime[i]))
        {
            for(j=2*i;j<=max;j+=i)
            {
                if(!isPrime[j]){isPrime[j]=true;}

            }
        }
    }
    for(i=1;i<=20;i++){printf("%lld=%d\n",i,isPrime[i]);}
}



int main()
{
    long long int t,i,j,k,n,m,l,r;
    scanf("%lld",&t);
    initsow();
    while(t--)
    {
        scanf("%lld %lld",&l,&r);
        for(i=l;i<=r;i++)
        {

        }
    }

	return 0;
}
