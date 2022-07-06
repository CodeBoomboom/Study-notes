#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<exception>
#include<stdexcept>
using namespace std;
//编写自己的异常类

class Person {
public:
    Person() {
        mAge = 0;
    }
    void setAge(int age) {
        if (age < 0 || age >100) {
            throw out_of_range("年龄应该在0-100之间！");
        }
        this->mAge = age;
    }
public:
    int mAge;
};

void test01() {
    Person p;
    //try {
    //    p.setAge(1000);
    //}
    //catch (out_of_range e) {
    //    cout << e.what() << endl;
    //}
    try {
        p.setAge(1000);
    }
    catch (exception e) {
        cout << e.what() << endl;
    }
}


class MyOutOfRange : public exception {
public:
    MyOutOfRange(const char* error) {
        pError = new char[strlen(error) + 1];
        strcpy(pError, error);
    }
    ~MyOutOfRange() {
        if (pError != NULL) {
            delete[] pError;
        }
    }
    virtual char const* what() const {
        return pError;
    }
public:
    char* pError;

};

void func02() {
    throw MyOutOfRange("我自己的out_of_range");
}

void test02() {
    try {
       func02();
    }
    catch (exception& e) {  //没写拷贝构造，所以不使用普通类型来接异常，使用引用接
        cout << e.what() << endl;
    }
}

int main()
{
    test01();
    test02();
    return 0;
}