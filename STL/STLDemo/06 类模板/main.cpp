#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
template<typename T>
class MyClass
{
public:
    MyClass(T id, T age)
    {
        this->mId = id;
        this->mAge = age;
    }

    void Show()
    {
        cout << "ID:" << mId << "age：" << mAge << endl;
    }

    T mId;
    T mAge;

private:

};

void test01()
{
    //函数模板在调用的时候可以自动类型推导
    //类模板必须显式指定类型
    MyClass<int> p(10, 20);
    p.Show();

}



int main()
{
    test01();

    printf("\n");
    system("pause");
    return 0;
}