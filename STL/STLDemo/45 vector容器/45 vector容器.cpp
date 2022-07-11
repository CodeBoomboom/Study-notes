#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int>& v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

//初始化
void test01() {
    vector<int> v1;//默认无参构造

    
    int arr[] = { 2,3,4,1,9 };
    vector<int> v2(arr, arr + sizeof(arr)/sizeof(int));

    vector<int> v3(v2.begin(), v2.end());

    vector<int> v4(v3);

    printVector(v2);
    printVector(v3);
    printVector(v4);
}

//赋值操作
void test02() {
    int arr[] = { 2,3,4,1,9 };
    vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));
    //成员方法
    vector<int> v2;
    v2.assign(v1.begin(), v1.end());
    //=
    vector<int> v3 = v2;

    int arr1[] = { 100,200,300,400,500 };
    vector<int> v4(arr1, arr1 + sizeof(arr1) / sizeof(int));
    v4.swap(v1);

    printVector(v1);
    printVector(v2);
    printVector(v3);
    printVector(v4);
}

//大小操作
void test03() {
    int arr[] = { 2,3,4,1,9 };
    vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

    cout << "size:" << v1.size() << endl;
    if (v1.empty()) {
        cout << "v1 空" << endl;
    }
    else {
        cout << "v1 不空" << endl;
    }

    printVector(v1);
    v1.resize(2);//如果resize的值比原来的小，会把后面的扔掉
    printVector(v1);
    //v1.resize(6);//如果resize的值比原来的大，会把后面添加默认值
    printVector(v1);
    v1.resize(6, 1);//指定默认值为1
    printVector(v1);

    for (int i = 0; i < 100;  i++) {
        v1.push_back(i);
    }
    cout << "size:" << v1.size() << endl;
    cout << "capacity:" << v1.capacity() << endl;
}

//vector存取数据
void test04() {
    int arr[] = { 2,3,4,1,9 };
    vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));

    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < v1.size(); i++) {
        cout << v1.at(i) << " ";
    }
    cout << endl;

    //区别：at抛异常  []不抛异常

    //数据存取操作
    cout << "front:" << v1.front() << endl;
    cout << "back:" << v1.back() << endl;

}

//插入和删除
void test05() {
    //insert的位置是用迭代器标识的
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    printVector(v);

    //头插法
    v.insert(v.begin(), 30);
    printVector(v);
    //尾插法
    v.insert(v.end(), 40);
    printVector(v);
    //中间插
    v.insert(v.begin() + 2, 100);//vector支持随机访问  容器支持[]的一般都支持随机访问  迭代器可以直接+2 +3 -5
    printVector(v);

    //删除
    v.erase(v.begin());
    printVector(v);
    v.erase(v.begin() + 1, v.end());
    printVector(v);
    v.clear();

}

//巧用swap缩减空间
void test06() {
    //vector添加元素 会自动增长
    //删除元素 不会自动缩减
    vector<int> v;
    for (int i = 0; i < 100; i++) {
        v.push_back(i);
    }
    cout << "size:" << v.size() << endl;
    cout << "capacity:" << v.capacity() << endl;
    v.resize(10);
    cout << "size:" << v.size() << endl;
    cout << "capacity:" << v.capacity() << endl;

    //利用swap收缩空间
    vector<int>(v).swap(v);//vector<int>(v) 通过v创建一个匿名对象 然后与v进行交换 匿名对象用完销毁
    cout << "size:" << v.size() << endl;
    cout << "capacity:" << v.capacity() << endl;
}

//reserve和resize区别
void test07() {
    //reserve 预留空间 resize 区别

    int num = 0;
    int* address = NULL;

    vector<int> v;
    v.reserve(10000);
    for (int i = 0; i < 10000; i++) {
        v.push_back(i);
        if (address != &v[0]) {
            address = &v[0];
            num++;
        }
    }
    cout << "num:" << num << endl;
    //如果你知道数据大概要存储的个数，可以用reserve预留空间

}

int main()
{
    //test01();
    //test02();
    //test03();
    //test04();
    //test05();
    //test06();
    test07();
    system("pause");
    return 0;
}