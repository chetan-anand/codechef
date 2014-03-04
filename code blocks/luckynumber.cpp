#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
#define max 118099

bool prime[max];
int arr[]
void initsow()
{
    int i,j,k;
    memset(prime,0,sizeof(prime));
    for(i=2;i<=sqrt(max);i++)
    {
        if(!(prime[i]))
        {
            for(j=2*i;j<=max;j+=i)
            {
                if(!prime[j]){prime[j]=true;}

            }
        }
    }
}


int main()
{
    int i,j,k;
    long long int a,b;
    int t;
    initsow();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&a,&b);
        printf()
    }

	return 0;
}
