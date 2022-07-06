#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//栈解旋
class Person {
public:
    Person() {
        cout << "对象构建" << endl;
    }
    ~Person() {
        cout << "对象析构" << endl;
    }
};

int divide(int x, int y) {
    Person p1, p2;
    if (y == 0) {
        throw y;
    }
    return x / y;
}

void test01() {
    try {
        divide(10, 0); //栈解旋就是当发生异常时 ，发生异常的函数的局部变量的内存都会自动析构掉
    }
    catch (int e) {
        cout << "异常捕获" << endl;
    }
}
int main()
{
    test01();
    return 0;
}