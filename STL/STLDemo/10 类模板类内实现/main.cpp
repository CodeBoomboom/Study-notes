#include <stdio.h>
#include <stdlib.h>
#include<string>
#include<iostream>
using namespace std;

template<class T1, class T2>
class Person {
public:
    Person(T1 name, T2 age) {
        this->mAge = age;
        this->mName = name;
    }

    void Show()
    {
        cout << "name:" << mName << "age:" << mAge << endl;
    }
public: 
    T1 mName;
    T2 mAge;

};

void test01()
{
    Person<string, int> a("xdx", 23);
    a.Show();
}

int main()
{
    test01();

    printf("\n");
    system("pause");
    return 0;
}