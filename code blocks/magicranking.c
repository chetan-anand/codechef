#include<stdio.h>
int main()
{
    int i,j,k,n,t,cnt;
    int m[102][102];
    float f;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&m[i][j]);
            }
        }

        /*for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("%d\n",m[i][j]);
            }
        }*/
        cnt=0;
        for(i=0,j=0;;)
        {
            if(i==(n-1))
            {
                for(j=j+1;j<n;j++)
                {
                    cnt=cnt+m[i][j];
                }
                break;
            }

            if(j==(n-1))
            {
                for(i=i+1;i<n;i++)
                {
                    cnt=cnt+m[i][j];
                }
                break;
            }

            if(m[i][j+1]>m[i+1][j]){j++;}
            else{i++;}
            cnt=cnt+m[i][j];
        }
        /*printf("cnt=%d\n",cnt);
        printf("n=%d\n",n);*/
        if(cnt<0){printf("Bad Judges\n");}
        else
        {
            f=(float)cnt/(float)(2*n-3);
            printf("%.7f\n",f);
        }

    }
    return 0;
}
