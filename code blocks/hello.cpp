#include<stdio.h>
int main()
{
    int i,t,mini,u,n,m,c;
    double cost,minv,d,r;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf %d %d",&d,&u,&n);
        minv = d*(double)u;mini=0;
        //printf("%lf\n",minv);
        for(i=1;i<=n;i++)
        {
            scanf("%d %lf %d",&m,&r,&c);
            cost=((double)c/(double)m)+r*(double)u;
            //printf("%lf\n",cost);
            if(cost<minv){minv=cost;mini=i;}
        }
        printf("%d\n",mini);

    }
    return 0;
}

