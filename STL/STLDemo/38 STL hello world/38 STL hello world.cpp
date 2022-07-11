#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>   //动态数组 可变数组
#include<algorithm>//算法
using namespace std;

void PrintVector(int v) {
    cout << v << endl;
}

//STL基本语法
void test01() {
    vector<int> v;//定义一个容器并指定存放的元素类型是int

    v.push_back(10);//把数据放在容器尾部
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    //通过STL提供的for_each算法遍历
    //容器提供的迭代器

    vector<int>::iterator pBegin = v.begin();
    vector<int>::iterator pEnd = v.end();

    //容器中可能存放基础的数据类型，也可能存放自定义数据类型，每次调用回调函数来打印
    for_each(pBegin, pEnd, PrintVector);

}

//容器也可以存放自定义数据类型
class Person {
public:
    Person(int age, int id) : age(age), id(id) {}
    void Show() {
        cout << "age:" << age << "id:" << id << endl;
    }
public:
    int age;
    int id;
};

void PrintPerson(Person p) {
    p.Show();
}

void test02() {
    vector<Person> v;
    Person p1(10, 20), p2(20, 30);
    
    v.push_back(p1);
    v.push_back(p2);

    vector<Person>::iterator pBegin = v.begin();
    vector<Person>::iterator pEnd = v.end();
    for_each(pBegin, pEnd, PrintPerson);

    //遍历
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
        cout << (*it).age << (*it).id << endl;
    }

}


int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}