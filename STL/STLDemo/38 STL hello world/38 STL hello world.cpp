#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>   //��̬���� �ɱ�����
#include<algorithm>//�㷨
using namespace std;

void PrintVector(int v) {
    cout << v << endl;
}

//STL�����﷨
void test01() {
    vector<int> v;//����һ��������ָ����ŵ�Ԫ��������int

    v.push_back(10);//�����ݷ�������β��
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    //ͨ��STL�ṩ��for_each�㷨����
    //�����ṩ�ĵ�����

    vector<int>::iterator pBegin = v.begin();
    vector<int>::iterator pEnd = v.end();

    //�����п��ܴ�Ż������������ͣ�Ҳ���ܴ���Զ����������ͣ�ÿ�ε��ûص���������ӡ
    for_each(pBegin, pEnd, PrintVector);

}

//����Ҳ���Դ���Զ�����������
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

    //����
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