#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

#define LL long long
#define LD long double

#define VI vector<int>

#define sd(x) x = GetNextInt()
#define slld(x) scanf("%lld",&x)

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define PII pair<int,int>
#define PPII pair< PI , PI >

#define INF 2000000009

#if 0
#define get getchar_unlocked
#else
#define get getchar
#endif

LL next_int;
char in_char;

inline LL GetNextInt(){
    in_char = ' ';
    while((in_char < '0') || (in_char > '9')){
        in_char = get();
    }
    next_int = 0;
    while((in_char >= '0') && (in_char <= '9')){
        next_int *= 10;
        next_int += in_char - 48;
        in_char = get();
    }
    return next_int;
}

/* Main Code */

#define MAXR 100
#define MAXC 100

int r, c;
bool dp[MAXR][MAXC][MAXR][MAXC], vis[MAXR][MAXC][MAXR][MAXC];
bool demon[MAXR][MAXC];
string s[MAXR];

bool valid(int i, int j){
    if(i < 0 || j < 0 || i >= r || j >= c){
        return false;
    }
    if(s[i][j] == '#'){
        return false;
    }
    return true;
}

inline bool outs(int i, int j){
    if(i < 0 || i >= r || j < 0 || j >= c){
        return true;
    }
    else{
        return false;
    }
}

int op;

int f(int ai, int aj, int bi, int bj){
    if(ai > bi || aj > bj || outs(ai, aj) || outs(bi, bj)){
        return 0;
    }
    if(vis[ai][aj][bi][bj] == true){
        return dp[ai][aj][bi][bj];
    }
    bool g[3] = {false};
    for(int j, c[4], i = ai; i <= bi;i++){
        for(j = aj; j <= bj;j++){
            if(demon[i][j] == true){
                c[0] = f(ai, aj, i - 1, j - 1);
                c[1] = f(ai, j + 1, i - 1, bj);
                c[2] = f(i + 1, aj, bi, j - 1);
                c[3] = f(i + 1, j + 1, bi, bj);
                g[c[0] ^ c[1] ^ c[2] ^ c[3]] = true;
            }
        }
    }
    if(g[0] == false){
        dp[ai][aj][bi][bj] = 0;
    }
    else{
        if(g[1] == false){
            dp[ai][aj][bi][bj] = 1;
        }
        else{
            dp[ai][aj][bi][bj] = 2;
        }
    }
    vis[ai][aj][bi][bj] = true;
    return dp[ai][aj][bi][bj];
}

inline void Solve(){
    cin>>r>>c;
    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++)
            cin>>s[i][j];
        //s[i] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
    }
    for(int j, k, i = 0;i < r;i++){
        for(j = 0;j < c;j++){
            for(k = -2;k <= 2;k++){
                if(valid(i + k, j) == false || valid(i, j + k) == false){
                    break;
                }
            }
            if(k <= 2){
                demon[i][j] = false;
            }
            else{
                demon[i][j] = true;
            }
        }
    }

    memset(vis, false, sizeof(vis));

    if(f(0, 0, r - 1, c - 1) != 0){
        cout<<"Asuna"<<endl;
    }
    else{
        cout<<"Kirito"<<endl;
    }
    return;

    for(int ai = 0;ai < r;ai++){
        for(int aj = 0;aj < r;aj++){
            for(int bi = ai;bi < r;bi++){
                for(int bj = aj;bj < r;bj++){
                    //cout<<ai<<" "<<aj<<" "<<bi<<" "<<bj<<" : "<<f(ai, aj, bi, bj)<<endl;
                }
            }
            system("pause");
        }
    }
    for(int ai = 0;ai < r;ai++){
        for(int aj = 0;aj < r;aj++){
            //cout<<ai<<" "<<aj<<" : "<<demon[ai][aj]<<endl;
        }
    }
}

int main(){
    int t;
    sd(t);
    while(t--){
        Solve();
    }
    return 0;
}


/*

20 20
^^^^^^^^^^^^^^^^^^^^

*/

