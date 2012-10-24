#include<stdio.h>
int a[500][500];
int b[500][500];
int getMax(int i, int j,int M,int N)
{
	if( (i<M) && (j<N) )
	{
		if( b[i][j] != 0 )
			return b[i][j];
		else
		{
			int right = getMax(i, j+1,M,N);
			int down = getMax(i+1, j,M,N);

			b[i][j] = ( (right>down) ? right : down )+a[i][j];
			return b[i][j];
		}
	}
	else
		return 0;
}
int main()
{
    int m,n,i,j,cnt;char ch;
    scanf("%d%c%d",&m,&ch,&n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            //printf("|- ");
            scanf("%d%c",&a[i][j],&ch);
        }
        //printf("\n");
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]<0){continue;}
            else
            {
                cnt=0;
                if(i-1>=0&&j-1>=0){if(a[i-1][j-1]<0){cnt=cnt-a[i-1][j-1];}}
                if(j-1>=0){if(a[i][j-1]<0){cnt=cnt-a[i][j-1];}}
                if(i+1<=m-1 && j-1>=0){if(a[i+1][j-1]<0){cnt=cnt-a[i+1][j-1];}}
                if(i+1<=m-1){if(a[i+1][j]<0){cnt=cnt-a[i+1][j];}}
                if(i+1<=m-1 && j+1<=n-1){if(a[i+1][j+1]<0){cnt=cnt-a[i+1][j+1];}}
                if(j+1<=n-1){if(a[i][j+1]<0){cnt=cnt-a[i][j+1];}}
                if(i-1>=0 && j+1<=n-1){if(a[i-1][j+1]<0){cnt=cnt-a[i-1][j+1];}}
                if(i-1>=0){if(a[i-1][j]<0){cnt=cnt-a[i-1][j];}}
                if((a[i][j]-cnt)<0){a[i][j]=0;}
                else{a[i][j]=a[i][j]-cnt;}
            }
        }
    }
    printf("\n\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("%d\n",getMax(0,0,m,n));

    return 0;
}
