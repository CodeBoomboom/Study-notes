参考视频网址：bilibili.com/video/BV1PW411t7Xg?spm_id_from=333.999.0.0&vd_source=49d77d31055b0b1a50f4a48825b3d51c



# 01函数模板

![image-20220704112607371](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704112607371.png)

![image-20220704112710179](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704112710179.png)

![image-20220704112723443](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704112723443.png)

![image-20220704112753014](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704112753014.png)

![image-20220704112803404](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704112803404.png)

# 02函数模板和普通函数的区别_函数模板调用规则

![image-20220704114056156](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704114056156.png)

![image-20220704114311753](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704114311753.png)

```cpp
template <class T>
void MyAdd(T a, T b)
{
    return a + b;
}


int MyAdd(int a, char c)
{
    return a + c;
}

void test02() {
    int a = 10;
    int b = 20;
    char c1 = 'a';
    char c2 = 'b';
    MyAdd(a, b);//调用函数模板
    MyAdd(a, c1);//调用普通函数
    MyAdd(c1, b);//调普通函数，因为普通函数可以自动类型转换
}
```

# 03 C编译过程概述

![image-20220704120125477](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704120125477.png)

# 04编译过程测试

![image-20220704142951062](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704142951062.png)

预编译，宏替换，头文件加载：

![image-20220704143009091](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704143009091.png)

编译，生成汇编代码：

![image-20220704143027904](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704143027904.png)

汇编，生成机器码：

![image-20220704143044997](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704143044997.png)

汇编+链接，生成可执行文件：

![image-20220704143100809](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704143100809.png)

# 05模板函数实现原理

![image-20220704143310092](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704143310092.png)

简单写一段代码：

![image-20220704143326497](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704143326497.png)

将代码进行编译后打开：

![image-20220704143341623](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704143341623.png)

可以看到，两个调用的函数不同

将代码改写一下，如下：

![image-20220704143404301](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704143404301.png)

再编译：

![image-20220704143422076](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704143422076.png)

如图，第一个和第三个调用函数是一样的。

![image-20220704143439754](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704143439754.png)

# 06类模板

```cpp
template<typename T>
class MyClass
{
public:
    MyClass(T id, T age)
    {
        this->mId = id;
        this->mAge = age;
    }

    void Show()
    {
        cout << "ID:" << mId << "age：" << mAge << endl;
    }

    T mId;
    T mAge;

private:

};

void test01()
{
    //函数模板在调用的时候可以自动类型推导
    //类模板必须显式指定类型
    MyClass<int> p(10, 20);
    p.Show();

}
```

# 07函数模板案例_char和int类型数组排序

```cpp
//对char类型和int类型数组进行排序
//打印函数
template<class T>
void PrintArray(T* arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//排序
template<class T>
void MySort(T* arr, int len)
{
    for (int i = 0;i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            //从大到小排序
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

    }
}

int main()
{
    int arr[] = {2,6,1,8,9,2};
    //数组长度
    int len = sizeof(arr) / sizeof(int);
    PrintArray(arr, len);
    MySort(arr, len);
    PrintArray(arr, len);

    char chArr[] = { 'a', 'c','d' };
    len = sizeof(chArr) / sizeof(char);
    PrintArray(chArr, len);
    MySort(chArr, len);
    PrintArray(chArr, len);
    return 0;
}
```

# 08类模板派生普通类_类模板派生类模板

类模板派生普通类

```cpp
template<class T>
class MyClass
{
public:
    MyClass()
    {
        mAge = 0;

    }
    ~MyClass() {
        default;
    }
    T mAge;
private:

};

//为什么<int>？
//类去定义对象，这个对象是不是需要编译分配内存
class MyClass01 :public MyClass<int> {

public:

private:

};
```

类模板派生类模板

```cpp
template<class T>
class Animal {
public:
    void Jiao() {
        cout << mAge << "岁动物在叫！" << endl;
    }
    T mAge;
};

//Cat也是模板，不实例化对象
template<class T>
class Cat : public Animal<T> {

};
```

# 09 类的写法.h和.cpp分离

.h写声明，.cpp写实现

```cpp
#pragma once	//防止头文件被重复包含
```

# 10类模板类内实现

```cpp
template<class T1, class T2>
class Person {
public:
    Person(T1 name, T2 age) {
        this->mAge = age;
        this->mName = name;
    }

    void Show()
    {
        cout << "name:" << mName << "age:" << mAge << endl;
    }
public: 
    T1 mName;
    T2 mAge;

};

void test01()
{
    Person<string, int> a("xdx", 23);
    a.Show();
}
```

