#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

const int MAXN = 10010000;
const int MAXM = 10000100;
const int INF = 0x3f3f3f3f;

struct Edge
{
	int v;
	int next;
}edge[MAXM];

int nx, ny, p;
int cnt;
int t;
int dis;

int first[MAXN];
int xlink[MAXN], ylink[MAXN];
int dx[MAXN], dy[MAXN];
int vis[MAXN];

void init()
{
	cnt = 0;
	memset(first, -1, sizeof(first));
	memset(xlink, -1, sizeof(xlink));
	memset(ylink, -1, sizeof(ylink));
}

void read_graph(int u, int v)
{
	edge[cnt].v = v;
	edge[cnt].next = first[u], first[u] = cnt++;
}

int bfs()
{
	queue<int> q;
	dis = INF;
	memset(dx, -1, sizeof(dx));
	memset(dy, -1, sizeof(dy));
	for(int i = 1; i <= nx; i++)
	{
		if(xlink[i] == -1)
		{
			q.push(i);
			dx[i] = 0;
		}
	}
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		if(dx[u] > dis) break;
		for(int e = first[u]; e != -1; e = edge[e].next)
		{
			int v = edge[e].v;
			if(dy[v] == -1)
			{
				dy[v] = dx[u] + 1;
				if(ylink[v] == -1) dis = dy[v];
				else
				{
					dx[ylink[v]] = dy[v]+1;
					q.push(ylink[v]);
				}
			}
		}
	}
	return dis != INF;
}

int find(int u)
{
	for(int e = first[u]; e != -1; e = edge[e].next)
	{
		int v = edge[e].v;
		if(!vis[v] && dy[v] == dx[u]+1)
		{
			vis[v] = 1;
			if(ylink[v] != -1 && dy[v] == dis) continue;
			if(ylink[v] == -1 || find(ylink[v]))
			{
				xlink[u] = v, ylink[v] = u;
				return 1;
			}
		}
	}
	return 0;
}

int MaxMatch()
{
	int ans = 0;
	while(bfs())
	{
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= nx; i++) if(xlink[i] == -1)
		{
			ans += find(i);
		}
	}
	return ans;
}

/*void read_case()
{
	init();
	while(p--)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		read_graph(u, v);
	}
}

void solve()
{
	read_case();
	int ans = MaxMatch();
	printf("%d\n", ans);
}

int main()
{
	while(~scanf("%d%d%d", &nx, &ny, &p))
	{
		solve();
	}
	return 0;
}*/

int gcd(int a,int b)
{
    int temp,g;
    if(b>a){temp=a;a=b;b=temp;}
    while(b!=0)
    {
        g=a%b;
        a=b;
        b=g;
    }
    return a;
}

int main()
{
    int i,j,a[110000],b[110000],u,v;
    scanf("%d",&nx);
    ny=nx;
    init();
    for(i=0;i<nx;i++){scanf("%d",&a[i]);}
    for(i=0;i<nx;i++){scanf("%d",&b[i]);}
    for(i=0;i<nx;i++)
    {
        for(j=0;j<nx;j++)
        {
            if(gcd(a[i],b[j])>1)
            {
                //printf("%d %d\n",a[i],b[j]);
                u=i+1;
                v=j+1;
                read_graph(u, v);
            }
        }
    }
	printf("%d\n",MaxMatch());
    return 0;
}
