#include<stdio.h>


int main()
{
    int t;
    int m,i;
    int a[10005];
    float b[10005];
    long long int n;
    double p;

    double ans;
    double temp1,temp2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %d %lf",&n,&m,&p);
        for(i=1;i<=m;i++)
        {
            scanf("%d",&a[i]);
        }
        num=n;p=p/100;
        while(n!=1)
        {
            i=1;
            for(j=1;j<=num;j+=2*i)
            {
                if(i==1)
                {
                    for(i=1;i<=m;i++)
                    {
                        if(y==a[i]){flag1=1;}
                        if(x==a[i]){flag2=1;}
                    }
                            if(flag1==0 && flag2==0){}
                            if(flag1==1 && flag2==0){return p;}
                            if(flag1==0 && flag2==1){return p;}
                        if(flag1==1 && flag2==1){return 1;}
                    if(j)
                }
            }
        }

        for(i=0)

        ans=prob(1,n);
        printf("%lf\n",ans*100);
    }
    return 0;
}