# 11 上午课程回顾

![image-20220705144629894](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220705144629894.png)

# 12 类模板类外实现_模板类中使用友元2

```cpp
template<class T> class MyClass;
template<class T> void PrintAge(MyClass<T>& p);

template <class T>
class MyClass
{
public:
    MyClass(T age) {
        this->mAge = age;

    }
    ~MyClass() {

    }
    //template <class T>    //不建议这么写，在windows编译器可以通过，但在linux下不可以通过
    //friend void PrintAge(MyClass<T>& p);
    friend void PrintAge<T>(MyClass<T>& p);     //推荐这么写，类外声明，类内加<T>
    T mAge;

private:

};

template <class T>
void PrintAge(MyClass<T>& p) {
    cout << p.mAge << endl;
}

void test01() {
    MyClass<int> p(10);
    PrintAge(p);
}

int main()
{
    test01();

    system("pause");
    return 0;
}
```

# 13 类模板h和cpp分离编写分析

main:

![image-20220705151533793](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220705151533793.png)

Person.cpp：

![image-20220705151601054](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220705151601054.png)

![image-20220705151608414](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220705151608414.png)

报错原因，在main文件编译时，会让链接器去找函数的实现，完事儿函数去编译Person.cpp文件，但是在这个cpp文件里，它只会编译函数模板，因为没有具体实现，不会生成模板函数，导致main文件的调用失败。

# 14 类模板h和cpp分离编写解决方案

将include的Person.h改为Person.cpp

一般来说写类模板的时候，写成hpp文件

# 15 类模板碰到static成员

 ![image-20220705153957444](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220705153957444.png)

![image-20220705154004174](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220705154004174.png)

 

