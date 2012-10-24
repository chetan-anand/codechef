 /*#include<stdio.h>
 #include<iostream>
 #include<new>
 using namespace std;
 int main()
 {
     int*buff;
     try
     {
         buff=new int[1000000000000000];
     }
     catch(bad_alloc&obj)
     {
         cout<<"Exception raised:"<<obj.what()<<endl;
     }
     return 0;
 }*/

 void terminate();
 #include<iostream>
 using namespace std;
 int main()
 {
     cout<<"\n start";
     try
     {

         cout<<"inside a try block";
         throw 100;
         cout<<"end of try block";

     }
     catch(double i)
     {
         cout<<"\n in catch block";
         cout<<"\n value is "<<i;
     }
     cout<<"\n end if the programme";
     return 0;
 }
