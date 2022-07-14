#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct MyPrint {
    MyPrint() {
        num = 0;
    }
    void operator()(int val) {
        cout << val << endl;
        num++;
    }
public:
    int num;
};
void test01() {
    MyPrint print;
    print(10);

    //函数可以像普通函数那样调用
    //函数可以像普通函数那样接收参数
    //函数对象超出了函数的概念，函数对象可以保存函数调用的状态
}

int num1 = 0;//真正在开发中，避免使用全局变量
void MyPrint02(int val) {
    cout << val << endl;
    num1++;
}

void test02() {

    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    //计算函数调用次数
    MyPrint02(10);
    MyPrint02(20);
    cout << num1 << endl;

    MyPrint print;
    print(10);
    print(20);
    cout << print.num << endl;

    MyPrint print1;
    MyPrint print2 = for_each(v.begin(), v.end(), print1);//把print1拷贝一份给print2，用print2完成打印操作
    cout << "print调用次数：" << print1.num << endl;
    cout << "print调用次数：" << print2.num << endl;
}

int main()
{
    //test01();
    test02();
    system("pause");
    return 0;
}