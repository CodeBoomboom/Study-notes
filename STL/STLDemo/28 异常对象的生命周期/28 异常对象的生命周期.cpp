#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyException {
public:
    MyException() {
        cout << "构造函数" << endl;
    }

    MyException(const MyException& copy) {
        cout << "拷贝构造" << endl;
    }
    MyException(const MyException&& copy) {
        cout << "拷贝构造" << endl;
    }
    ~MyException() {
        cout << "析构函数" << endl;
        }
};
void func01() {
    throw MyException();    //创建匿名对象 调用构造
}

void func02() {
    MyException err = MyException();
    throw& err;
    //throw &(MyException());    //创建匿名对象 调用构造    //匿名对象是右值无法取引用，不知道视频是怎么可以的
}

void func03() {
    throw new MyException();
}

void test01() {

    //普通元素类型  引用  指针  

    //普通元素类型 catch处理完之后就析构
    try {
        func01();
    }
    catch (MyException e) { //调用拷贝构造
        cout << "异常捕获" << endl;
    }

    //引用类型 不用调用拷贝构造，catch处理完就析构
    try {
        func01();
    }
    catch (MyException& e) { //不会再调用任何构造
        cout << "异常捕获" << endl;
    }

    //指针类型 在catch前就已经析构了，就不能在catch里调用MyException对象的方法等进行处理了
    try {
        func02();
    }
    catch (MyException* e) { 
        cout << "异常捕获" << endl;
    }

    //指针类型 如果想在catch里调用MyException对象的方法等进行处理，需要这么做：
    try {
        func03();
    }
    catch (MyException* e) {
        cout << "异常捕获" << endl;
        delete e;//手动释放
    }
}

int main()
{
    test01();


    return 0;
}