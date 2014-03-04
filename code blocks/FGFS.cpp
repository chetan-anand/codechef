#include<bits/stdc++.h>
using namespace std;

map<long long int,vector<pair<long long int,long long int>>> sc;
map<long long int,vector<pair<long long int,long long int>>>::iterator it;
int main()
{
    int t;
    long long int n,k,s,f,p,temp,i,j,k,curr;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&k);
        for(i=0;i<n;i++)
        {
            scanf("%lld %lld %lld",&s,&f,&p);
            arr[p-1].push_back(make_pair(f,s));
        }
        temp=0;
        for(it=sc.begin();it!=sc.end();it++)
        {
            j=it->second.size();
            if(j==0){continue;}
            curr=0;
            sort(it->second.begin(),it->second.end());
            for(k=0;k<j;k++)
            {
                if(it->second)
            }
        }
    }
    return 0;
}
