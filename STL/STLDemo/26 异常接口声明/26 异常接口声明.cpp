#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//这个函数只能抛出int float char三种类型的异常，抛出其他的异常会报错，中止程序
void func() throw(int, float, char) {
    throw "asd";//char*
}

//不能抛出任何异常      在vc中可以正常跑，是因为vc对这个可能支持不太好，在linux中是无法跑的
void func01() throw() {
    throw - 1;
}

int main()
{
    //try {
    //    func();
    //}
    //catch (char* str) {
    //    cout << str << endl;
    //}
    //catch (int e) {
    //    cout << e << endl;
    //}
    //catch (...) {   //  捕获所有异常

    //}

    try {
        func01();
    }
    catch (int a) {
        cout << a << endl;
    }
    return 0;
}