#include<stdio.h>
#include<string.h>
#include<algorithm>

int main()
{

    int t,flag;
    scanf("%d",&t);
    while(t--)
    {
        flag=0;

        int n,s[100010],a[100010];
        scanf("%d",&n);
        int i,j,k;
        for(i=0;i<n;i++)
        {
            scanf("%d",&s[i]);
        }

        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }

        std::sort(s,s+n);
        std::sort(a,a+n);
        for(i=0;i<n;i++)
        {
            if(s[i]<=a[i]){flag=1;break;}
        }
        if(flag==0){printf("YES\n");}
        else{printf("NO\n");}
    }
    return 0;
}
