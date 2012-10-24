#include<stdio.h>
long long int power2(int x)
{
    return 2<<(x-1);
}
int main()
{
    int n=32;
    printf("The value of n before bit shifting is %d\n",n);
    n=n>>4;
    printf("The value of n after bit shifting is %d\n",n);
    long long int ans;
    ans=power2(30);
    printf("the value of power 10 is %lld\n",ans);
    int Result = (50<< 16 ) | 60;
    printf("%d\n",Result);
    return 0;
}
