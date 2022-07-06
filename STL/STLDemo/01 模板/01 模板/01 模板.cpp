#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

template<class T>
void MySwap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}


void test01()
{
    int a = 10;
    int b = 20;
    cout << "a:" << a << "b:" << b << endl;
    MySwap(a, b);
    cout << "a:" << a << "b:" << b << endl;
    MySwap<int>(a, b);
    cout << "a:" << a << "b:" << b << endl;

}

int main()
{
    test01();

    printf("\n");
    system("pause");
    return 0;
}