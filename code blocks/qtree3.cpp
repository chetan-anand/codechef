#include<iostream>
#include<algorithm>
#include<set>
#include<cstdio>
#include<cstdlib>

using namespace std;
#define mp(x,y) make_pair((x),(y))
#define er(S,x) S.erase(S.find(x))

const int maxn=200010;
const int INF=1<<29;
int N,tn,n,m,tot;
int fs[maxn],next[maxn*2],oth[maxn*2];
int q[maxn],fa[maxn],dis[maxn],son[maxn],size[maxn];
int lit[maxn],jump[maxn],sl[maxn];
int fir[maxn],pos[maxn],bel[maxn];
int D0[maxn*4],D1[maxn*4];
bool col[maxn];

multiset<pair<int,int> >S;

    #define Gm(a,x,y) gm((a),1,1,tn,(x),(y))
    #define L(k) ((k)<<1)
    #define R(k) (((k)<<1)+1)
    inline int gm(int *a,int k,int l,int r,int x,int y){
      if(l==x&&r==y)return a[k];
      int mid=(l+r)>>1;
      if(y<=mid)return gm(a,L(k),l,mid,x,y);
      if(x>mid)return gm(a,R(k),mid+1,r,x,y);
      //return min(gm(a,L(k),l,mid,x,mid),gm(a,R(k),mid+1,r,mid+1,y));
      return max(gm(a,L(k),l,mid,x,mid),gm(a,R(k),mid+1,r,mid+1,y));
    }

  void init(){
    int i,x,y,head,tail,u,t,p,j;
    scanf("%d",&N);
    for(i=1;i<N;++i){
      scanf("%d%d",&x,&y);
      oth[++m]=y,next[m]=fs[x],fs[x]=m;
      oth[++m]=x,next[m]=fs[y],fs[y]=m;
    }
    for(q[head=tail=1]=1;head<=tail;)
      for(i=fs[u=q[head++]];i;i=next[i])
        if(oth[i]!=fa[u])fa[q[++tail]=oth[i]]=u;
    for(j=N;j;--j)
      for(u=q[j],size[u]=1,i=fs[u];i;i=next[i])
        if((t=oth[i])!=fa[u]){
          size[u]+=size[t];
          if(size[son[u]]<size[t])son[u]=t;
        }
    for(j=2;j<=N;++j)
      u=q[j],lit[u]=lit[fa[u]]+(son[fa[u]]!=u),dis[u]=dis[fa[u]]+1;
    for(j=1;j<=N;++j)if(!son[j]){
      for(p=j;;p=fa[p])if(son[fa[p]]!=p)break;
      for(sl[++n]=tot+1,i=fir[n]=p;i;i=son[i])
        bel[i]=n,jump[i]=fa[fir[n]],pos[i]=++tot;
    }sl[n+1]=N+1;
    for(tn=1;tn<N;tn<<=1);
    for(i=tn;i<N+tn;++i)D0[i]=INF-i,D1[i]=INF+i;
    for(i=tn-1;i;--i)
      D0[i]=max(D0[L(i)],D0[R(i)]),D1[i]=max(D1[L(i)],D1[R(i)]);
    for(i=1;i<=n;++i)if(jump[fir[i]])
      S.insert(mp(jump[p],Gm(D1,sl[i],sl[i+1]-1)-sl[i]+1));
  }
  void change(int x){
    int t;
 typeof(S.begin()) it;
    if(col[x])er(S,mp(x,0));else S.insert(mp(x,0));
    for(col[x]^=1;x;x=jump[x]){
      n=bel[x];
      if(jump[x]&&!S.empty()){
        it=S.find(mp(jump[x],Gm(D1,sl[n],sl[n+1]-1)-sl[n]+1));
        if(it!=S.end())S.erase(it);
      }
      if(!S.empty()){
     it=S.lower_bound(mp(x,-INF));
         t=(it!=S.end()&&it->first==x)?it->second:INF;
   }else t=INF;
      D0[pos[x]+tn-1]=t-pos[x],D1[pos[x]+tn-1]=t+pos[x];
      for(t=(pos[x]+tn-1)>>1;t;t>>=1)
        D0[t]=max(D0[L(t)],D0[R(t)]),D1[t]=max(D1[L(t)],D1[R(t)]);
      if(jump[x])
        S.insert(mp(jump[x],Gm(D1,sl[n],sl[n+1]-1)-sl[n]+1));
    }
  }
  int query(int x){
    if(col[x])return 0;
    int ans=-1,s=0,t,n;
    for(;x;s+=dis[x]-dis[jump[x]],x=jump[x]){
      if(s<=ans)break;
      n=bel[x];
      //t=min(Gm(D0,sl[n],pos[x])+pos[x],Gm(D1,pos[x],sl[n+1]-1)-pos[x]);
      t=max(Gm(D0,sl[n],pos[x])+pos[x],Gm(D1,pos[x],sl[n+1]-1)-pos[x]);
      //ans=min(ans,t+s);
      ans=max(ans,t+s);
    }
    return ans>=N?-1:ans;
  }

int main(){
  int M,opt,x;
  init();
  for(scanf("%d",&M);M--;){
    scanf("%d%d",&opt,&x);
    if(opt)printf("%d\n",query(x));else change(x);
  }
  return 0;
}
