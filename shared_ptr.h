#ifndef _SHARED_PTR_H_
#define _SHARED_PTR_H_
#include<iostream>

using namespace std;

namespace easymile {

// Class representing a reference counter class
class Counter {

private:
    unsigned int m_counter{};

public:
    // Constructor
    Counter()
        : m_counter(0){};

    Counter(const Counter&) = delete;
    Counter& operator=(const Counter&) = delete;
    // Destructor
    ~Counter()
    {
    }

    void reset()
    {
        m_counter = 0;
    }

    unsigned int get()
    {
        return m_counter;
    }

    // Overload post/pre increment
    void operator++()
    {
        m_counter++;
    }

    void operator++(int)
    {
        m_counter++;
    }

    // Overload post/pre decrement
    void operator--()
    {
        m_counter--;
    }
    void operator--(int)
    {
        m_counter--;
    }

    // Overloading << operator
    friend ostream& operator<<(ostream& os, const Counter& counter)
    {
        os << counter.m_counter;
        return os;
    }

};

// Class representing a shared pointer
template <typename T>
class Shared_ptr {
private:
    // Reference counter
    Counter* m_counter;

    // Shared pointer
    T* m_ptr;

public:
    // Constructor
    explicit Shared_ptr(T* ptr = nullptr)
    {
        m_ptr = ptr;
        m_counter = new Counter();
        if (ptr) {
            (*m_counter)++;
        }
    }

    // Copy constructor
    Shared_ptr(Shared_ptr<T>& sp)
    {
        m_ptr = sp.m_ptr;
        m_counter = sp.m_counter;
        (*m_counter)++;
    }

    // Reference count
    unsigned int use_count()
    {
        return m_counter->get();
    }

    // Get the pointer
    T* get() const
    {
        return m_ptr;
    }
    // Move constructor
    Shared_ptr(Shared_ptr&& rhs)
    {
        m_ptr = rhs.m_ptr;
        m_counter = rhs.m_counter;
        rhs.m_ptr = nullptr;
        rhs.m_counter = nullptr;
    }
    // Destructor
    ~Shared_ptr()
    {
        (*m_counter)--;
        if (m_counter->get() == 0) {
            delete m_counter;
            delete m_ptr;
        }
    }
    // Note: the std::shared_ptr::reset method is template
    //       but we'll keep things simple with a non-template method.

   void reset()
   {
       m_counter->reset();
       delete m_ptr;
   }

    //operators
    Shared_ptr<T>& operator= (const Shared_ptr<T>& sp)
    {
        m_ptr = sp.m_ptr;
        m_counter = sp.m_counter;
        (*m_counter)++;
        return this;
    }

    T& operator*() const
    {
        return *m_ptr;
    }

     T* operator->() const
     {
         return m_ptr;
     }
    //move operator
    Shared_ptr& operator=(Shared_ptr&& rhs)
    {
         /*   (*m_counter)--;
            if (m_counter->get() == 0) {
                delete m_counter;
                delete m_ptr;
            }*/
            m_ptr = rhs.m_ptr;
            m_counter = rhs.m_counter;
            rhs.m_ptr = nullptr;
            rhs.m_counter = nullptr;
    }

    bool operator<(const Shared_ptr& b) const {
            return m_ptr<b.mptr;
    }

    explicit operator bool() const { return m_ptr!=nullptr; }

    friend ostream& operator<<(ostream& os, Shared_ptr<T>& sp)
    {
        os << sp.get();
        return os;
    }

};


}

#endif
