#include<stdio.h>
int main()
{
    int t,n,i,j,k,l,flag1,b,s,flag2,flag3;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        for(j=2;;j++)
        {
            flag1=flag2=flag3=0;
                for(k=2;j/(k*k)!=0;k++)
                {
                    if(j%(k*k)==0){flag1=1;break;}
                }
                if(flag1==0)
                {
                for(k=2;k<=j/2;k++)
                    {
                        if(j%k==0){flag2=1;break;}
                    }
                }
                if(flag1==0 && flag2==1)
                {
                    for(k=2;k<=n;k++)
                    {
                        for(l=1;;l++)
                        {
                        if(j>k){b=j;s=k;}else{b=k;s=j;}
                        if((b*l)%s==0){break;}
                        }
                        if((j*k)/(b*l)!=1){flag3=1;break;}
                    }
                }
            if(flag1==0 && flag2==1 && flag3==0){break;}
        }
        printf("%d\n",j);
    }
    return 0;
}
