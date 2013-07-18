#include<stdio.h>
#include<string.h>

/*#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b*/

long long int max(long long int a,long long int b)
{
    return a>b?a:b;
}

long long int min(long long int a,long long int b)
{
    return a<b?a:b;
}


void init(long long int a[11000],long long int n,long long int dpmax[11000],long long int dpmin[11000])
{

    long long int i,maxv,curmax,curmin;
    dpmin[0]=dpmax[0]=curmax=curmin=a[0];
    for(i=1;i<n;i++)
    {
        curmax=max(curmax+a[i],a[i]);
        dpmax[i]=max(dpmax[i-1],curmax);
        curmin=min(curmin+a[i],a[i]);
        dpmin[i]=min(dpmin[i-1],curmin);
    }
}

void init1(long long int b[11000],long long int n,long long int dpmax1[11000],long long int dpmin1[11000])
{

    long long int i,maxv,curmax,curmin;
    dpmin1[0]=dpmax1[0]=curmax=curmin=b[0]=curmin=curmax[20];
    for(i=1;i<n;i++)
    {
        curmax=max(curmax+b[i],b[i]);
        dpmax1[i]=max(dpmax1[i-1],curmax);
        curmin=min(curmin+b[i],b[i]);
        dpmin1[i]=min(dpmin1[i-1],curmin);
    }
}

int main()
{
    long long int a[11000],t,i,n,dif1,dif2,temp;
    long long int b[11000];
    long long int dpmax1[11000];
    long long int dpmin1[11000];
    long long int dpmin[11000];
    long long int dpmax[11000];
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        memset(dpmax,0,sizeof(dpmax));
        memset(dpmin,0,sizeof(dpmin));
        memset(dpmin1,0,sizeof(dpmin1));
        memset(dpmax1,0,sizeof(dpmax1));
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            b[n-1-i]=a[i];
        }

        init(a,n,dpmax,dpmin);
        init1(b,n,dpmax1,dpmin1);
        /*for(i=0;i<n;i++)
        {
            printf("%lld=%lld\n",i,dpmax[i]);
        }
        printf("---------------\n");
        for(i=0;i<n;i++)
        {
            printf("%lld=%lld\n",i,dpmin[i]);
        }*/
        dif1=dif2=0;
        for(i=1;i<=n-1;i++)
        {
            if((dpmax[i-1]-dpmin1[n-1-i])<0){temp=dpmin1[n-1-i]-dpmax[i-1];}
            else{temp=dpmax[i-1]-dpmin1[n-1-i];}
            dif1=max(dif1,temp);
            if((dpmin[i-1]-dpmax1[n-1-i])<0){temp=dpmax1[n-1-i]-dpmin[i-1];}
            else{temp=dpmin[i-1]-dpmax1[n-1-i];}
            dif2=max(dif2,temp);
        }
        printf("%lld\n",max(dif1,dif2));
    }
    return 0;
}
