#include<stdio.h>
#include<iostream>
using namespace std;
/*int main()
{
    try
    {
        int age;
        cin >>age;
        if (age>100||age<1)
        throw 'f';
        cout<<"After the throw statement"<<endl;
    }
    catch(char msg)
    {
        cout<<"Error! "<<msg<<endl;
    }
    cout<<"end of the programme"<<endl;
    return 0;
}*/

/*int main()
{
    cout<<"Before the throw statement"<<endl;
    try
    {
        throw 27.9f;//throwing a float value
    }
    catch(char ch)
    {
        cout<<"caught a character"<<endl;
    }
    catch(int num)
    {
        cout<<"caught a integer"<<endl;
    }
    catch(float f)
    {
        cout<<"caught a float"<<endl;
    }

    catch(...)  //this handler is always present at the last of any given try staement
    {
        cout<<"caught an unknown data type"<<endl;
    }

    cout<<"After throw statement"<<endl;
    return 0;
}*/

/*//#include<new>  //new class is derived from exception class.
int main()
{
    char*buff;
    try
    {
        buff=new char[1000000000000000];
    }
    catch(bad_alloc &obj)
    {
        cout<<"Exception raised:"<<obj.what()<<endl;
    }
    return 0;
}*/
/*void terminate();
int main()
{
    cout<<"\n start"<<endl;
    try
    {
        cout<<"insisde a try block"<<endl;
        throw 100;
        cout<<"end of try block"<<endl;
    }

    catch(double i)
    {
        cout<<"\n in catch block"<<endl;
        cout<<"\n value is "<<i;
    }
    cout<<"\n end of the programme"<<endl;
    return 0;
}*/
/*#include<iostream>
 template<class DT>
 DT Max(DT a,DT b)
 {
     return(a>b?a:b);
 }
 int main()
 {
     int i=28,j=26,k;
     long l=9,m=15,n;
     k=Max<int>(i,j);
     n=Max<long>(l,m);
     cout<<k<<endl;
     cout<<n<<endl;
     return 0;
 }*/


//dynamic polymorphism

/*class apple
{
    private:
    int n;
    void disp()
    {
        printf("hello world");
    }
    public:

    void disp1()
    {
        disp();scanf("%d",&n);
        printf("%d\n",n);
    }

};
int main()
{
    apple x;
    x.disp1();
    return 0;
}*/

/*class Customer
{

    private:
    char mn[11];
    char n[25];
    void print()
    {
        printf("%s %s",mn,n);
    }
    public:
    char ba[51];
    float ao;
    void get()
    {
        cin>>ba;
        cin>>ao;
    }
};
int main()
{
    Customer x;
    x.get();

    return 0
}*/

class x
{
    static int i;
    void increament()
    {
        cout<<i<<endl;
        i++;
    }
    public:
    void display()
    {

        increament();
        increament();
    }
};
int x::i=5;

int main()
{

    x y;
    y.display();
    x z;
    z.display();
    return 0;
}
