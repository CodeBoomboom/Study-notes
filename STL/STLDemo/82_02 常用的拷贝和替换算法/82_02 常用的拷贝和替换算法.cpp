#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<time.h>
#include<algorithm>
using namespace std;

struct MyPrint01 {
    void operator()(int  val) {
        cout << val << " ";
    }
};
struct MyCompare01 {
    bool operator()(int v1, int v2) {
        return v1 > v2;
    }
};

//copy(iterator beg, iterator end, iterator dest) 将容器内指定范围的元素拷贝到另一容器中
//swap(container c1, container c2) 交换两个容器中元素的值
void test01() {
    vector<int> v1;

    
    srand((unsigned int)time(NULL));

    for (int i = 0; i < 10; i++) {
        v1.push_back(rand() % 10);
    }

    vector<int> v2;
    v2.resize(v1.size());

    copy(v1.begin(), v1.end(), v2.begin());

    cout << "v1：" << " ";
    for_each(v1.begin(), v1.end(), MyPrint01());
    cout << endl;
    cout << "v2：" << " ";
    for_each(v2.begin(), v2.end(), MyPrint01());
    cout << endl;

    //swap
    vector<int> v3;
    for (int i = 0; i < 10; i++) {
        v3.push_back(rand() % 10);
    }

    cout << "交换前：" << endl;
    cout << endl;
    cout << "v2：" << " ";
    for_each(v2.begin(), v2.end(), MyPrint01());
    cout << endl;
    cout << "v3：" << " ";
    for_each(v3.begin(), v3.end(), MyPrint01());
    cout << endl;

    swap(v2, v3);

    cout << "交换后：" << " ";
    cout << endl;
    cout << "v2：" << " ";
    for_each(v2.begin(), v2.end(), MyPrint01());
    cout << endl;
    cout << "v3：" << " ";
    for_each(v3.begin(), v3.end(), MyPrint01());
    cout << endl;
}


struct MyCompare02{
    bool operator()(int val) {
        return val > 5;
    }
};

//replace(iterator beg, iterator end, oldvalue, new value)将容器内的oldvalue替换为newvalue
//replace_if((iterator beg, iterator end, _callback, new value);
void test02() {
    vector<int> v1;

    srand((unsigned int)time(NULL));

    for (int i = 0; i < 10; i++) {
        v1.push_back(rand() % 10);
    }
    for_each(v1.begin(), v1.end(), MyPrint01()); cout << endl;
    replace(v1.begin(), v1.end(), 5, 100);
    for_each(v1.begin(), v1.end(), MyPrint01()); cout << endl;

    replace_if(v1.begin(), v1.end(), MyCompare02(), 200);

    for_each(v1.begin(), v1.end(), MyPrint01());

}




int main(){
    //test01();
    test02();
    return 0;
}