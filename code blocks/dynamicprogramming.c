#include<stdio.h>
#define max(a,b) a>b?a:b
int a[10]={1,5,8,9,10,17,17,20,24,30};
int cnt=0;
int res[100000];

int maxrev(int n)
{

    int ans;
    if(n==0)
    {
        return 0;
    }
    //if(res[n-1]!=0){return res[n-1];}
    int i;
    ans=a[n-1];
    for(i=1;i<n-2;i++)
    {
        ans=max(ans,maxrev(i)+maxrev(n-i));
    }
    printf("%d\n",ans);
    //res[n-1]=ans;
    return ans;
}
int main()
{
    int i,j,k,ans;
    /*for(i=0;i<100000;i++)
    {
        res[i]=0;
    }*/
        /*for(i=0;i<10;i++)
    {
        printf("%d\n",a[i]);
    }*/
    //printf("%d\n",max(2,3));
    ans=maxrev(10);
    printf("The maximum revenue you get is %d\n",ans);
    return 0;
}
