#include<stdio.h>
#include<algorithm>

//bool func(int i,int j){return (i<j);}

int main()
{
    int m,i,j,k,n,b[100100],mid,first,cnt,ch[100100],flag;
    scanf("%d",&m);
    for(i=0;i<m;++i)
    {
        scanf("%d",&b[i]);
    }
    std::sort(b,b+m);
    for(i=0;i<m;++i)
    {
        printf("%d\n",b[i]);
    }
    cnt=0;first=0;mid=1;
    for(i=first;i<=m-1;)
    {
        for(j=i+1;j<=m-1;j++)
        {
            flag=0;
            for(k=j+1;k<=m-1;k++)
            {
                if((2*b[j]-b[i])!=b[k]){ch[cnt]=first;cnt++;ch[cnt]=j;cnt++;first=k;flag=1;break;}
            }
            if(flag==1){break;}
        }
    }
    return 0;
}
