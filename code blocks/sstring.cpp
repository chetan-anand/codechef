#include<stdio.h> #include<string.h> const
int MAX = 110, MOD = 1009; int dp[MAX][27], len, sstrings[MAX]; char str[MAX];   int solve(int i, int prev) {         if (i == len)      
          return dp[i][prev] = 1;
        if (dp[i][prev] == -1)
{            
    dp[i][prev] = 0;
                for (int c = 'a'; c < (int)str[i];
c++)    
                   
if (c-'a' != prev)              
                  dp[i][prev] = (dp[i][prev] + sstrings[len-i-1])
% MOD;    
            if
(prev != str[i]-'a')      
                  dp[i][prev] = (dp[i][prev] + solve(i+1, str[i]-'a')) %
MOD;         }         return dp[i][prev]; }
int main() {      
  scanf("%s", str);         len = strlen(str);         sstrings[0]
= 1;         for (int i = 1; i <= len; i++)  //
sstrings[i] = 25^i % MOD            
    sstrings[i] = (sstrings[i-1]
* 25) % MOD;         memset(dp, -1, sizeof dp);      // -1 meaning
not calculated yet         printf("%d\n", solve(0, 26));   //
26 is a non-existing letter before the start      
  return 0; }
