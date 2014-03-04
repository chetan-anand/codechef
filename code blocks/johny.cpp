#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#define max(a,b) a>b?a:b

using namespace std;


int main()
{
    int t,i,j,k,n,m;
    int a[202];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        scanf("%d",&k);
        int temp=a[k];
        /*int b=0;
        for(i=1;i<=k;i++)
        {
            if(a[i]==)
        }*/


        sort(a+1,a+n+1);
        for(i=1;i<=n;i++)
        {
            if(a[i]==temp){printf("%d\n",i);break;}
        }

    }


	return 0;
}
