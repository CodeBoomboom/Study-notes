#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//实现单例的步骤
//1.构造函数私有化
//2.增加静态私有的当前类的指针变量
//3.提供静态对外接口，可以让用户获得单例对象
class A {
private:
    A(){
        a = new A;
    }

public:
    static A* getInstace() {
        return a;
    }
private:
    static A* a;
};
A* A::a = NULL;


//单例分为懒汉式、饿汉式

//懒汉式：只有在调用getInstance的时候才会new一个对象出来
class Singleton_lazzy
{
private:
	Singleton_lazzy(){}
public:
    static Singleton_lazzy* getInstance() {
        if (pSigleton == NULL) {
            pSigleton = new Singleton_lazzy;
        }
        return pSigleton;
    }

private:
    static Singleton_lazzy* pSigleton;

};
//类外初始化
Singleton_lazzy* Singleton_lazzy::pSigleton = NULL;

//饿汉式：在main函数开始执行前就已经创造好了
class Singleton_hungry
{
private:
    Singleton_hungry() { cout << "我是饿汉构造" << endl; }
public:
    static Singleton_hungry* getInstance() {
        return pSigleton;
    }

private:
    static Singleton_hungry* pSigleton;

};
//类外初始化
Singleton_hungry* Singleton_hungry::pSigleton = new Singleton_hungry;


int main(){
    cout << "main函数开始执行" << endl;
    //A::getInstace();
    return 0;
}