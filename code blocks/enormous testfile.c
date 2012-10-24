#include<stdio.h>
int main()
{
    int n,k,i,cnt=0;
    scanf("%d %d",&n,&k);
    while(n--)
    {
        scanf("%d",&i);
        if(i==0){continue;}
        if(i%k==0){cnt++;}
    }
    printf("%d\n",cnt);
    return 0;
}
