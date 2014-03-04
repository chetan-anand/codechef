#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005
vector<int>ad[MAX];
bool visited[MAX];
int father[MAX];
bool mark[MAX];
int window[MAX];
long long int t_pair=0L;
long long int temp_second=0L;

inline void fastRead_int(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if(c=='-') {
    	neg = 1;
    	c = getchar_unlocked();
    }

    for(; c>47 && c<58 ; c = getchar_unlocked()) {
    	x = (x<<1) + (x<<3) + c - 48;
    }

    if(neg)
    	x = -x;
}

void dfs(int node)
{
  visited[node]=true;

  for(int i=0;i<ad[node].size();i++)
  {
  	if(!visited[ad[node][i]])
  	{
  		father[ad[node][i]]= node;
  		visited[ad[node][i]]=true;
  		if(window[ad[node][i]]==1)
  		{
  			t_pair++;
  			mark[father[ad[node][i]]]=true;
  			window[father[ad[node][i]]]=1;
  			mark[ad[node][i]]=true;
  		}
  		dfs(ad[node][i]);
  		if(window[ad[node][i]]==1)
  		{
  			mark[father[ad[node][i]]]=true;
  			window[father[ad[node][i]]]=1;
  		}
  	}
  }

}
int main()
{
	int n,m;
	//scanf("%d%d",&n,&m);
	fastRead_int(n);
	fastRead_int(m);
	for(int i=1; i<=n;i++)
	{
		visited[i]=false;
		father[i]=0;
		window[i]=0;
		ad[i].clear();
		mark[i]=false;
	}
	visited[0]=true;
	mark[0]=true;
	for(int i=1;i<=n;i++)
    {
        fastRead_int(window[i]);
    }
	 //scanf("%d",&window[i]);
    for(int i=1; i<=m;i++)
    {
    	int c,d;
    	//scanf("%d%d",&c,&d);
    	fastRead_int(c);
    	fastRead_int(d);
    	ad[c].push_back(d);
    	ad[d].push_back(c);
    }
    bool flag=false;
    int node=1;
    long long int first=0L;
    long long int second =0L;
   for(int j=1;j<=n;j++)
   {
   	t_pair=0;
   	if(!visited[j] && window[j]==1)
   	dfs(j);
   first+=t_pair*(t_pair+1)/2;
   }

    for(int i=1;i<=n;i++)
    {
    	if(mark[i])
    	 second++;
    }

    printf("%lld% lld\n",first,second);
    return 0;
}
