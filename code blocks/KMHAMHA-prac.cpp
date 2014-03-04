#include<stdio.h>
#include<string.h>
#include<map>
#include<algorithm>
#include<stdlib.h>
using namespace std;

const int maxn=1000;

vector<int> adj[maxn];
int mark[maxn], stamp, match[maxn];

int main()
{
    int t,n,i,j,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        map<int, int> hashx,hashy;
        for(i=0;i<n;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            if(!hashx.count(x))//
            {
                int newid=hashx.size();// return the size of the map
                adj[newid].clear();// Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
                hashx[x]=newid;
            }
            x=hashx[x];

        }
    }
    return 0;
}
