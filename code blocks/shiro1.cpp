#include<stdio.h>
void shiro(int a[],double p[],int sum,int length,int i,double probab);
double final_probab;
int main()
{
    int t,a[100];
     double p[100];
    scanf("%d",&t);
    while(t--)
    {
        final_probab=0;
        int n,i;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++)
            scanf("%lf",&p[i]);
            shiro(a,p,0,n,0,1);
         printf("%lf\n",final_probab);
    }
    return 0;
}
void shiro(int a[], double p[],int sum,int length,int i,double probab)
{
    if(sum>=0&&i==length)
    {
        final_probab+=probab;
    }
    if(i==length)
        return;
        double probab1,probab2;
    probab1=probab*(p[i]/100);
    probab2=probab*((100-p[i])/100);
    i=i+1;
    shiro(a,p,sum+a[i-1],length,i,probab1);
    shiro(a,p,sum-a[i-1],length,i,probab2);
}
