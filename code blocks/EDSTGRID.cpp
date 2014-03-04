#include<stdio.h>
#include<math.h>

int main()
{
int t,n,m,c2,c3,i,j;
long long cnt,cnt1;
scanf("%d",&t);
while(t--)
{
    cnt=0;
    scanf("%d %d %d %d\n",&n,&m,&c2,&c3);
    char arr[n][m+1];
    for(i=0;i<n;i++)
    {
        fflush(stdin);
        gets(arr[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        if(arr[i][j]=='B')
        cnt++;
    }
    printf("%d\n",cnt);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        if(arr[i][j]=='B')
        printf("%d %d %d\n",3,i+1,j+1);
    }

}
return 0;
}
