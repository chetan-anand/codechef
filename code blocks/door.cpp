#include<stdio.h>
int main()
{
    int t,i,j,d,cnt1,cnt2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&d);
        cnt1=0;
        for(i=1;i<=d;i++)
        {
            cnt2=0;
            for(j=1;j<=i;j++)
            {
                if((i%j)==0)
                {cnt2++;}
            }
            if((cnt2%2)!=0){cnt1++;}
        }
        printf("%d\n",cnt1);
    }
    return 0;
}