![img](file:///C:/Users/ADMINI~1/AppData/Local/Temp/msohtmlclip1/01/clip_image002.jpg)

![img](file:///C:/Users/ADMINI~1/AppData/Local/Temp/msohtmlclip1/01/clip_image004.jpg)

运行结果如下：

![img](file:///C:/Users/ADMINI~1/AppData/Local/Temp/msohtmlclip1/01/clip_image006.jpg)

所以，类模板中的静态成员，对于同一个模板类是共享的。

# 16 昨天课程回顾

略

# 17 MyArray框架搭建

```cpp
template<class T>
class MyArray {
public:
    MyArray(int capacity);
    MyArray(const MyArray& arr);
    T& operator[](int index);
    const T& operator[](int index) const;
    MyArray<T> operator=(const MyArray<T>& arr);
    void PushBack(T& data);
    void PushBack(T&& data);
public:
    //一共可以容下多少个元素
    int mCapacity;
    //当前数组有多少元素
    int mSize;
    //保存数据的首地址
    T* pAddr;
};
```



# 18 MyArray函数实现

```cpp
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

template<class T>
class MyArray {
public:
    MyArray(int capacity) {
        this->mCapacity = capacity;
        this->mSize = 0;
        //申请内存
        this->pAddr = new T[this->mCapacity];
    }
    MyArray(const MyArray& arr) {
        this->mCapacity = arr.mCapacity;
        this->mSize = arr.mSize;
        //申请内存空间
        this->pAddr = new T[this->mCapacity];
        for (int i = 0; i < this->mSize; i++) {
            this->pAddr[i] = arr.pAddr[i];
        }
    }
    T& operator[](int index) {
        return this->pAddr[index];
    }
    const T& operator[](int index) const {
        return this->pAddr[index];
    }
    MyArray<T> operator=(const MyArray<T>& arr) {
        if (this->pAddr != NULL) {
            delete[] this->pAddr;
        }
        this->mCapacity = arr.mCapacity;
        this->mSize = arr.mSize;
        //申请内存空间
        this->pAddr = new T[this->mCapacity];
        for (int i = 0; i < this->mSize; i++) {
            this->pAddr[i] = arr.pAddr[i];
        }
        return *this;
    }
    void PushBack(T& data) {
        //判断容器中是否有位置
        if (this->mSize >= this->mCapacity) {
            return;
        }

        //调用拷贝构造 =操作符
        //1.对象元素必须能够被拷贝
        //2.容器都是值寓意，而非引用寓意，向容器中放入元素都是放入元素的拷贝
        //3.如果元素的成员有指针，注意深拷贝和浅拷贝问题
        this->pAddr[this->mSize] = data;
        this->mSize++;
    }
#if 1
    void PushBack(T&& data) {
        //判断容器中是否有位置
        if (this->mSize >= this->mCapacity) {
            return;
        }

        this->pAddr[this->mSize] = data;
        this->mSize++;
    }
#endif
    ~MyArray() {
        if (this->pAddr != NULL) {
            delete[] this->pAddr;
        }
    }
public:
    //一共可以容下多少个元素
    int mCapacity;
    //当前数组有多少元素
    int mSize;
    //保存数据的首地址
    T* pAddr;
};


void test01() {
    MyArray<int> marray(20);
    int a = 10, b = 20, c = 30, d = 40;
    marray.PushBack(a);
    marray.PushBack(b);
    marray.PushBack(c);
    marray.PushBack(d);
    
    //不能对右值取引用，解决办法：#if 内容打开，右值引用
    //marray.PushBack(100);
    marray.PushBack(100);

    for (int i = 0; i < marray.mSize; i++) {
        cout << marray[i] << " ";
    }
    cout << endl;
}

int main()
{
    test01();
    return 0;
}
```

# 19 类型转换基本语法

![image-20220705180633354](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220705180633354.png)

![image-20220705180639625](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220705180639625.png)

![image-20220705180646238](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220705180646238.png)

## 20 类型转换static_cast和dynamic_cast

```cpp
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

    Animal aniobj;
    Animal& aniref = aniobj;
    Cat& cat = static_cast<Cat&>(aniref);

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
int main()
{
    test01();
    test02();


    return 0;
}
```

![image-20220705184531509](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220705184531509.png)

# 21 类型转换const_cast和reinterpret_cast

const_cast的作用是增加或去除变量的const性

```cpp
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
```

![image-20220706113358023](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220706113358023.png)

# 22 异常理论概念

![image-20220706151341214](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220706151341214.png)



![image-20220706151358454](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220706151358454.png)



![image-20220706151403087](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220706151403087.png)

![image-20220706151409390](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220706151409390.png)





# 23 异常基本语法

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//异常基本语法

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
```

![image-20220706154008615](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220706154008615.png)

# 24 上午课程回顾

略

# 25 栈解旋

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//栈解旋
class Person {
public:
    Person() {
        cout << "对象构建" << endl;
    }
    ~Person() {
        cout << "对象析构" << endl;
    }
};

int divide(int x, int y) {
    Person p1, p2;
    if (y == 0) {
        throw y;
    }
    return x / y;
}

void test01() {
    try {
        divide(10, 0); //栈解旋就是当发生异常时 ，发生异常的函数的局部变量的内存都会自动析构掉
    }
    catch (int e) {
        cout << "异常捕获" << endl;
    }
}
int main()
{
    test01();
    return 0;
}
```

# 26 异常接口声明

![image-20220706155239668](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220706155239668.png)



```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//这个函数只能抛出int float char三种类型的异常，抛出其他的异常会报错，中止程序
void func() throw(int, float, char) {
    throw "adv";//char*
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
```

# 27 异常类型

![image-20220706160625190](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220706160625190.png)



```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//异常类型

void func01() {
    throw 1;//抛出int类型异常
}

void func02() {
    throw "abc";//抛出char*类型异常
}

class MyException {
public:
    MyException(const char* str) {
        error = new char[strlen(str) + 1];
        strcpy(error, str);
    }
    //27解决办法：增加拷贝构造函数和=运算法重载
    MyException(const MyException& copy) {
        this->error = new char[strlen(copy.error) + 1];
        strcpy(this->error, copy.error);
    }
    MyException& operator=(const MyException& copy) {
        if (this->error != NULL) {
            delete[] this->error;
            this->error = NULL;
        }
        this->error = new char[strlen(copy.error) + 1];
        strcpy(this->error, copy.error);
    }

    void what() {
        cout << error << endl;
    }
    ~MyException() {
        if (error != NULL) {
            delete[] error;
        }
    }
public:
    char* error;
};

void func03() {
    throw MyException("我刚写的异常");
}

void test01() {
    try {
        func01();
    }
    catch (int e) {
        cout << "捕获int异常" << e << endl;
    }

    try {
        func02();
    }
    catch (const char* e) {
        cout << "捕获char*异常" << e << endl;
    }

    try {
        func03();
    }
    catch (MyException e) {//27 会崩，原因：throw的匿名对象会拷贝给此处的e，这两个的error指针都指向同一块内存空间，而我们又没写拷贝构造函数，所以析构的时候同一内存空间会析构两次
        cout << "捕获MyException异常" << endl;
        e.what();
    }

}


int main()
{
    test01();
    return 0;
}
```

# 28 异常对象生命周期

![image-20220706170928719](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220706170928719.png)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyException {
public:
    MyException() {
        cout << "构造函数" << endl;
    }

    MyException(const MyException& copy) {
        cout << "拷贝构造" << endl;
    }
    MyException(const MyException&& copy) {
        cout << "拷贝构造" << endl;
    }
    ~MyException() {
        cout << "析构函数" << endl;
        }
};
void func01() {
    throw MyException();    //创建匿名对象 调用构造
}

void func02() {
    MyException err = MyException();
    throw& err;
    //throw &(MyException());    //创建匿名对象 调用构造    //匿名对象是右值无法取引用，不知道视频是怎么可以的
}

void func03() {
    throw new MyException();
}

void test01() {

    //普通元素类型  引用  指针  

    //普通元素类型 catch处理完之后就析构
    try {
        func01();
    }
    catch (MyException e) { //调用拷贝构造
        cout << "异常捕获" << endl;
    }

    //引用类型 不用调用拷贝构造，catch处理完就析构
    try {
        func01();
    }
    catch (MyException& e) { //不会再调用任何构造
        cout << "异常捕获" << endl;
    }

    //指针类型 在catch前就已经析构了，就不能在catch里调用MyException对象的方法等进行处理了
    try {
        func02();
    }
    catch (MyException* e) { 
        cout << "异常捕获" << endl;
    }

    //指针类型 如果想在catch里调用MyException对象的方法等进行处理，需要这么做：
    try {
        func03();
    }
    catch (MyException* e) {
        cout << "异常捕获" << endl;
        delete e;//手动释放
    }
}

int main()
{
    test01();


    return 0;
}
```

# 29 C标准异常类使用举例_编写自己的异常类

![image-20220706170955393](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220706170955393.png)

![image-20220706171002642](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220706171002642.png)

![image-20220706171008480](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220706171008480.png)



最重要的两点：

1.继承标准异常类

2.重载父类的what函数和虚析构函数

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<exception>
#include<stdexcept>
using namespace std;
//编写自己的异常类

class Person {
public:
    Person() {
        mAge = 0;
    }
    void setAge(int age) {
        if (age < 0 || age >100) {
            throw out_of_range("年龄应该在0-100之间！");
        }
        this->mAge = age;
    }
public:
    int mAge;
};

void test01() {
    Person p;
    //try {
    //    p.setAge(1000);
    //}
    //catch (out_of_range e) {
    //    cout << e.what() << endl;
    //}
    try {
        p.setAge(1000);
    }
    catch (exception e) {
        cout << e.what() << endl;
    }
}


class MyOutOfRange : public exception {
public:
    MyOutOfRange(const char* error) {
        pError = new char[strlen(error) + 1];
        strcpy(pError, error);
    }
    ~MyOutOfRange() {
        if (pError != NULL) {
            delete[] pError;
        }
    }
    virtual char const* what() const {
        return pError;
    }
public:
    char* pError;

};

void func02() {
    throw MyOutOfRange("我自己的out_of_range");
}

void test02() {
    try {
       func02();
    }
    catch (exception& e) {  //没写拷贝构造，所以不使用普通类型来接异常，使用引用接
        cout << e.what() << endl;
    }
}

int main()
{
    test01();
    test02();
    return 0;
}
```

# 30 继承在异常中的应用

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//继承在异常中的应用

//异常基类
class BaseMyException {
public:
    virtual void what() = 0;
    virtual ~BaseMyException(){}
};

class TargetSpaceNullException :public BaseMyException {
public:
    virtual void what() {
        cout << "目标空间空" << endl;
    }
    ~TargetSpaceNullException() {

    }
};

class SourceSpaceNullException :public BaseMyException {
public:
    virtual void what() {
        cout << "源空间为空" << endl;
    }
    ~SourceSpaceNullException() {

    }
};


void copy_str(char* target, const char* source) {
    if (target == NULL) {
        throw TargetSpaceNullException();
    }

    if (source == NULL) {
        throw SourceSpaceNullException();
    }
    int len = strlen(source) + 1;
    while (*source != '\0') {
        *target = *source;
        target++;
        source++;
    }

}



int main()
{
    const char* source = "abcdefg";
    char buf[1024] = {0};
    try {
        copy_str(NULL, source);
    }
    catch (BaseMyException& e) {
        e.what();
    }

    try {
        copy_str(buf, NULL);
    }
    catch (BaseMyException& e) {
        e.what();
    }


    try {
        copy_str(buf, source);
    }
    catch (BaseMyException& e) {
        e.what();
    }

    cout << buf << endl;


    return 0;
}
```

# 31 C输入和输出流_缓冲区

![image-20220706180706517](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220706180706517.png)

![image-20220706180711775](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220706180711775.png)



![image-20220706180716754](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220706180716754.png)









































































