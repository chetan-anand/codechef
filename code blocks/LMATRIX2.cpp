#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <algorithm>
#include <map>
#include <climits>
#include <string>
#include <cstring>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<ULL> VULL;
typedef vector<LL> VLL;

#define MX 0
#define MN 1001
#define SZ LINE_MAX
#define REP(i, s, e) for(int i = (s); i <= (e); ++i)
#define FOR(i, s, n) for(int i = (s); i < (n); ++i)
#define FORALL(i, n) for(int i = 0; i < (n); ++i)
#define pushb push_back
#define MOD 1000000007
#define UNTOUCHED 0
#define COLORED 1
#define STARTCOLOR 2
#define RECOLOR 3

struct node {
	int v, c;
	int i, j;
};

int g[101][101], g1[101][101];
struct node h[101][101], h1[101][101];

int main() {
	int n, m, count = 0, count1 = 0;
	cin >> n >> m;
	int num, a[n+1][m+1], p[n+1][m+1];
	FOR(i, 1, n+1) FOR(j, 1, m+1) {
		cin >> p[i][j];
	}
	FOR(i, 1, n+1) FOR(j, 1, m+1) {
		cin >> a[i][j];
	}
	FOR(i, 1, n+1) FOR(j, 1, m+1) {
		if (a[i][j]) g[i][j] = p[i][j] - a[i][j], g1[i][j] = p[i][j] - a[i][j];
		else g[i][j] = 0, g1[i][j] = 0;
		h[i][j].v = h1[i][j].v = UNTOUCHED;
	}
	FOR(i, 1, n+1) {
		FOR(j, 1, m+1) {
			h[i][j].c = g[i][j];
			if (!g[i][j]) continue;
			int maxj = 0, maxi = 0, c = g[i][j];
			int l, k;
			for(k = i; k <= n; k++) {
				if (g[k][j] != c) break;
				for(l = j; l <= m && (g[k][l] == c); l++);
				maxj = max(maxj, l-1);
			}
			for(l = j; l <= maxj; l++) {
				for(k = i; k <= n && (g[k][l] == c); k++);
				maxi = max(maxi, k-1);
			}
			FOR(k, i, maxi+1) FOR(l, j, maxj+1) {
				a[k][l] = (a[k][l]+c)%p[k][l];
				g[k][l] = p[k][l]-a[k][l];
				if (!a[k][l]) g[k][l] = 0;
				else {
					g[k][l] = p[k][l]-a[k][l];
				}
			}
			h[i][j].i = maxi;
			h[i][j].j = maxj;
			h[i][j].v = STARTCOLOR;
			count++;
		}
	}
	FOR(i, 1, n+1) {
		FOR(j, 1, m+1) {
			h1[i][j].c = g1[i][j];
			if (!g1[i][j] || h1[i][j].v) continue;
			int minj = m+1, mini = n+1, c = g1[i][j];
			int l, k;
			for(k = i; k <= n; k++) {
				if (g1[k][j] != c) break;
				for(l = j; l <= m && abs(g1[k][l]-c)%p[k][l] == 0 && !h1[k][l].v; l++);
				if (l > j) minj = min(minj, l-1);
			}
			for(l = j; l <= minj; l++) {
				for(k = i; k <= n && abs(g1[k][l]-c)%p[k][l] == 0 && !h1[k][l].v; k++);
				if (k > i) mini = min(mini, k-1);
			}
			FOR(k, i, mini+1) FOR(l, j, minj+1) {
				h1[k][l].v = COLORED;
			}
			h1[i][j].i = mini;
			h1[i][j].j = minj;
			h1[i][j].v = STARTCOLOR;
			count1++;
		}
	}
	if (count < count1) {
		cout << count << endl;
		FOR(i, 1, n+1) FOR(j, 1, m+1) if (h[i][j].v == STARTCOLOR) cout << i << " " << j << " " << h[i][j].i << " " << h[i][j].j << " " << h[i][j].c << endl;
	}
	else {
		cout << count1 << endl;
		FOR(i, 1, n+1) FOR(j, 1, m+1) if (h1[i][j].v == STARTCOLOR) cout << i << " " << j << " " << h1[i][j].i << " " << h1[i][j].j << " " << h1[i][j].c << endl;
	}
	return 0;
}
