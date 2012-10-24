#include<stdio.h>
int main()
{
    int t,i,j,temp,n,a[5001],s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        temp=a[0]-a[1];
        if(temp<0){temp=temp*-1;}
        s=temp;
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                temp=a[i]-a[j];
                if(temp<0){temp=temp*-1;}
                if(s>temp){s=temp;}
            }
        }
        printf("%d\n",s);
    }
    return 0;
}
