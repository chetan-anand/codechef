#include<stdio.h>
int main()
{
    int t,n,a[10100],i,j,k,minv,maxv,temp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);minv=2000;maxv=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]>maxv){maxv=a[i];}
            if(a[i]<minv){minv=a[i];}
        }
        if((maxv-minv)>5)
        {
            for(i=0;i<n;i++)
            {

            }
        }
    }
    return 0;
}
