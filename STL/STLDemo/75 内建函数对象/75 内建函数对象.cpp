#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<functional>
using namespace std;


void test01() {
    plus<int> myplus;
    int ret = myplus(10, 20);
    cout << ret << endl;
}

int main()
{
    test01();
    system("pause");
    return 0;
}