#include <stdio.h>
#include <math.h>

int lastKdigits(int n,int k,int *a)
{
    int i,res=1,div=a[k];
    for(i=1;i<=n;i++)
    {
        res=(res*2)%div;
    }
    return res;
}

int firstKdigits(int n,int k,double temp)
{
    double x, y;
    x = n*temp;
    y = int(pow(10,x-floor(x) +k-1));
    return y;
}

int main()
{
    int a[11]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
    int n,k,t;
    scanf("%d",&t);
    double temp=log10(2);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        printf("%d\n",lastKdigits(n-1,k,a)+firstKdigits(n-1,k,temp));
        //printf("%ld\n",firstKdigits(n-1,k));
    }
}

