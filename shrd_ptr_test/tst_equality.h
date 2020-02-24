#ifndef TST_EQUALITY_H
#define TST_EQUALITY_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "../shared_ptr.h"
#include "../myclass.h"
using namespace testing;

TEST(std_cmpr, equality)
{
    std::shared_ptr<MyClass> std_ptr1(new MyClass(100));
    easymile::Shared_ptr<MyClass> ptr1(new MyClass(101));
    cout << "--- Shared pointers ptr1 ---\n";
    cout <<"ptr1  adr :" <<ptr1<<" ptr1 counter :"<<endl;
    cout <<"ptr1  adr :" <<std_ptr1<<" ptr1 counter :"<<endl;
    EXPECT_EQ(ptr1.use_count(), std_ptr1.use_count());

    {
        // ptr2 pointing to same integer
        // which ptr1 is pointing to
        // Shared pointer reference counter
        // should have increased now to 2.
        std::shared_ptr<MyClass> std_ptr2 = std_ptr1;
        easymile::Shared_ptr<MyClass> ptr2 = ptr1;

        cout << "--- Shared pointers ptr1, ptr2 ---\n";
        cout <<"ptr1  adr :" <<ptr1<<" ptr1 counter :"<<endl;
        cout <<"ptr2  adr :" <<ptr2<<" ptr2 counter :"<<endl;

        EXPECT_EQ( ptr1.use_count(), std_ptr1.use_count());

        {
            // ptr3 pointing to same integer
            // which ptr1 and ptr2 are pointing to.
            // Shared pointer reference counter
            // should have increased now to 3.
            std::shared_ptr<MyClass> std_ptr3(std_ptr2);
            easymile::Shared_ptr<MyClass> ptr3(ptr2);
            cout << "--- Shared pointers ptr1, ptr2, ptr3 ---\n";
            cout <<"ptr1  adr :" <<ptr1<<" ptr1 counter :"<<endl;
            cout <<"ptr2  adr :" <<ptr2<<" ptr2 counter :"<<endl;
            cout <<"ptr3  adr :" <<ptr3<<" ptr3 counter :"<<endl;
            EXPECT_EQ(ptr1.use_count(), std_ptr1.use_count());

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

    EXPECT_EQ(ptr1.use_count(), std_ptr1.use_count());

}

#endif // TST_EQUALITY_H
