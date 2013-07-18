/////////////////////--------author: Chetan Anand-------\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

#include<stdio.h>
int main()
{
    int t,n,i,j,k,cnt,total,l,temp;
    int x[55],y[55],xa,xb,xc,ya,yb,yc;
    int h,g,r,dis;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&x[i],&y[i]);
        }
        cnt=0;
        for(i=0;i<=n-3;i++)
        {
            for(j=i+1;j<=n-2;j++)
            {
                for(k=j+1;k<=n-1;k++)
                {
                    xa=x[i];xb=x[j];xc=x[k];
                    ya=y[i];yb=y[j];yc=y[k];
                    int ori=xb*yc+xa*yb+ya*xc-(ya*xb+yb*xc+xa*yc);
                    if(ori!=0)
                    {
                        if(ori<0)
                        {
                            xc=x[i];xb=x[j];xa=x[k];
                            yc=y[i];yb=y[j];ya=y[k];
                        }
                        for(l=0;l<n;l++)
                        {
                            if((l==i||l==j)||l==k){continue;}
                            int sx,sy;
                            sx=x[l];sy=y[l];
                            int pos=0;
                            pos=pos+(xb-xa)*((yc-ya)*(sx*sx - xa*xa + sy*sy - ya*ya)-(sy-ya)*(xc*xc - xa*xa + yc*yc - ya*ya));
                            pos=pos-(yb-ya)*((xc-xa)*(sx*sx - xa*xa + sy*sy - ya*ya)-(sx-xa)*(xc*xc - xa*xa + yc*yc - ya*ya));
                            pos=pos+(xb*xb - xa*xa + yb*yb - ya*ya)*((xc-xa)*(sy-ya)-(sx-xa)*(yc-ya));
                            if(pos<=0){cnt++;}
                        }
                    }
                }
            }
        }
        //printf("cnt=%d\n",cnt);
        total=((n*(n-1)*(n-2))/6)*(n-3);
        printf("%.6lf\n",(double)cnt/(double)total);
        //printf("%lf\n",(int)cnt/(int)total);
    }
    return 0;
}

