#include<stdio.h>

int rev(int x)
{
    int i;
    int ans=0,j;
    for(i=0;x%10==0;i++)
    {
            x=x/10;
    }
    for(i=0;x!=0;i++)
    {
        j=x%10;
        ans=10*ans+j;
        x=x/10;
    }
    return ans;
}
int main()
{
    int i;
    int t,p,q,r;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d %d",&p,&q);
        p=rev(p);
        q=rev(q);
        r=p+q;
        r=rev(r);
        printf("%d\n",r);
    }
    getch();
    return 0;
}
