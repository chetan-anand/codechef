#include<stdio.h>
int main()
{
    long long int t,n,k;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&k);
        if(k==0){printf("0 %lld\n",n);}
        else{printf("%lld %lld\n",n/k,n%k);}
    }
    return 0;
}
