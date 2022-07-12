#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
using namespace std;

void test01() {
    //初始化
    stack<int> s1;
    stack<int> s2(s1);

    //stack操作
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(100);
    cout << "栈顶元素：" << s1.top() << endl;
    s1.pop();
    cout << "栈顶元素：" << s1.top() << endl;

    //打印stack容器的数据
    while (!s1.empty()) {
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;
    cout << "size:" << s1.size() << endl;
}

class Person
{
public:
    Person() {}
    Person(string name, int scorce):mName(name),mScorce(scorce){}
    void show() {
        cout << "id" << mName << endl;
        cout << "scorce" << mScorce << endl;
    }

public:
    string mName;
    int mScorce;
};

void CreatePerson(stack<Person>& persons) {
    string s("ABCDE");
    for (int i = 0; i < 5; i++) {
        Person p;
        p.mName = "选手";
        p.mName += s[i];
        p.mScorce = 0;

        persons.push(p);
    }
}

void ShowStack(stack<Person>& p) {
    while(!p.empty()) {
        p.top().show();
        p.pop();
    }
}


//作业：stack存放对象
void test02() {
    stack<Person> p;
    CreatePerson(p);
    ShowStack(p);
}

void ShowStack(stack<Person*>& p) {
    while (!p.empty()) {
        (*(p.top())).show();
        p.pop();
    }
}
//作业：stack存放对象指针
void test03() {
    Person* p1 = new Person("A", 10);
    Person* p2 = new Person("B", 20);
    Person* p3 = new Person("C", 30);

    stack<Person*> p;
    p.push(p1);
    p.push(p2);
    p.push(p3);
    ShowStack(p);
}

int main()
{
    //test01();
    //test02();
    test03();
    system("pause");
    return 0;
}