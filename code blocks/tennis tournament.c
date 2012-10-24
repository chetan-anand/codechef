#include<stdio.h>
int n,m,i,a[10005];
double p;
double prob(int x,int y)
{
    if((y-x)==1)
    {
        int flag1,flag2;
        flag1=flag2=0;
        for(i=1;i<=m;i++)
        {
            if(y==a[i]){flag1=1;}
            if(x==a[i]){flag2=1;}
        }
        if(flag1==0 && flag2==0){return 0;}
        if(flag1==1 && flag2==0){return p;}
        if(flag1==0 && flag2==1){return p;}
        if(flag1==1 && flag2==1){return 1;}
    }
    double temp1=prob(1,n/2);
    double temp2=prob((n/2)+1,n);
    return temp1*temp2+(1-temp2)*temp1*p+(1-temp1)*temp2*p;
}

int main()
{
    int t;
    double ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %lf",&n,&m,&p);
        for(i=1;i<=m;i++)
        {
            scanf("%d",&a[i]);
        }
        p=p/100;
        ans=prob(1,n);
        printf("%lf\n",ans*100);
    }
    return 0;
}
