#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#define maxv 100002
#define max(a,b) a>b?a:b
using namespace std;

long long int dp[maxv];
bool pd(long long int n)
{
    long long int temp;
    while(n>0)
    {
        temp=n%10;
        if(temp!=0 &&temp!=1&&temp!=4&&temp!=9)
        {
            return false;
        }
        n=n/10;
    }
    return true;
}

void init()
{
    long long int i;
    dp[0]=1;
    for(i=1;i<=100005;i++)
    {
        if(pd(i*i))
        {dp[i]=dp[i-1]+1;}
        else{dp[i]=dp[i-1];}
    }
    /*for(i=0;i<=100;i++){printf("%lld=%lld ",i,dp[i]);}
    printf("-------------------------------------\n\n\n");*/
}

int main()
{
    long long int t,i,j,a,b,cnt,tempa,tempb;
    memset(dp,0,sizeof(dp));
    init();
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&a,&b);
        //if(a==b){printf("%d\n",pd(a));continue;}
        tempa=(long long int)sqrt(a);
        tempb=(long long int)sqrt(b);
        if(tempa==tempb)
        {
            if(tempa*tempa==a){printf("%d\n",pd(a));}
            else{printf("0\n");}
        }
        else{
        cnt=0;
        if(tempa*tempa!=a){tempa=tempa+1;}
        printf("%lld\n",dp[tempb]-dp[tempa-1]);
        }
    }

	return 0;
}
