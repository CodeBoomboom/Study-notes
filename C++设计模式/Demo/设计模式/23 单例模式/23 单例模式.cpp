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
    Singleton_lazzy() { cout << "我是懒汉构造" << endl; }
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
#if 0   //这样写不行，任何人都能调这个函数
    static void freeSpace() {
        if (pSigleton != NULL) {
            delete pSigleton;
        }
    }
#endif
    class Garbo {
        ~Garbo() {
            if (pSigleton != NULL) {
                delete pSigleton;
            }
        }
    };
private:
    static Singleton_hungry* pSigleton;
    static Garbo garbo;

};
//类外初始化
Singleton_hungry* Singleton_hungry::pSigleton = new Singleton_hungry;


void test01() {
    Singleton_lazzy* p1 = Singleton_lazzy::getInstance();
    Singleton_lazzy* p2 = Singleton_lazzy::getInstance();
    if (p1 == p2) {
        cout << "懒汉式两个指针指向同一块内存，是单例模式" << endl;
    }
    else {
        cout << "不是单例模式" << endl;
    }

    Singleton_hungry* p3 = Singleton_hungry::getInstance();
    Singleton_hungry* p4 = Singleton_hungry::getInstance();
    if (p3 == p4) {
        cout << "饿汉式两个指针指向同一块内存，是单例模式" << endl;
    }
    else {
        cout << "不是单例模式" << endl;
    }
}

//释放
void test02() {
    //Singleton_hungry::freeSpace();//这样写不行，任何人都能调这个函数

    //实际上单例模式只能创造出一个对象，不会出现内存溢出的风险
    //在整个程序结束时类的静态对象会自动调用析构函数进行析构，所以不用担心释放的问题

    //如果非要释放，可以写个垃圾工人Garbo嵌套类，放在单例类中
    //程序结束后，会调用Garbo析构函数析构，进而把静态对象释放
}



int main(){
    cout << "main函数开始执行" << endl;
    test01();
    //A::getInstace();
    return 0;
}