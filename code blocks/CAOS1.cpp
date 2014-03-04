#include<stdio.h>

int main()
{
    int i,j,k,r,c,cnt;
    char s[60][60];
    int t;
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        scanf("%d %d",&r,&c);
        for(i=0;i<r;i++)
        {
            scanf("%s",s[i]);
        }

        for(i=0;i<r;i++)
        {
            printf("%s\n",s[i]);
        }

        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(s[i][j]=='#'){continue;}

            }
        }
    }
    return 0;
}
