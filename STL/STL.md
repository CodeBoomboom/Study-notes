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

