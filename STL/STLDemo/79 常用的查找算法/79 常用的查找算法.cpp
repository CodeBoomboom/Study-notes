#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//find(iterator beg, iterator end, value)  寻找容器中value值的元素，返回其迭代器
//基本数据类型
void test01() {
    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }

    vector<int>::iterator ret = find(v1.begin(), v1.end(), 5);
    if (ret != v1.end()) {
        cout << "找到了：" << *ret<<endl;
    }
    else {
        cout << "没找到" << endl;
    }
}
//对象  需要在对象类中重载一个bool类型==
class Person {
public:
    Person(int age, int id) :age(age), id(id) {}
    bool operator==(const Person& p) const {
        return p.id == this->id && p.age == this->age;
    }
    ~Person() {}
    void show() {
        cout << "age：" << age << "id：" << id << endl;
    }
public:
    int age;
    int id;
};
void test02() {
    vector<Person> v1;
    Person p1(10, 20), p2(20, 30);
    v1.push_back(p1);
    v1.push_back(p2);

    vector<Person>::iterator  ret = find(v1.begin(), v1.end(), p1);
    if (ret != v1.end()) {
        cout << "找到了"<< endl;
    }
    else {
        cout << "没找到" << endl;
    }
}

//binary_search(iterator beg, iterator end, value);  二分查找，在无序序列中不可用，查找成功返回true 失败false
void test03() {
    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }

    bool ret = binary_search(v1.begin(), v1.end(), 5);
    if (ret) {
        cout << "找到了" << endl;
    }
    else {
        cout << "没找到" << endl;
    }
}

//adjacent_find(iterator beg, iterator end, _callback);  查找相邻重复元素 返回相邻元素的第一个位置的迭代器
void test04() {
    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    v1.push_back(9);

    vector<int>::iterator ret = adjacent_find(v1.begin(), v1.end());
    if (ret != v1.end()) {
        cout << "找到了相邻重复元素：" << *ret << endl;
    }
    else {
        cout << "没找到相邻重复元素" << endl;
    }
}

//find_if(iterator beg, iterator end, _callback);    find_if会根据我们的条件（函数），返回第一个满足条件的元素的迭代器 _callback回调函数或谓词 
bool MySearch(int val){
    return val > 5;
}
void test05() {
    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }

    vector<int>::iterator ret = find_if(v1.begin(), v1.end(), MySearch);
    if (ret != v1.end()) {
        cout << "找到了：" <<*ret << endl;
    }
    else {
        cout << "没找到" << endl;
    }
}

//count 统计元素出现次数 count_if   count_if会根据我们的条件（函数），返回满足条件的元素的个数
bool MySearch2(int val) {
    return val > 5;
}
void test06() {
    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    v1.push_back(9);

    int num = count(v1.begin(), v1.end(), 9);
    cout << "9出现的次数：" << num << endl;

    int num1 = count_if(v1.begin(), v1.end(), MySearch2);
    cout << "大于5的个数：" << num1 << endl;

}

int main()
{
    //test01();
    //test02();
    //test03();
    //test04();
    //test05();
    test06();
    system("pause");
    return 0;
}