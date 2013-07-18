#include<stdio.h>
#include<stdlib.h>
#define max(a,b) a>b?a:b
double maxi(double a,double b)
{
    if(a>b){return a;}
    else{return b;}
}

double dp[11000];
double p[1100];
int d[11000],n,l;
double func(int start,int n)
{
    if(start==n){return 1.0;}
    if(dp[start]!=0.0){return dp[start];}
    int i,j;
    double temp=0.0;
    for(i=start+1;d[start]-d[i]<=l;i++)
    {
        temp=max(temp,func(i,n)*p[i]);
        //printf("%f\n",temp);
    }
    dp[n]=temp;
    //printf("temp=%f\n",temp);
    //printf("temp=%f\n",);
    return temp;
}



int main()
{
    int i,tot;
    scanf("%d %d %d",&n,&l,&tot);
    for(i=0;i<11000;i++)
    {
        dp[i]=0.0;
    }
    p[0]=p[n+1]=1.0;
    for(i=1;i<=n;i++)
    {
        scanf("%f",&p[i]);
    }
    d[0]=0;d[n+1]=tot;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&d[i]);
    }

    printf("%.6f\n",func(0,n+1));
    return 0;
}
