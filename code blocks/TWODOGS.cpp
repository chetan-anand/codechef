#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef vector <int> vi;
typedef pair <int,int> pii;

#define pb push_back
#define mp make_pair
#define gi(n) scanf("%d",&n)
#define gl(n) scanf("%llu",&n)
#define pi(n) printf("%d\n",n)
#define pl(n) printf("%llu\n",n)
#define rep(i,n) for(int i=0;i<n;i++)
#define fi(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define input(f) freopen("f.txt","r",stdin)

//////////////// bondapa /////////////
#define all(a) a.begin(),a.end()
#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define lmax numeric_limits<llu>::max()
#define lmin numeric_limits<llu>::min()
///////////////////////////////////////


int app[1000004];
int pos[1000004];
int has[1000004];

int main()
{
    //freopen("i.txt","r",stdin);
    int n,k,i,j;
    memset(has,0,sizeof(has));
    cin>>n>>k;
    //cout<<n<<" "<<n<<endl;
    for(i=1;i<=n;i++)
    {
        cin>>app[i];
        has[app[i]]=1;
    }

    for(i=1;i<=n;i++)
    {
        pos[app[i]]=i;
    }

    for(i=1;i<=n;i++)
    {
        pos[app[i]]=min(pos[app[i]],min(i,n-i+1));
    }
    int minv;
    minv=500001;
    for(i=1;i<=n;i++)
    {
        if(k-app[i]>0){
        if(has[k-app[i]]==1 && k!=2*app[i])
        {
            minv=min(minv,max(pos[app[i]],pos[k-app[i]]));
        }
        }
    }
    if(minv==500001){cout<<"-1"<<endl;}
    else{cout<<minv<<endl;}

    //fclose(stdin);
    return 0;
}
