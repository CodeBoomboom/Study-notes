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


//仿函数：重载了函数调用符号的类
class mycompare {
public:
    bool operator()(int v1, int v2) const {
        return v1 > v2;
    }
};


//初始化
void test01() {
    set<int> s1;    //自动排序，默认从小到大，如何实现从大到小？仿函数，见下面的s3
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

    mycompare com;
    com(10, 20);

    set<int, mycompare> s3;    //利用仿函数排序：从大到小
    s3.insert(7);
    s3.insert(2);
    s3.insert(4);
    s3.insert(5);
    s3.insert(1);
    for (set<int>::iterator it = s3.begin(); it != s3.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
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

class Person
{
public:
    Person(int id, int age):id(id), age(age){}
public:
    int id;
    int age;

private:

};

class mycompare2 {
public:
    bool operator()(const Person& p1, const Person& p2)const{
        return p1.age > p2.age;
    }
};

void test03() {
    //set<Person> sp; //set需要排序，当你放对象，set不知道怎么排序，所以需要指定
    set<Person,mycompare2> sp;
    Person p1(10, 20), p2(20, 30), p3(30, 40);

    sp.insert(p1);
    sp.insert(p2);
    sp.insert(p3);

    Person p4(10, 30);

    for (set<Person, mycompare2>::iterator it = sp.begin(); it != sp.end(); it++) {
        cout << (*it).age << " " << (*it).id << endl;
    }

    //查找
    set<Person, mycompare2>::iterator ret = sp.find(p4);    //只会根据Person的age属性进行查找，不管到底有没有
    if (ret == sp.end()) {
        cout << "没找到" << endl;
    }
    else {
        cout << "找到" << (*ret).id << " " << (*ret).age << endl;
    }

}

int main()
{
    //test01();
    //test02();
    test03();
    system("pause");
    return 0;
}