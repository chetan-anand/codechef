#include<stdio.h>
#include<algorithm>
int main()
{
    int t,n,a[100000],i,j,k,minv,maxv,teamv;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        std::sort(a,a+n);
        /*for(i=0;i<n;i++)
        {
            printf("%d\n",a[i]);
        }*/
        teamv=a[0]+a[n-1];
        maxv=teamv;
        minv=teamv;
        for(i=1;i<n/2;i++)
        {
            teamv=a[i]+a[n-1-i];
            if(teamv>maxv){maxv=teamv;}
            if(teamv<minv){minv=teamv;}
        }
        /*printf("%d\n",maxv);
        printf("%d\n",minv);*/
        printf("%d\n",maxv-minv);
    }
    return 0;
}
