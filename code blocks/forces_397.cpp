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
#define rep(i,n) for(i=0;i<n;i++)
#define fi(i,a,n) for(i=a;i<=n;i++)
#define fd(i,n,a) for(i=n;i>=a;i--)
#define input(f) freopen("f.txt","r",stdin)

//////////////// bondapa /////////////
#define all(a) a.begin(),a.end()
#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define lmax numeric_limits<llu>::max()
#define lmin numeric_limits<llu>::min()
///////////////////////////////////////


int main()
{
    //freopen("i.txt","r",stdin);
    int t,n,cnt;int i,j,k,x,y,yi;
    cnt=0;
    int ans[104];
    memset(ans,0,sizeof(ans));
    cin>>n;
    cin>>yi>>yi;
    if(n==1){pi(yi);return 0;}
    fi(i,1,n-1)
    {
        cin>>x>>y;
       // pi(x);pi(y);
        fi(j,x,y-1)
        {
            ans[j]=1;
        }
    }
    //fi(i,0,yi){pi(ans[i]);}
    fi(i,0,yi){if(ans[i]==0)cnt++;}
    pi(cnt);
    //fclose(stdin);
    return 0;
}

