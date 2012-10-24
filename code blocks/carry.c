#include<stdio.h>
int main()
{
    int i,j,l1,l2,x,y,a[11],b[11],s,cnt,carry;
    for(i=0;;i++)
    {
        cnt=0;
        scanf("%d %d",&x,&y);
        if(x==0 || y==0){break;}
        for(j=0;x!=0;j++)
        {
            a[j]=x%10;
            x=x/10;
        }
        l1=j;
        for(j=0;y!=0;j++)
        {
            b[j]=y%10;
            y=y/10;
        }
        l2=j;
        if(l1>l2){s=l2;}else{s=l1;}
        for(j=0;j<s;j++)
        {
            carry=0;
            if(((b[j]+a[j]+carry)/10)!=0){cnt++;carry=1;}
        }
        if(cnt==0){printf("No carry operation.\n");}
        else if(cnt==1){printf("1 carry opration.\n");}
        else{printf("%d carry operations.\n",cnt);}
    }
    return 0;
}
