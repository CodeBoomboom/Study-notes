#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include <stack>
using namespace std;


void test01() {
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "队尾：" << q.back() << endl;
    cout << "大小：" << q.size() << endl;
    //输出顺序 10 20 30 40
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

}

class Person
{
public:
    Person() {}
    Person(string name, int scorce) :mName(name), mScorce(scorce) {}
    void show() {
        cout << "id" << mName << "  ";
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
    while (!p.empty()) {
        p.top().show();
        p.pop();
    }
}

void ShowQueue(queue<Person*>& p) {
    while (!p.empty()) {
        (*(p.front())).show();
        p.pop();
    }
}

//作业：队列容器存放对象指针
void test02() {
    Person* p1 = new Person("A", 10);
    Person* p2 = new Person("B", 20);
    Person* p3 = new Person("C", 30);

    queue<Person*> q;
    q.push(p1);
    q.push(p2);
    q.push(p3);
    ShowQueue(q);
}

//作业：队列容器存放stack容器
void test03() {
    stack<Person> s1;
    stack<Person> s2;
    stack<Person> s3;
    CreatePerson(s1);
    CreatePerson(s2);
    Person p;
    p.mName = "XDX";
    p.mScorce = 100;
    s3.push(p);
    Person p1;
    p1.mName = "XDX1";
    p1.mScorce = 100;
    s3.push(p1);

    queue<stack<Person>> q;
    q.push(s1);
    q.push(s2);
    q.push(s3);

    while (!q.empty()) {
        ShowStack(q.front());
        q.pop();
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