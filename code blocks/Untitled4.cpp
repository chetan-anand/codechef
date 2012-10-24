
//this is the programme for understanding the use of constructor and destructor

#include<stdio.h>
#include<iostream>
class test
{
    public:
    test()
    {
        printf("constructor is invoked\n");
    }
    ~test()
    {
        printf("destructor is invoked\n");
    }
};
test obj1;
int main()
{
    printf("main() begins\n");
    test obj2;
    {
        printf("inner block begins\n");
        test obj3;
        printf("inner block ends\n");
    }
    return 0;
}
