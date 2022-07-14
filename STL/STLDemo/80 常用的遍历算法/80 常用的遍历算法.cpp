#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//transform  将一个容器中的元素搬运到另一个容器中
struct MyPlus {
    int operator()(int val) {
        return val+100;
    }
};
struct MyPrint{
    void operator()(int val) {
        cout << val << " ";
    }
    
};
void test01() {
    vector<int> v1;
    vector<int> v2;

    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }

    v2.resize(v1.size());//开辟空间
    transform(v1.begin(), v1.end(), v2.begin(), MyPlus());//把v1中的元素逐个放入MyPlus仿函数中，仿函数返回的值逐个放到v2中
    for_each(v2.begin(), v2.end(), MyPrint());

}

int main(){
    test01();

    return 0;
}