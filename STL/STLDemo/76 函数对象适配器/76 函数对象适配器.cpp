#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

struct MyPrint {
    void operator()(int val)const {
        cout << val + 100<< " "<<endl; //如果希望将值 + 100后输出
    }
};

//如果需要一堆增加值后的输出，按照下边的写法需要一堆函数对象，写起来就很麻烦了
//struct MyPrint02 {
//    void operator()(int val)const {
//        cout << val + 200 << " "; //如果希望将值 + 200后输出
//    }
//};

//考虑将增加值作为参数传入，然而for_each需要的是一元函数对象，此时就需要绑定适配器
//需要继承父类: public binary_function<int, int, void>  参数类型，返回值
struct MyPrint03 : public binary_function<int, int, void>{ 
    void operator()(int val, int plus)const {
        cout<<"val："<<val<<"plus："<< plus <<endl;
        cout << val + plus << " "; //如果希望将值 + plus后输出
    }
};

//函数对象适配器 bind1st bin2nd 绑定适配器
void test01() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), MyPrint());
    int addNum = 200;
    for_each(v.begin(), v.end(), bind2nd(MyPrint03(),addNum));

    //绑定适配器：将一个二元函数对象转变成一元函数对象

    //bind1st，bind2nd区别？
    //bind1st将传进来的参数绑定为函数对象的第一个参数，bind2nd绑定为第二个参数
    //两个都是将二元函数对象绑定为一元函数对象
}


//需要继承父类: public binary_function<int, int, void>  参数类型，返回值
struct MyCompare : public  binary_function<int, int ,bool>{
    bool operator()(int v1, int v2) const {
        return v1 > v2;
    }
};
struct MyPrint04 {
    void operator()(int val)const {
        cout << val<< " " ; //如果希望将值 + 100后输出
    }
};

struct MyGreater5 : public unary_function<int, bool>{
    bool operator()(int v) const {
        return v > 5;
    }
};

//函数对象适配器 not1 not2 取反适配器
void test02() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        //v.push_back(rand()%100 );//rand % (b - a + 1) + a  : a~b一个随机整数
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), MyPrint04()); cout << endl;
    sort(v.begin(), v.end(), not2(MyCompare()));//取反 从大到小改为从小到大
    for_each(v.begin(), v.end(), MyPrint04()); cout << endl;

    //not1和not2的区别
    //如果对二元谓词取反：not2
    //如果对一元谓词取反：not1

    //一元
    vector<int>::iterator it = find_if(v.begin(), v.end(), not1(MyGreater5()));
    if (it == v.end()) {
        cout << "没有找到" << endl;
    }
    else {
        cout << "找到了：" << *it << endl;
    }
}

void Myprint05(int val1, int val2) {
    cout << "val1：" << val1 << " " << "val2：" << val2 << endl;
    cout << val1 + val2 << endl;
}

//仿函数适配器： ptr_fun
void test03() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        //v.push_back(rand()%100 );//rand % (b - a + 1) + a  : a~b一个随机整数
        v.push_back(i);
    }

    //普通函数无法通过bind1st等适配器进行绑定等操作
    //这时候就需要把普通函数适配成（转成）函数对象
    for_each(v.begin(), v.end(), bind2nd(ptr_fun(Myprint05),10)); 

}

class Person
{
public:
    Person(int age, int id) :age(age), id(id){}
    ~Person(){}
    void show() {
        cout << "age：" << age << "id：" << id << endl;
    }
public:
    int age;
    int id;
};


//成员函数适配器：mem_fun  men_fun_ref
void test04() {
    //如果容器中存放的是对象或对象指针，我们for_each算法打印的时候调用类自己提供的打印函数
    vector<Person> v;
    Person p1(10, 20), p2(30, 40), p3(50, 60);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    //格式 &类名::函数名
    for_each(v.begin(), v.end(), mem_fun_ref(&Person::show)); 

    vector<Person*> v1;
    v1.push_back(&p1);
    v1.push_back(&p2);
    v1.push_back(&p3);
    for_each(v1.begin(), v1.end(), mem_fun(&Person::show));

    //对象用mem_fun_ref 对象指针用mem_fun
}


int main(){
    //test01();
    //test02();
    //test03();
    test04();
    system("pause");
    return 0;
}