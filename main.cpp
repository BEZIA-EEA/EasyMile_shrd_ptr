#include<iostream>
#include"shared_ptr.h"
#include"myclass.h"

using namespace std;
void print(easymile::Shared_ptr<MyClass> ptr)
{
    cout<<ptr.get()<<endl;
}
int main()
{
    // ptr1 pointing to an integer.
       easymile::Shared_ptr<MyClass> ptr1(new MyClass(151));
       cout << "--- Shared pointers ptr1 ---\n";
       cout <<"ptr1  adr :" <<ptr1<<" ptr1 counter :"<<endl;

       {
           // ptr2 pointing to same integer
           // which ptr1 is pointing to
           // Shared pointer reference counter
           // should have increased now to 2.
           easymile::Shared_ptr<MyClass> ptr2 = ptr1;
           cout << "--- Shared pointers ptr1, ptr2 ---\n";
           cout <<"ptr1  adr :" <<ptr1<<" ptr1 counter :"<<endl;
           cout <<"ptr2  adr :" <<ptr2<<" ptr2 counter :"<<endl;


           {
               // ptr3 pointing to same integer
               // which ptr1 and ptr2 are pointing to.
               // Shared pointer reference counter
               // should have increased now to 3.
               easymile::Shared_ptr<MyClass> ptr3(ptr2);
               cout << "--- Shared pointers ptr1, ptr2, ptr3 ---\n";
               cout <<"ptr1  adr :" <<ptr1<<" ptr1 counter :"<<endl;
               cout <<"ptr2  adr :" <<ptr2<<" ptr2 counter :"<<endl;
               cout <<"ptr3  adr :" <<ptr3<<" ptr3 counter :"<<endl;

           }

           // ptr3 is out of scope.
           // It would have been destructed.
           // So shared pointer reference counter
           // should have decreased now to 2.
           cout << "--- Shared pointers ptr1, ptr2 ---\n";
           cout <<"ptr1  adr :" <<ptr1<<" ptr1 counter :"<<endl;
           cout <<"ptr2  adr :" <<ptr2<<" ptr2 counter :"<<endl;
       }

       // ptr2 is out of scope.
       // It would have been destructed.
       // So shared pointer reference counter
       // should have decreased now to 1.
       cout << "--- Shared pointers ptr1 ---\n";
       cout <<"ptr1  adr :" <<ptr1<<" ptr1 counter :"<<endl;

       cout<<ptr1->getData()<<endl;
       cout<<(*ptr1).getData()<<endl;
       print(ptr1);
       cout<<ptr1;
       return 0;
}
