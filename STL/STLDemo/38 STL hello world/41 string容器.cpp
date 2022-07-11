#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//初始化
void test01() {
    string s1;  //无参构造
    string s2(10, 'a');
    string s3("xdx");
    string s4(s3);  //拷贝构造
}

//赋值操作
void test02() {
    string s1;
    string s2("xdx");
    s1 = "xdx1";
    cout << s1 << endl;
    s1 = s2;
    cout << s1 << endl;
    s1 = 'x';
    cout << s1 << endl;

    //成员方法
    s1.assign("jkl");
    cout << s1 << endl;
}


//赋值操作
void test03() {
    string s1 = "xedx";

    //重载[]操作符
    for (int i = 0; i < s1.size(); i++) {
        cout << s1[i]<<" ";
    }
    cout << endl;

    //at成员函数
    for (int i = 0; i < s1.size(); i++) {
        cout << s1.at(i)<<" ";
    }
    cout << endl;

    //区别：[]方式如果访问越界，直接挂了
                 //at方式会抛出异常，out of range
    try
    {
        //cout << s1[100]<<endl;
        cout << s1.at(100) << endl;
    }
    catch (...)
    {
        cout << "越界" << endl;
    	
    }
}

//拼接操作
void test04() {
    string s = "abcde";
    s += "ads";
    string s2 = "11";
    s += s2;
    cout << s << endl;

    string s3 = "22222";
    s.append(s3);
    cout << s << endl;

    string s4 = s2 + s3;
    cout << s4 << endl;
}


//查找
void test05() {
    string s = "abcdefghjfgkl";
    //第一次
    int pos = s.find('fg');
    cout <<"pos:"<< pos << endl;

    //最后一次
    pos = s.rfind('fg');
    cout << "pos:" << pos << endl;
}

//替换
void test06() {
    string s = "abcdefghjfgkl";
    s.replace(0, 2, "111");
    cout << s << endl;
}

//比较
void test07() {
    string s1 = "abcd";
    string s2 = "abce"; 

    if (s1.compare(s2) == 0) {
        cout << "两个字符串相等" << endl;
    }
    else
    {
        cout << "两个字符串不相等" << endl;
    }

}

//截取子串
void test08() {
    string s = "abcdefg";
    string mysubstr = s.substr(1, 3);
    cout << mysubstr << endl;
}

//插入
void test09() {
    string s = "abcdefghjfgkl";
    s.insert(1, "11");//从1位置（1位置后面插）插入11
    cout << s << endl;
    s.erase(1, 2);  // 从1位置开始删除2个
    cout << s << endl;
}

int main()
{
    //test01();
    //test02();
    //test03();
    //test04();
    //test05();
    //test06();
    //test07();
    //test08();
    test09();
    
    system("pause");
    return 0;
}