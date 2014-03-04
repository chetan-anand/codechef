#include<stdio.h>
#include<string.h>
#include<math.h>

#define max 100
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
int main()
{
    int i,j,k;
    initsow();
    //memset(prime,1,sizeof(prime));
    for(i=1;i<=100;i++)
    {
        printf("%d=%d\n",i,prime[i]);
    }

    return 0;
}

