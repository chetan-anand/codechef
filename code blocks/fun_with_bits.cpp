#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i,j,k,dp[100][100],mask,t,m,n;
    memset( dp, 0, sizeof(dp) );
    dp[0][0] = 1;
    for (i = 0; i < n; i++ )
    {
        for (mask = 0; mask < (1 << m); mask++ )
        {
            dp[i+1][mask] += dp[i][mask];
            for(t = 0; t < m; t++)
                if ( (mask >> t) & 1 == 0 && valid[i][t] )
                    dp[i+1][mask | (1 << t)] += dp[i][mask];
        }
    }
    long long ans = 0;
    for (mask = 0; mask < (1 << m); mask++ )
        if ( __builtin_popcount(mask) == k )
            ans += dp[n][mask];
}
