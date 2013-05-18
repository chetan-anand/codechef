#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k,t,addr,found,flag;
    char m[270000],w[270000],ch;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s %s",m,w);
        if(strlen(m)<strlen(w))
        {
            addr=0;
            for(i=0;i<strlen(m);i++)
            {
                found=0;
                for(j=addr;j<strlen(w);j++)
                {
                    if(m[i]==w[j])
                    {
                        found=1;
                        addr=j+1;
                        break;
                    }
                }
                if(found==0){break;}
            }
            if(found==0){printf("NO\n");}
            else{printf("YES\n");}
        }
        else
        {
            addr=0;
            for(i=0;i<strlen(w);i++)
            {
                found=0;
                for(j=addr;j<strlen(m);j++)
                {
                    if(w[i]== m[j])
                    {
                        found=1;
                        addr=j+1;
                        break;
                    }
                }
                if(found==0){break;}
            }
            if(found==0){printf("NO\n");}
            else{printf("YES\n");}
        }
    }
    return 0;
}
