#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//异常类型

void func01() {
    throw 1;//抛出int类型异常
}

void func02() {
    throw "abc";//抛出char*类型异常
}

class MyException {
public:
    MyException(const char* str) {
        error = new char[strlen(str) + 1];
        strcpy(error, str);
    }
    //27解决办法：增加拷贝构造函数和=运算法重载
    MyException(const MyException& copy) {
        this->error = new char[strlen(copy.error) + 1];
        strcpy(this->error, copy.error);
    }
    MyException& operator=(const MyException& copy) {
        if (this->error != NULL) {
            delete[] this->error;
            this->error = NULL;
        }
        this->error = new char[strlen(copy.error) + 1];
        strcpy(this->error, copy.error);
    }

    void what() {
        cout << error << endl;
    }
    ~MyException() {
        if (error != NULL) {
            delete[] error;
        }
    }
public:
    char* error;
};

void func03() {
    throw MyException("我刚写的异常");
}

void test01() {
    try {
        func01();
    }
    catch (int e) {
        cout << "捕获int异常" << e << endl;
    }

    try {
        func02();
    }
    catch (const char* e) {
        cout << "捕获char*异常" << e << endl;
    }

    try {
        func03();
    }
    catch (MyException e) {//27 会崩，原因：throw的匿名对象会拷贝给此处的e，这两个的error指针都指向同一块内存空间，而我们又没写拷贝构造函数，所以析构的时候同一内存空间会析构两次
        cout << "捕获MyException异常" << endl;
        e.what();
    }

}


int main()
{
    test01();
    return 0;
}