#include<stdio.h>
#include<string.h>
#include<algorithm>
int main()
{
    int i,j,k;
    int n,a[60];
    for(j=1;;j++)
    {scanf("%d",&n);
    if(n==0){break;}
    int cnt=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        cnt=cnt+a[i];
    }
    cnt=cnt/n;
    std::sort(a,a+n);
    int ans=0;
    for(i=0;;i++)
    {
        if(a[i]<cnt){ans=ans+cnt-a[i];}
        else{break;}
    }
    printf("Set #%d\n",j);
    printf("The minimum number of moves is %d.\n",ans);
    }
    return 0;
}
