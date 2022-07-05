#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//开闭原则：对扩展开放，对修改关闭，增加功能是用过增加代码实现的，而不是修改代码
//示例：计算器类要修改就会出错

//应该：写一个抽象类
class AbstractCaculator {
public:
    virtual int getResult() = 0;
    virtual void setOperatorNumber(int a, int b) = 0;

};

//加法计算器类
class PlusCaculator :public AbstractCaculator {
public:
    virtual void setOperatorNumber(int a, int b) {
        this->mA = a;
        this->mB = b;
    }
    virtual int getResult() {
        return mA + mB;
    }
public:
    int mA;
    int mB;
};


//减法计算器类
class MinuteCaculator :public AbstractCaculator {
public:
    virtual void setOperatorNumber(int a, int b) {
        this->mA = a;
        this->mB = b;
    }
    virtual int getResult() {
        return mA - mB;
    }
public:
    int mA;
    int mB;
};

//乘法计算器类
class MultiplyCaculator :public AbstractCaculator {
public:
    virtual void setOperatorNumber(int a, int b) {
        this->mA = a;
        this->mB = b;
    }
    virtual int getResult() {
        return mA * mB;
    }
public:
    int mA;
    int mB;
};

void test01() {
    AbstractCaculator* caculator = new PlusCaculator;
    caculator->setOperatorNumber(10, 20);
    cout<<"ret："<<caculator->getResult()<<endl;

}

int main()
{
    test01();


    return 0;
}