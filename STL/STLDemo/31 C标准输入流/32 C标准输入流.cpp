#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#if 0
cout;    //全局流对象 输出数据到显示器
cin;
//cerr没有缓冲区，clog有缓冲区
cerr;//标准错误 输出数据到显示器
clog;//标准日志 输出数据到显示器
#endif

//标准输入流 cin.get()
void test01() {
    char ch;
    while ((ch = cin.get()) != EOF) {
        cout << ch << endl;
    }

    //cin.get()
    //char ch2;
    //cin.get(ch2);//读取一个字符，放入ch2
    //char buf[256] = { 0 };
    //cin.get(buf, 256);//从缓冲区读一个字符串 ，放入buf
    //cin.getline(buf, 256);//读取一行数据 不读换行符
    //cout << buf << endl;
}


//cin.ignore() 忽略当前的字符
void test02() {
    char ch;
    cin.get(ch);//从缓冲区要数据 阻塞
    cout << ch << endl;
    cin.ignore();//忽略掉缓冲区的一个字符，从缓冲区取走了（缓冲区已经没有这个字符了）
    cin.ignore(10, '\n');//忽略缓冲区10个字符，如果到\n，则忽略\n前的字符
    cin.get(ch);
    cout << ch << endl;
}

//cin.peek()    与cin.get不同，cin.peek只是看一下缓冲区数据，并没有取走
void test03() {
    cout << "请输入数字或者字符串" << endl;
    char ch;
    ch = cin.peek();    //偷窥一下缓冲区，返回第一个字符
    if (ch >='0' && ch <= '9') {
        int num;
        cin >> num;
        cout << "您输入的是数字" << num << endl;
    }
    else {
        char buf[256] = { 0 };
        cin >> buf;
        cout << "您输入的是字符串" <<buf<< endl;
    }
}

//cin.putback  cin.get
void test04() {
    cout << "请输入数字或者字符串" << endl;
    char ch;
    ch = cin.get(); 
    if (ch >= '0' && ch <= '9') {
        cin.putback(ch);//ch放回到缓冲区
        int num;
        cin >> num;
        cout << "您输入的是数字" << num << endl;
    }
    else {
        cin.putback(ch);//ch放回到缓冲区
        char buf[256] = { 0 };
        cin >> buf;
        cout << "您输入的是字符串" << buf << endl;
    }

}



int main()
{
    test01();
    //test02();
    //test03();
    //test04();

    return 0;
}