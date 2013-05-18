#include<stdio.h>
#define max(a,b) a>b?a:b
int bottomcutrod(int *p,int n)
{
    int r[n],i,j,ans;
    r[0]=0;r[1]=1;
    for(i=1;i<=n;i++)
    {
        ans=-1;
        for(j=1;j<=i;j++)
        {
            ans=max(ans,p[j]+r[i-j]);
        }
        r[i]=ans;
        printf("index=%d   value=%d\n",i,r[i]);
    }

    return r[n];
}

int main()
{
    int p[11]={0,1,5,8,9,10,17,17,20,24,30},ans;
    ans=bottomcutrod(p,10);
    printf("the maximum revenue from rod cutting is %d\n",ans);
    return 0;
}
