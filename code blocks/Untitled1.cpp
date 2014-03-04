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

int absdif(int a,int b)
{
    if(a>b){return a-b;}
    else
    {return b-a;}
}

int l[100000];
int r[100000];
int main()
{
    int t,i,j,k,n,m;
    int a[11]={1, 3, 7, 17, 41, 99, 239, 577, 1393, 3363};
    int b[11];
    memset(b,0,sizeof(b));
    cin>>t;
    int lv,rv;lv=0;rv=0;
    rv=t;r[0]=t;
    int temp,dif,mini;
    int lcnt=0,rcnt=1;
    while(rv!=lv)
    {
        cout<<rv<<endl;
        cout<<lv<<endl;
        if(rv>lv)
        {
            temp=rv-lv;
            for(i=0;i<=10;i++)
            {
                if(b[i]==1){continue;}
                if(i==0){dif=absdif(a[i],temp);mini=0;}
                else
                {
                    if(absdif(a[i],temp)<dif){dif=absdif(a[i],temp);mini=i;}
                }
            }
            b[i]=1;
            lv=lv+a[i];
            l[lcnt]=a[i];
            lcnt++;
        }
        if(rv<lv)
        {
            temp=lv-rv;
            for(i=0;i<=10;i++)
            {
                if(b[i]==1){continue;}
                if(i==0){dif=absdif(a[i],temp);mini=0;}
                else
                {
                    if(absdif(a[i],temp)<dif){dif=absdif(a[i],temp);mini=i;}
                }
            }
            b[i]=1;
            rv=rv+a[i];
            r[rcnt]=a[i];
            rcnt++;
        }
    }
    sort(l,l+lcnt);
    sort(r,r+rcnt);
    for(i=0;i<lcnt;i++)
    {
        cout<<l[i]<<endl;
    }
    cout<<"\n";
    for(i=0;i<rcnt;i++)
    {
        cout<<r[i]<<endl;
    }


	return 0;
}

