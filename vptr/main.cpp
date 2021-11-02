#include <iostream>
#include <vector>
#include <unistd.h>
using namespace std;

class Base
{
public:
    Base();
    virtual ~Base();
    virtual void base() {}
//    size_t _a;
};

class Father : public virtual Base
{
public:
    Father();
    virtual ~Father();
    virtual void base() {}
    virtual void father() {}
};

class Mother : public virtual Base
{
public:
    Mother() {}
    virtual ~Mother();

    virtual void base() {}
    virtual void mother() {}
};

class Child : public Mother, public Father
{
public:
    Child();
    ~Child();
    void base() {}
};

int main(void)
{

    Child *c = new Child;
    cout << sizeof(Base) << " " << sizeof(Father) << " " << sizeof(Mother) << " " << sizeof(Child) << " ";

    delete c;
    return 0;
}

Father::Father()
{

    cout << __func__ << endl;
}

Father::~Father()
{
    cout << __func__ << endl;
}




Child::Child()
{
    cout << __func__ << endl;
}

Child::~Child()
{
    cout << __func__ << endl;
}

Mother::~Mother()
{

}

Base::Base()
{

}

Base::~Base()
{

}
