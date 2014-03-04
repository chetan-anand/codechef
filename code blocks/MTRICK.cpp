#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll l[1100];
char s[1100];

void fr(int i)
{
    int j,k;
    for(j=)
}

void fa(int i)
{

}


void fm(int i)
{

}


int main()
{
    /*ll temp=1000000000000000010;
    cout<<temp<<endl;*/
    ll t,a,b,c,n,i,j,k;

    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>l[i];
        }
        cin>>a>>b>>c;
        cin>>s;
        cout<<s<<endl;
        //int len=strlen(s);
        for(i=0;i<n;i++)
        {
            if(s[i]=='R'){fr(i);}
            if(s[i]=='A'){fa(i);}
            if(s[i]=='M'){fm(i);}
        }

        for(i=0;i<n;i++)
        {
            printf("%lld ",l[i]);
        }
        printf("\n");
    }
    return 0;
}
