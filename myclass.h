#ifndef _MYCLASS_H_
#define _MYCLASS_H_

class MyClass
{
private:
  int m_data;

public:
  MyClass(int data) : m_data{data} { }

  int getData() const { return m_data; }
  void setData(int data) { m_data = data; }
};

#endif
