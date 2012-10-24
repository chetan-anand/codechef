#include<stdio.h>
#include<string.h>
int p(char c[],int x)
{
    int i,s,a,j,b,k;
    s=0;i=0;
    for(j=0;c[j]!='\0';j++)
    {
        if(c[j]==' '||j==0)
        {
            sscanf(c+j,"%d",&a);
            b=1;
            for(k=0;k<i;k++)
            {
               b=b*x;
            }
            s=s+a*b;
            i++;
        }
    }
    return s;
}
int main()
{
    int t,m,n,x,a[1000],d,e,i,j,k,g,s,ans,l;
    long long int s1;
    char c[1000];
    scanf("%d",&t);
    for(l=0;l<t;l++)
    {
        scanf("%d %d %d",&m,&n,&x);

       /* printf("%d\n",m);
        printf("%d\n",n);
        printf("%d\n",x);
        printf("a\n");*/
        getchar();
        scanf("%d %[^\n]s",&d,c);
        e=1;
        for(i=0;i<m;i++)
        {
            e=e*10;
        }
        k=0;
        for(i=0;i<e;i++)
        {
            g=i;s=0;
            if((g%10)>n){continue;}
            for(j=0;g!=0;j++)
            {
                s=s+(g%10);
                if(s>n){break;}
                g=g/10;
            }
            if(s==n){a[k]=i;k++;}
        }
        s1=0;
        for(i=0;i<k;i++)
        {
            e=1;
            for(j=0;j<m;j++)
            {
                ans=p(c,(a[i]%10)*x);
                a[i]=a[i]/10;
                e=e*ans;
            }
            s1=s1+e;
        }
        s1=s1%1000000007;
        printf("%lld\n",s1);
    }
    return 0;
}
