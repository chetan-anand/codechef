#include<stdio.h>
#include<algorithm>
int main()
{
    int m,i,j,k,n,b[110000],ans[110000],flag;
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
    }
    std::sort(b,b+m);
    /*for(i=0;i<m;i++)
    {
        printf("%d\n",b[i]);
    }*/
    int start,mid,cnt=0;
    for(j=1;j<=m-2;j++)
    {
        flag=0;
        for(k=j+1;k<=m-1;k++)
        {
            if((2*b[j]-b[0])!=b[k])
            {
                ans[cnt]=b[0];cnt++;start=j;ans[cnt]=b[j];cnt++;mid=k;ans[cnt]=b[k];cnt++;flag=1;break;
            }
        }
        if(flag==1){break;}
    }

    while(1)
    {
        flag=0;
        for(k=mid+1;k<=m-1;k++)
        {
            for(j=0;j<k;j++)
            {
                b[j]+
            }
        }
        if(flag==0){break;}
    }

    printf("%d\n",cnt);
    for(i=0;i<cnt;i++)
    {
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}
