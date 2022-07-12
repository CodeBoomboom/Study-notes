#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>
using namespace std;

void PrintSet(set<int>& s) {
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

//初始化
void test01() {
    set<int> s1;    //自动排序，默认从小到大
    s1.insert(7);
    s1.insert(2);
    s1.insert(4);
    s1.insert(5);
    s1.insert(1);
    PrintSet(s1);
    
    //赋值操作
    set<int> s2;
    s2 = s1;
    s2.swap(s1);

    if (!s1.empty()) cout << "size:"<< s1.size() << endl;

    //删除
    s1.erase(s1.begin());
    s1.erase(7);
    PrintSet(s1);

}

//set 查找 
void test02() {
    //实际的值(set键值一样)
    set<int> s1; 
    s1.insert(7);
    s1.insert(2);
    s1.insert(4);
    s1.insert(5);
    s1.insert(1);

    set<int>::iterator ret = s1.find(4);//找到返回迭代器，否则返回end迭代器
    if (ret == s1.end()) {
        cout << "没找到" << endl;
    }
    else {
        cout << "找到了：" << *ret << endl;
    }
    
    ret = s1.lower_bound(2);//返回第一个大于等于2的元素的迭代器
    if (ret == s1.end()) {
        cout << "没找到" << endl;
    }
    else {
        cout << "找到了：" << *ret << endl;
    }

    ret = s1.upper_bound(2);//返回第一个大于2的元素的迭代器
    if (ret == s1.end()) {
        cout << "没找到" << endl;
    }
    else {
        cout << "找到了：" << *ret << endl;
    }

    pair<set<int>::iterator, set<int>::iterator> p = s1.equal_range(2);//返回lower_bound(2)和upper_bound(2)的值
    if (p.first == s1.end()) {
        cout << "没找到" << endl;
    }
    else {
        cout << "找到了p.first：" << *p.first << endl;
    }

    if (p.second == s1.end()) {
        cout << "没找到" << endl;
    }
    else {
        cout << "找到了p.second：" << *p.second << endl;
    }
}


int main()
{
    //test01();
    test02();
    system("pause");
    return 0;
}