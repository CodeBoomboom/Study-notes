#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>
using namespace std;

void printDeque(deque<int>& d) {
    for (deque<int>::iterator it = d.begin(); it != d.end(); it++) {
        cout << *it ;
    }
    cout << endl;
}

//初始化
void test01() {
    deque<int> d1;
    deque<int> d2(10, 5);//10个5
    deque<int> d3(d2.begin(), d2.end());
    deque<int> d4(d3);
    printDeque(d4);
}

//赋值及大小操作
void test02() {
    deque<int> d1;
    d1.assign(10, 5);//10个5
    deque<int> d2;
    d2.assign(d1.begin(), d1.end());//迭代器指定区间赋值
    deque<int> d3;
    d3 = d2;//等号赋值

    d1.swap(d2);
    if (d1.empty()) {
        cout << "d1 空" << endl;
    }
    else {
        cout << "size:" << d1.size() << endl;
    }

    d1.resize(5);//后5个扔掉
}

//deque容器的插入和删除
void test03() {
    deque<int> d1;
    d1.push_back(100);
    d1.push_front(200);
    d1.push_back(300);
    d1.push_back(400);
    d1.push_front(500);
    //500 200 100 300 400 
    printDeque(d1);

    int val = d1.front();//拿到被删除的数据
    d1.pop_front();
    printDeque(d1);

    val = d1.back();//拿到被删除的数据
    d1.pop_back();
    printDeque(d1);


}

int main()
{
    //test01();
    //test02();
    test03();
    system("pause");
    return 0;
}