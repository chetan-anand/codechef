#include<stdio.h>
int main()
{
   /* int n,q,k,i,j,cnt;int s[100003],t[100003],a[5003];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&s[i],&t[i]);
    }
    scanf("%d",&q);
    while(q--)
    {
        cnt=0;
        for(i=0;i<=a[0];i++)
        {
            scanf("%d",&a[i]);
        }
        /*for(i=0;i<=a[0];i++)
        {
            if(a[i]==0){continue;}
            for(j=i+1;j<=a[0];j++)
            {
                if(a[j]==a[i]){a[j]=0;}
            }
        }
        for(i=0;i<=a[0];i++)
        {
            printf("%d\n",a[i]);
        }*/
        for(i=1;i<=a[0];i++)
        {
            for(j=i-1;j>=1;j--)
            {
                if(a[i]==a[j]){goto A;}
            }
            for(k=0;k<n;k++)
            {
                if(a[i]>=s[k]&&a[i]<t[k]){cnt++;}
            }
            A:{}
        }
        printf("%d\n",cnt);
    }
    return 0;
}
