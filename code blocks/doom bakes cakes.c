#include<stdio.h>
#include<string.h>
int main()
{
    int t,k,i,j,len,c,d,e,flag,l,m;
    int a[10]={0,1,2,3,4,5,6,7,8,9};
    char b[1000],g[1000],ch;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&k);
        scanf("%s",b);
        //puts(b);
        flag=0;l=0;
        len=strlen(b);
        for(i=0;i<len;i++)
        {
            if(b[i]=='?')
            {
                if(b[(i+1)%len]=='?')
                {
                    d=b[(i+len-1)%len];
                    for(j=0;j<k;j++)
                    {
                        c=a[j];c=c+48;
                        if(c!=d){b[i]=c;break;}
                    }
                }
                else
                {
                    d=b[(i+len-1)%len];
                    e=b[(i+len+1)%len];
                    for(j=0;j<k;j++)
                    {
                        c=a[j];c=c+48;
                        if(c!=d && c!=e){b[i]=c;break;}
                    }
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
        for(i=0;i<len;i++)
        {
                          g[i]=b[i];
              if(b[i]!='-')
              {
                           ch=b[i];l++;
                           for(m=0;b[m]!='\0';m++)
                           {
                                                  if(ch==b[m]){b[m]='-';}
                                                  }
                                                  }
                                                  }
        g[len]='\0';
        if(l>k){flag=1;}

        if(flag==0){puts(g);}else{printf("NO\n");}
    }
    return 0;
}
