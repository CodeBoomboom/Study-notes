#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

class Buliding{};
class Animal{};
class Cat : public Animal {};

//static_cast  用于内置的数据类型或者具有继承关系的指针或者引用
void test01() {
    //基础类型转换
    int a = 51;
    char c = static_cast<char>(a);
    cout << "a:" << a << endl;
    cout << "c:" << c << endl;

    //基础数据i类型指针
    //int* p = NULL;
    //char* sp = static_cast<char*>(p);

    //对象指针
    //Buliding* building = NULL;
    //Animal* animal = static_cast<Animal*>(building);

    //转换具有继承关系的指针
    //父类指针转成子类指针
    Animal* ani = NULL;
    Cat* cat = static_cast<Cat*>(ani);

    //转换具有继承关系的指针
    //子类指针转成父类指针
    Cat* soncat = NULL;
    Animal* anifather = static_cast<Animal*>(soncat);

    //父类引用转为子类引用
    Animal aniobj;
    Animal& aniref = aniobj;
    Cat& cat1 = static_cast<Cat&>(aniref);

    Cat catobj;
    Cat& catrief = catobj;
    Animal& anifather2 = static_cast<Animal &>(catrief);

    //结论：static_cast用于内置的数据类型或者具有继承关系的指针或者引用
}

//dynamic_cast  转换具有继承关系的指针或者引用，在转换前会进行队形类型的检查
void test02() {
    //基础类型转换
    //int a = 51;
    //char c = dynamic_cast<char>(a);
    //cout << "a:" << a << endl;
    //cout << "c:" << c << endl;

    //基础数据类型指针
    //int* p = NULL;
    //char* sp = dynamic_cast<char*>(p);

    //非继承关系的指针或者引用
    //Animal* ani = NULL;
    //Buliding* building = dynamic_cast<Building*>(ani);

    //具有继承关系的指针
    //Animal* ani = NULL;
    //Cat* cat = dynamic_cast<Cat*>(ani);   //失败原因：dynamic_cast会进行类型检查，父类不能转换为子类指针（小转大不安全）

    Cat* cat = NULL;
    Animal* ani = dynamic_cast<Animal*>(cat);//成功：子类转为父类，大转小安全

    //结论：dynamic只能转换具有继承关系的指针或者引用，并且只能由子类型转为基类型
}

//const_cast    指针、引用、对象指针  取消/增加const属性
void test03() {
    //引用
    int a = 10;
    const int& b = a;
    int & c = const_cast<int&>(b);
    c = 20;
    cout << "a:" << a << endl;  
    cout << "b:" << b << endl;
    cout << "c:" << c << endl;

    //指针
    int pp = 0;
    const int* p = &pp;
    int* p2 = const_cast<int*>(p);
    if (p2) {
        *p2 = 10;
    }
    cout << *p2 << endl;


    int* p3 = NULL;
    const int* p4 = const_cast<const int*>(p3);

    //总结：增加或者去除变量的const属性
}

//reinterpret_cast 强制类型转换  无关的指针类型都可以进行转换 包括函数指针
typedef void(*FUNC1)(int, int);
typedef int(*FUNC2)(int, char*);
void test04() {
    //1.无关的指针类型都可以进行转换
    Buliding* buliding = NULL;
    Animal* animal = reinterpret_cast<Animal*>(buliding);

    //2.函数指针转换
    FUNC1 func1;
    FUNC2 func2 = reinterpret_cast<FUNC2>(func1);

}


int main()
{
    cout << "test01:" << endl;;
    test01();
    cout << "test02:" << endl;
    test02();
    cout << "test03:" << endl;
    test03();
    cout << "test04:" << endl;
    test04();

    return 0;
}