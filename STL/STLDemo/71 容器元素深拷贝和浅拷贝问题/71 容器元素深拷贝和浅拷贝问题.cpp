#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

class Person
{
public:
    Person(const char* name, int age) {
        this->pName = new char[strlen(name) + 1];
        strcpy(this->pName, name);
        this->mAge = age;
    }
    Person(const Person& p) {
        this->pName = new char[strlen(p.pName) + 1];
        strcpy(this->pName, p.pName);
        this->mAge = p.mAge;
    }
    Person& operator=(const Person& p) {
        if (this->pName != NULL) {
            delete[] this->pName;
        }
        this->pName = new char[strlen(p.pName) + 1];
        strcpy(this->pName, p.pName);
        this->mAge = p.mAge;
        return *this;
    }

    ~Person() {
        if (this->pName != NULL) {
            delete[] this->pName;
        }
    }

private:
    int mAge;
    char* pName;//指针 容易出现浅拷贝问题
};


void test01() {
    Person p("aaa", 20);
    vector<Person> vPerson;
    //vPerson.push_back(p);       //出现浅拷贝问题，test01()结束时p析构，但是p push到vector中时是通过浅拷贝进行的（两个指针就指向一块内存空间）也会进行析构，两次析构就会出异常，，所以要增加拷贝构造
    vPerson.push_back(p);
}

int main()
{
    test01();
    system("pause");
    return 0;
}