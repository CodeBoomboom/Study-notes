#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
using namespace std;
//标准输出流


void test01() {
    //cout << "hello world";
    //cout.flush();//刷新缓冲区
    cout.put('h').put('e').put('l') << endl;    //put向缓冲区写字符

    cout.write("hello xdx",strlen("hello xdx"))<<endl;
}

//格式化输出
void test02() {
    //成员方法的方式
    int num = 10;
    cout << num << endl;
    cout.unsetf(ios::dec);//卸载当前默认的10进制输出方式
    cout.setf(ios::oct);//设置为八进制输出
    cout.setf(ios::showbase);
    cout << num << endl;
    cout.unsetf(ios::oct);//卸载八进制
    cout.setf(ios::hex);//16进制
    cout << num << endl;

    cout.width(10);//设置位宽
    cout.fill('*');//空余部分用*填充
    cout.setf(ios::left);//左对齐
    cout << num << endl;

    //通过控制符  需要引入头文件iomanip
    int num2 = 10;
    cout << hex
        << setiosflags(ios::showbase)
        << setw(10)
        <<setfill('~')
        <<setiosflags(ios::left)
        << num2
        << endl;

}

int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}