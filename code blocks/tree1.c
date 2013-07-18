#include<stdio.h>
#include<assert.h>
#define mod 1000000007

inline int mul(int a,int b)
{
    return (long long)a*b%mod;
}

int power(int base, long long exp)
{
    int sq=base,res=1;
    for(;exp;exp>>=1)
    {
        if(exp&1)
        {
            res=mul(res,sq);
        }
        sq=mul(sq, sq);
    }
}

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    if(n<2){printf("0\n");}
    else
    {
        printf("%d\n",mul(power(k*n,n-2),power(k*(n-1),n*(k-1))));
    }
    return 0;
}
