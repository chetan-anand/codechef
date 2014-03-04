#include<iostream>
#include<string.h>
#include<climits>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<queue>
#include<math.h>
#include<sstream>
#include<vector>
#include<map>
using namespace std;
bool bfs(vector<vector <int> > &resgraph,int s,int d,int parent[])
{
	bool value=false;
	queue<int> q;
	bool explored[d+1];
	for (int i = 0; i < d+1; ++i)
	{
		explored[i]=false;
	}
	q.push(s);
	explored[s]=true;
	while(!q.empty())
	{
		int temp=q.front();
		if(temp==d)
		{
			value=true;
		}
		q.pop();
 		for(vector<int>::iterator it=resgraph[temp].begin();it!=resgraph[temp].end();it++)
 		{
 			if(explored[*it]==false)
 			{
 				parent[*it]=temp;
 				q.push(*it);
 				explored[*it]=true;
 			}
 		}
	}
	return value;
}
int ford_fulkerson(vector< vector <int> > &adj,int x_count,int y_count)
{
	int n=x_count+y_count+2;
	int parent[n],flow=0;
	vector< vector <int> > resgraph;
	resgraph=adj;
	vector< vector <int> >::iterator it;
	vector<int>::iterator it2;
	while(bfs(resgraph,0,n-1,parent))
	{
		flow++;
		int path_flow=INT_MAX,s,t,u,d;
		s=0;
		d=n-1;
		for(int v=d;v!=s;v=parent[v])
		{
			u=parent[v];
			for(it2=resgraph[u].begin();it2!=adj[u].end();it2++)
			{
				if(*it2==v)
				{
					resgraph[u].erase(it2);
					break;
				}
			}
			resgraph[v].push_back(u);
		}
	}
	return flow;
}
int main(int argc, char const *argv[])
{
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
		vector< vector <int> > adj;
		int n,x_count=1,y_count=1,x1,y1;
		cin>>n;
		map<int,int> x;
		map<int,int> y;
		int arr[1000][2];
		for (int i = 0; i < n; ++i)
		{
			cin>>x1;
			cin>>y1;
			if(x[x1]==0)
			{
				x[x1]=x_count;
				x_count++;
			}
			if (y[y1]==0)
			{
				y[y1]=y_count;
				y_count++;
			}
			arr[i][0]=x1;
			arr[i][1]=y1;
			//adj[x[x1]].push_back(y[y1]);
		}
		adj.resize(x_count+y_count+2);
		for (int i = 0; i < n; ++i)
		{
			adj[x[arr[i][0]]].push_back(x_count+y[arr[i][1]]);
		}
		vector< vector <int> >::iterator it;
		vector<int>::iterator it2;
		for (int i = 1; i <	x_count; ++i)
		{
			adj[0].push_back(i);
		}
		for(int i=x_count+1;i < y_count+x_count+1;i++)
		{
			adj[i].push_back(x_count+y_count+1);
		}
		/*for(it=adj.begin();it<adj.end();++it)
		{
			cout<<(it-adj.begin())<<"--";
			for(it2=it->begin();it2<it->end();++it2)
			{
				cout<<*it2<<",";
			}
			cout<<endl;
		}*/
		cout<<ford_fulkerson(adj,x_count,y_count)<<endl;
	}
	return 0;
}
