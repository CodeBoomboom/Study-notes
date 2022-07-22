#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//适配器模式就是将已经写好的接口，但是这个接口不符合需求
//将写好的接口转换成目标接口

//这函数我已经写好，是两个参数的，但是for_each需要的是一个参数的，需要转换适配成一个参数的
struct MyPrint{
    void operator()(int v1, int v2) {
        cout << v1 + v2 << endl;
    }
};

//定义目标接口，我要适配成什么样的
class Targrt {
public:
    virtual void operator()(int val) = 0;
};

//适配器
class Adapter :public Targrt {
public:
    Adapter(int param) {
        this->param = param;
    }
    virtual void operator()(int val) {
        print(val , param);
    }
public:
    MyPrint print;
    int param;
};

//MyBind2nd
Adapter MyBind2nd(int v) {
    return Adapter(v);
}

int main(){

    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    for_each(v.begin(), v.end(), MyBind2nd(10));

    return 0;
}