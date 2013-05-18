#include<stdio.h>
int main()
{
    int t,g,n,q,f;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&g);
        while(g--)
        {
            scanf("%d %d %d",&f,&n,&q);
            if(n%2==0){printf("%d\n",n/2);}
            else
            {
                if(f==q)
                {
                    printf("%d\n",n/2);
                }
                else{printf("%d\n",(n/2)+1);}
            }
        }
    }
    return 0;
}
