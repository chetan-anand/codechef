#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("i.txt","r",stdin);
    int a[150],b[150],t,i,j,k;
    cin>>t;
    while(t--)
    {
        string ach,bch;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        cin>>ach;
        cin>>bch;
        //cout<<ach<<endl;
        //cout<<bch<<endl;
        for(i=0;ach[i]!='\0';i++)
        {
            a[ach[i]]++;
        }

        for(i=0;bch[i]!='\0';i++)
        {
            b[bch[i]]++;
        }
        int cnt=0;
        for(i=0;i<=150;i++)
        {
            if(a[i]>0 && b[i]>0)
            {
                cnt=cnt+min(a[i],b[i]);
            }
        }
        cout<<cnt<<endl;
    }
    //fclose(stdin);
    return 0;
}
