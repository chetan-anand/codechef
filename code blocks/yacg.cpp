#include<stdio.h>
#
#define max 1000004
bool prime[max];

void initsow()
{
    int i,j,k;
    memset(prime,false,sizeof(prime));
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

