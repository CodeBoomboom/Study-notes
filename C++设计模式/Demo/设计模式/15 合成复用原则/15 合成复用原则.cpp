#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//合成复用原则

class AbstractCar {
public:
    virtual void run() = 0;
};

class DaZhong :public AbstractCar {
public:
    virtual void run() {
        cout << "大众启动" << endl;
    }
};

class Tuolaji :public AbstractCar {
public:
    virtual void run() {
        cout << "拖拉机启动" << endl;
    }
};

#if 0
//针对具体类，不适用继承
class Person :public Tuolaji {
public:
    void Doufeng() {
        run();
    }
};
#endif

//可以使用组合
class Person {
public:
    void setCar(AbstractCar* car) {
        this->Car = car;
    }
    void Doufeng() {
        this->Car->run();
        if (this->Car != NULL) {
            delete this->Car;
            this->Car = NULL;
        }
    }
    ~Person() {
    }
public:
    AbstractCar* Car;
};
void test02() {
    Person* p = new Person;
    p->setCar(new DaZhong);
    p->Doufeng();

    p->setCar(new Tuolaji);
    p->Doufeng();
    delete p;
}

int main()
{
    test02();
    return 0;
}
