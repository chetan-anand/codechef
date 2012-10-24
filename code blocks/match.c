#include<stdio.h>
int main()
{
    int t,i,j,a[1001],b[1001],n,cnt;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);cnt=0;
        scanf("%d %d",&a[0],&b[0]);
        for(i=1;i<n;i++)
        {
            scanf("%d %d",&a[i],&b[i]);
            for(j=0;j<i;j++)
            {
                if((a[i]<a[j])&&(b[i]>b[j])){cnt++;}
                else if((a[i]>a[j])&&(b[i]<b[j])){cnt++;}
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
