#include<iostream>
#include<string.h>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
              int n,m,k;
              int ini[1001],ini1[1001],c[1001][1001],b[1001][1000],mx[1001];
              cin>>n>>m>>k;
              map<int,vector<int> > mapx; int y=0;
              memset(mx,0,sizeof(mx));
              memset(ini1,0,sizeof(ini1));
              for(int i=1;i<=n;i++)
                      cin>>ini[i];
              for(int i=1;i<=n;i++)
                      for(int j=1;j<=m;j++)
                       cin>>b[i][j];
              for(int i=1;i<=n;i++)
                      for(int j=1;j<=m;j++)
                       cin>>c[i][j];
              for(int i=1;i<=n;i++)
              {        int p=0;
                       for(int j=1;j<=m;j++)
                      {
                             int x;
                             x=b[i][j]-c[i][j]-b[i][ini[i]]-c[i][ini[i]];
                             if(x>p)
                              p=x;
                      }
                      if(p>0)
                       {      mapx[p].push_back(i); mx[y]=p;y++; }
                      }
              sort(mx,mx+y); int result;
              for(int i=y-1;i>=0;i--)
              {
                      if(k>0)
                      {      int indx=mapx[mx[i]].back();

                             ini1[indx]=-1;
                             result+=mx[i];
                             mapx[mx[i]].pop_back();
                             k--;

                             }

                      }
                      y--;
                      //cout<<"inga"<<result<<endl;
              for(int i=1;i<=n;i++)
              {
                   // if(ini1[i]=-1)
                  //  result+=(ini[i]);
                   // else
                    result+=(b[i][ini[i]]-c[i][ini[i]]) ;

              }

                cout<<result<<endl;

                                                         }

    return 0;
}

