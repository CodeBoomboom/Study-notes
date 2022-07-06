#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//异常基本语法
//异常跨函数
//异常必须处理

int divide(int x, int y) {
    if (y == 0) {
        throw y;    //抛异常
    }
    return x / y;
}

void test01() {
    //试着去捕获异常
    try {
        divide(10, 0);
    }
    catch (int e) {  //异常是根据类型进行匹配
        cout << "除数为" <<e<< endl;
    }
}


void CallDivide(int x, int y) {
    divide(x, y);
}
void test02() {
    //试着去捕获异常
    try {
        CallDivide(10, 0);
    }
    catch (int e) {  //异常是根据类型进行匹配
        cout << "除数为" << e << endl;
    }
}


int main()
{
    test01();
    test02();
    return 0;
}