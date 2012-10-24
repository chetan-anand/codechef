#include<stdio.h>
#include<math.h>
int main()
{
    int n,n1,l,lcn,ucn,d,f,k,t,i,j,a[100000],s1,len;
    int flag;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n1);
        for(k=n1;k>=0;k--)
        {
            flag=0;
            s1=0;n=n1;l=0;
            for(i=0;n!=0;i++)
            {
                a[l]=n%10;
                s1=s1+a[l];
                n=n/10;
                l++;
            }
            len=i;
            for(i=0;i<len;i++)
            {
                for(j=i+1;j<len;j++)
                {
                    a[l]=a[i]+a[j];
                    l++;
                }
            }
            for(i=0;i<len;i++)
            {
                for(j=i+1;j<len;j++)
                {
                    for(k=j+1;k<len;j++)
                    {
                        a[l]=a[i]+a[j]+a[k];
                        l++;
                    }
                }
            }
            for(i=0;i<l;i++)
            {
                d=1;f=s1-a[i];
                for(j=0;j<a[i];j++)
                {
                    d=d*f;
                }
                if(d%k==0){flag=1;break;}
            }
            if(flag==1){printf("%d\n",k);break;}
        }

    }
    return 0;
}
