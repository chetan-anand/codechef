#include<stdio.h>
int main()
{
    int t,i,j,k,n,m,c,tw,cnt,temp,prev;
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        scanf("%d %d %d",&n,&c,&m);
        tw=n/c;prev=0;cnt=cnt+tw;temp=tw+prev;
        while(temp>=m)
        {
            tw=temp/m;
            cnt=cnt+temp/m;
            prev=temp%m;
            temp=prev+tw;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
