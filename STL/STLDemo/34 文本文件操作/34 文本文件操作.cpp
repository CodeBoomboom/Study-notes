#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
using namespace std;

void test01() {
    const char* sourcename = "G:\\Git\\GitProject\\Study-notes\\STL\\STLDemo\\34 文本文件操作\\source.txt";
    const char* targetname = "G:\\Git\\GitProject\\Study-notes\\STL\\STLDemo\\34 文本文件操作\\target.txt";
    ifstream ism(sourcename, ios::in);    //只读方式打开文件  有参构造
    ofstream osm(targetname, ios::out);
    //ofstream osm(targetname, ios::out | ios::app);
    //ifstream isml;
    //isml.open(filename, ios::in);
    if (!ism) {
        cout << "打开文件失败" << endl;
        return;
    }

    //读文件
    char ch;
    while (ism.get(ch)) {
        cout << ch;
        osm.put(ch);
    }

    //关闭文件
    ism.close();
    osm.close();

}

//二进制文件操作  对象序列化
class Person {
public:
    Person(){}
    Person(int age, int id): age(age), id(id){}
    void Show() {
        cout << "age:" << age << "id:" << id << endl;
    }
public:
    int age; 
    int id;
};

void test02() {
    //文本模式读的是文本文件吗
    //二进制模式读的是二进制文件吗
    //都不是，都是二进制，只是换行符不一样，windows是\r\n，linux是\n

    Person p1(10, 20);  //二进制
    Person p2(30, 40);

    //把p1 p2 放到文件
    const char* targetname = "G:\\Git\\GitProject\\Study-notes\\STL\\STLDemo\\34 文本文件操作\\class.txt";
    ofstream osm(targetname, ios::out | ios::binary);//二进制的方式
    osm.write((char *)&p1, sizeof(Person));//二进制方式写文件
    osm.write((char*)&p2, sizeof(Person));

    osm.close();

    ifstream ism(targetname, ios::in | ios::binary);
    Person p3, p4;
    ism.read((char*)&p3, sizeof(Person));//从文件读取数据
    ism.read((char*)&p4, sizeof(Person));
    p3.Show();
    p4.Show();

}

int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}