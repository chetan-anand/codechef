#include<stdio.h>
double a[1000000],b[1000000];
int c[1000000];
int main()
{
    int n,d,i,j,k=0,temp=0,flag;
    double slope,cons,diff;
    scanf("%d %d",&n,&d);
    for(i=0;i<n;i++)
    {
        scanf("%lf %lf",&a[i],&b[i]);
    }
    c[k]=temp;
    while(temp!=n-1)
    {
        for(i=n-1;i>=temp+1;i--)
        {
            flag=0;
            slope=((b[i]-b[temp])/(a[i]-a[temp]));//printf("%lf\n",slope);
            cons=(b[i]-slope*a[i]);//printf("%lf\n",cons);
            for(j=temp+1;j<i;j++)
            {
                diff=b[j]-slope*a[j]-cons;
                if(diff<0){diff=diff*-1;}
                if(diff>=3){flag=1;break;}
            }
            if(flag==0){break;}
        }
        temp=i;
        c[++k]=temp;
    }
    printf("%d\n",k);
    for(i=0;i<k+1;i++)
    {
        printf("%d %d\n",(int)a[c[i]],(int)b[c[i]]);
    }
    return 0;
}
