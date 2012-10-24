#include<stdio.h>
int j;
int po(int x)
{
    int y=1;
    for(j=0;j<x;j++)
    {
        y=y*5;
    }
    return y;
}
void main()
{
    int n,i,t,cnt;
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        scanf("%d",&n);
        for(i=1;n/po(i)!=0;i++)
        {
            cnt=cnt+n/po(i);
        }
        printf("%d\n",cnt);
    }
}
