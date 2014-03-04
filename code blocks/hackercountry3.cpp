#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 99999999999LL
ll cc[501][501];
ll dp[501][501];

ll gcd(ll a, ll b)
{
        if(!b) return a;
        else return gcd(b, a % b);
}

int main()
{
    ll n;
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            cin >> dp[i][j];
            if(!dp[i][j]) dp[i][j] = inf;
            cc[i][j] = 1;
        }
    }


    for(ll k = 0; k < n; k++) {
        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < n; j++) {
                if(i == j || j == k || k == i) continue;
                if(dp[i][j]*(cc[i][k] + cc[k][j]) > (dp[i][k]+dp[k][j])*cc[i][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                    cc[i][j] = cc[i][k] + cc[k][j];
                }
            }
        }
    }
    ll minval = inf;
    ll mincount = 1;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            if((dp[i][j]+dp[j][i])*mincount < minval*(cc[i][j] + cc[j][i])) {
                //ans = (double)(dp[i][j]+dp[j][i])/(double)(cc[j][i]+cc[i][j]);
                mincount = cc[i][j] + cc[j][i];
                minval = dp[i][j] + dp[j][i];
            }
        }
    }

    ll g = gcd(minval, mincount);

    cout << minval/g << "/" << mincount/g << endl;
}

