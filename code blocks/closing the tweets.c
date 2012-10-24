#include<stdio.h>
#include<string.h>
int main()
{
    int n,k,i,j,m,b[1001]={0},cnt=0,flag;
    char a[12],ch;
    scanf("%d %d",&n,&k);
    for(i=0;i<k;i++)
    {
        scanf("%s",a);
        if(strcmp(a,"CLOSEALL")==0)
        {
            cnt=0;
          for(j=0;j<k;j++)
          {b[j]=0;}
            printf("0\n");continue;
        }
        scanf("%d",&m);
        b[m-1]++;
        if((b[m-1])%2==1){cnt++;}
        else{cnt--;}
        printf("%d\n",cnt);
           /*for(j=0;j<k;j++)
            {
                printf("%d\n",b[j]);
            }*/
    }
    return 0;
}
