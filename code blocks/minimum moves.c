#include<stdio.h>
int main()
{
    int cnt,t,i,j,k,n,s[103],max;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            scanf("%d",&s[i]);
            //printf("%d",s[i]);
        }
        for(j=0;;j++)
        {
            max=-1;
            for(i=0;i<n;i++)
            {
                if(s[i]>max){max=s[i];}
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
