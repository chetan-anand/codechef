#include<stdio.h>
#include<string.h>
int main()
{
    int t,k,i,j,len,c,d,e,flag,l,flag1;
    int a[10]={0,1,2,3,4,5,6,7,8,9};
    char b[102],x[102];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&k);
        scanf("%s",b);

        len=strlen(b);
        if(k==2&& len>1)
        {
            flag=0;flag1=0;
            if(len%2!=0){printf("NO\n");}
            else
            {
                for(i=0;i<=len;i++)
                {
                    if(b[i]=='?'){x[i]=(i%2)+48;}
                    else{x[i]=b[i];}
                }
                for(i=0;i<len;i++)
                {
                    if(x[i]==x[(i+1)%len]){flag=1;break;}
                }
                if(flag==0){puts(x);}
                if(flag==1)
                {
                   for(i=0;i<=len;i++)
                    {
                        if(b[i]=='?'){x[i]=(i+1)%2+48;}
                        else{x[i]=b[i];}
                    }
                    for(i=0;i<len;i++)
                    {
                        if(x[i]==x[(i+1)%len]){flag1=1;break;}
                    }
                    if(flag1==0){puts(x);}else{printf("NO\n");}
                }

            }
        }
        else{flag=0;
        for(i=0;i<len;i++)
        {
            if(b[i]=='?')
            {
                        d=b[(i+len-1)%len];
                        e=b[(i+1)%len];
                        for(j=0;j<k;j++)
                        {
                        c=a[j];c=c+48;
                        if(c!=d && c!=e){b[i]=c;break;}
                        }
            }
        }
        if(len>1)
        {
            for(i=0;i<len;i++)
            {
                if(b[i]==b[(i+1)%len]||b[i]=='?'){flag=1;break;}
            }
        }
        k=k+48;
        k=k-1;
        for(i=0;i<len;i++)
        {
           l=b[i];
           if(l>k){flag=1;break;}
        }
        if(flag==1){printf("NO\n");}
        else{puts(b);}
        }
    }
    return 0;
}
