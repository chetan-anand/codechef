#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,i,j,k,x[110000],max;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&q);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x[i]);
        }
        for(i=0;i<q;i++)
        {
            scanf("%d%d%d",&a,&p,&r);
            for(i=p-1;i<=r-1;i++)
            {
                if(i==p-1){max=a^x[i];continue;}
                if((a^x[i])>max){max=(a^x[i])}

            }
        }

    }
    return 0;
}
