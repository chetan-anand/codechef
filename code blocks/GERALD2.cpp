#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<string.h>
#define max(a,b) a>b?a:b
#define MAX 300000
using namespace std;
typedef pair<int,int> ii;
/*vector<int> adj[MAX];

int dis[MAX];
int ans[MAX];
int col[MAX];
/// 0==white
/// 1==black
int idx[MAX];*/
int n,m,q;

//////////////////////////////////////////////////////////

const int MAXM = 16;
const int MAXN = 1 << MAXM;

// Heavy-Light Decomposition
  vector<int> e[MAXN], c[MAXN];
  int s[MAXN];    // subtree size
  int p[MAXN];    // parent id
  int r[MAXN];    // chain root id
  int t[MAXN];    // timestamp, index used in segtree
  int ts;

  void dfs_(int v, int f) {
    p[v] = f;
    s[v] = 1;
    for (int i = 0; i < (int)e[v].size(); ++i) {
      int w = e[v][i];
      if (w != f) {
        dfs_(w, v);
        s[v] += s[w];
      }
    }
  }

  void decomp_(int v, int f, int k) {
    t[v] = ts++;
    c[k].push_back(v);
    r[v] = k;

    int x = 0, y = -1;
    for (int i = 0; i < (int)e[v].size(); ++i) {
      int w = e[v][i];
      if (w != f) {
        if (s[w] > x) {
          x = s[w];
          y = w;
        }
      }
    }
    if (y != -1) {
      decomp_(y, v, k);
    }

    for (int i = 0; i < (int)e[v].size(); ++i) {
      int w = e[v][i];
      if (w != f && w != y) {
        decomp_(w, v, w);
      }
    }
  }

  void init(int n) {
    for (int i = 0; i < n; ++i) {
      e[i].clear();
    }
  }

  void add(int a, int b) {
    e[a].push_back(b);
    e[b].push_back(a);
  }

  void build() {  // !!
    ts = 0;
    dfs_(0, 0);
    decomp_(0, 0, 0);
  }

///////////////////////////////////////////////////////////

/////////////////////////////OLD ONE/////////////////////////////////////////////////////////////
/*int maxdis(int v,int maxi)
{
    int i,maxv;printf("vertex %d\n",v);

    if(col[v]==1&&adj[v].size()==0){return -1;}
    if(col[v]==0&&adj[v].size()==0){return 0;}

    for(i=0;i<adj[v].size();i++)
    {
        if(i==0){maxv=maxdis(adj[v][i],maxi)+1;maxi=i;}
        //else {maxv=max(maxv,maxdis(adj[v][i])+1);}
        if(maxv<=maxdis(adj[v][i],maxi)+1)
        {
            maxv=maxdis(adj[v][i],maxi)+1;
            maxi=adj[v][i];
        }
    }
    ans[v]=maxi;
    dis[v]=maxv;
    return maxv;
}


void init()
{
    dis[1]=maxdis(1,1);
    //ans[1]=maxans(1);

    for(int i=1;i<=n;i++){printf("dis%d=%d\n",i,dis[i]);}
    for(int i=1;i<=n;i++){printf("ans%d=%d\n",i,dis[i]);}
}
void solve(int q)
{
    if(col[q]==1)
    {
        col[q]=0;

    }
}*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    int tc,i,j,k,v;
    scanf("%d",&t);
    while(tc--)
    {
        //memset(col,0,sizeof(col));
        scanf("%d %d",&n,&m);
        /*
        n=number of vertex of tree
        m=number of operation
        */
        for(i=1;i<=n-1;i++)
        {
            //scanf("%d",&idx[i]);
            //adj[idx[i]].push_back(i);
            scanf("%d",&v);
            v=v-1;
            add(v,i);
        }

        /*for(i=1;i<=n;i++)
        {
            for(j=0;j<adj[i].size();j++)
            {
                printf("%d ",adj[i][j]);
            }
            printf("\n");
        }*/

        /*for(i=1;i<=n;i++)
        {
            adj[i].clear();
        }*/
        //init();
        /*scanf("%d",&m);
        while(m--)
        {
            scanf("%d",&q);
            solve(q);
            for(i=1;i<=n;i++)
            {
                adj[i].clear();
            }
        }*/
        //init(n);
        printf("-----the adjacency list---------\n");
        for(i=0;i<=n-1;i++)
        {
            printf("vertex %d ",i);
            for(j=0;j<e[i].size();j++)
            {
                printf("=%d ",e[i][j]);
            }
            printf("\n");
        }

        build(); //building the Decomposed chains

        printf("-----------------------------------------\n");
        printf("-----decomposed chains---------\n");
        for(i=0;i<=n-1;i++)
        {
            printf("vertex %d ",i);
            for(j=0;j<c[i].size();j++)
            {
                printf("=%d ",c[i][j]);
            }
            printf("\n");
        }
        printf("-----------------------------------------\n");
        for(i=0;i<=n-1;i++)
        {
            printf("s[%d]=%d\n",i,s[i]);
        }

        printf("-----------------------------------------\n");
        for(i=0;i<=n-1;i++)
        {
            printf("p[%d]=%d\n",i,p[i]);
        }

        printf("-----------------------------------------\n");
        for(i=0;i<=n-1;i++)
        {
            printf("r[%d]=%d\n",i,r[i]);
        }

        printf("-----------------------------------------\n");
        for(i=0;i<=n-1;i++)
        {
            printf("t[%d]=%d\n",i,t[i]);
        }

        printf("-----------------------------------------\n");
    }
	return 0;
}


