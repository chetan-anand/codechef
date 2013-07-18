#include<stdio.h>
#include<algorithm>
bool min(int i,int j) {return (i<j);}
int main()
{
    int t,n,k,a[11000],i,j,b[11000];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        std::sort(b+1,b+n+1,min);
        for(i=1;i<=n;i++){printf("%d ",b[i]);}
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(b[i]==a[j]){ind=i;}

            }
        }
    }
}
