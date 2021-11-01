#include <iostream>
#include <vector>
#include <unistd.h>
using namespace std;

namespace FatherSpace {
class Father
{
public:
    virtual ~Father();
    virtual void show() = 0;

};

class FatherCreator
{
public:
    virtual ~FatherCreator();

    virtual Father *create() = 0;
    virtual void destory(Father *) = 0;

};

Father::~Father()
{

}

FatherCreator::~FatherCreator()
{

}


}

namespace ChildASpace {
class Childa final: public FatherSpace::Father
{
public:
    ~Childa();
    void show();
};

class ChildaCreator : public FatherSpace::FatherCreator
{
public:
    ~ChildaCreator();
    Childa *create();

    void destory(FatherSpace::Father *c);
};

ChildaCreator::~ChildaCreator()
{

}

Childa *ChildaCreator::create()
{
    return new Childa();
}

void ChildaCreator::destory(FatherSpace::Father *c)
{
    delete c;
}

Childa::~Childa()
{

}

void Childa::show()
{
    cout << "show" << endl;
}

}


int main(void)
{
    ChildASpace::ChildaCreator *creator = new ChildASpace::ChildaCreator();
    FatherSpace::Father *c = creator->create();
    sleep(5);
    c->show();

    creator->destory(c);
    sleep(5);

    return 0;
}
