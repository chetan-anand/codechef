#include<stdio.h>
int main()
{
    double x,y,z,cen[3][50000],temp;
    int n,q,ans,i,j;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    scanf("%lf %lf %lf",&cen[0][i],&cen[1][i],&cen[2][i]);
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%lf %lf %lf",&x,&y,&z);
        if(i>200){printf("%d\n",n-1);continue;}
            double dist = (x-cen[0][0])*(x-cen[0][0])+(y-cen[1][0])*(y-cen[1][0])+(z-cen[2][0])*(z-cen[2][0]);
            ans=0;
            for(j=1;j<n;j++)
            {
                temp = (x-cen[0][j])*(x-cen[0][j])+(y-cen[1][j])*(y-cen[1][j])+(z-cen[2][j])*(z-cen[2][j]);
                if(dist>temp)
                {
                     ans=j;
                    dist = temp;
                }
                if(dist==1)
                break;
            }
        printf("%d\n",ans);
    }
    return 0;
}
