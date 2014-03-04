#include<stdio.h>
#include<string.h>
using namespace std;
bool ispal[5001][5001];
bool ispal(int i,int j,char *s)
{
    if(i)
    if(s[i]==s[j] && ispal(i+l,j-1))
    {
        ispal[i][j]=true;
    }
    return ispal[i][j];
}
int dp[5003];

int solve(int x,char* s)
{
    if()
    dp[x]=min(solve(x))
}

int main()
{
    int t,i,j,k,n,l,r,i;
    char s[6000];
    scanf("%d",&t);
    while(t--)
    {
        memset(ispal,false,sizeof(ispal));
        memset(dp,false,sizeof(dp));
        scanf("%d",&n);
        scanf("%s",s);
        ///precomputation of ispal
        for(i=0;i<n;i++)
        {
            l=r=i;
            while(l>=0 && r<n && s[l]==s[r])
            {
                pal[l][r]=true;
                l--;
                r++;
            }
            l=i-1;
            r=i;
            while(l>=0 && r<n && s[l]==s[r])
            {
                ispal[l][r]=true;
                l--;
                r++;
            }
        }

        dp[0]=1;
        for(i=0;i<n;i++)
        {
            if(ispal[0][i]==true){dp[0][i]=true;}
        }
        printf("%d\n",solve(n-1,s));

        //puts(s);

    }
    return 0;
}
