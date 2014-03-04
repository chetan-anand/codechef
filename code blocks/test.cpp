#include<stdio.h>
class shape
{
    public:
        shape()
        {
            printf("it is base class\n");
        }
        ~shape()
        {
            printf("~it is base class\n");
        }
};

class circle:shape
{
public:
    circle()
    {
        printf("it is derived class\n");
    }

    ~circle()
        {
            printf("~it is derived class\n");
        }
};
class apple
{
public:
    apple()
    {
        printf("apple \n");
    }

    ~apple()
    {
        printf("~apple \n");
    }

};


int main()
{
    //shape o;
    //apple a;
    circle m;
    /*o.fuck();
    m.fuck();*/
   /* shape *x=new shape();
    x->fuck();
    circle *y=new circle();
    y->fuck();*/
    return 0;
}
