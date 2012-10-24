#include<stdio.h>
int po(int x)
{
    if(x==0||x==1){return 1;}
    int p=1,i;
    for(i=0;i<x;i++)
    {
        p=p*2;
    }
    return p;
}
int fact(int x)
{
    int i,p=1;
    for(i=x;i>=2;i--)
    {
        p=p*i;
    }
    return p;
}
int main()
{
    int t,n,a,b,i;
    long long int cnt;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);cnt=0;
        for(i=0;i<=n/2;i++)
        {
            a=n-2*i;
            b=i;
            if(b==0)
            {
                cnt=cnt+po(a-1);printf("%lld\n",cnt);
            }
            else
            {
                cnt=cnt+(fact(n-i)/(fact(a-1)*fact(b)))*po(a-1+b);printf("%lld\n",cnt);
                cnt=cnt+(fact(n-i)/(fact(a)*fact(b-1)))*po(a+b-1);printf("%lld\n",cnt);
            }
        }
        printf("%lld\n",cnt);
    }
    //printf("%d %d",fact(1),po(5));
    return 0;
}
