#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<list>
#include<time.h>
#include<algorithm>
using namespace std;

struct MyPrint01 {
    void operator()(int  val) {
        cout <<val<< " ";
    }
};
struct MyCompare01 {
    bool operator()(int v1, int v2) {
        return v1 > v2;
    }
};

//merge(iterator beg1, iterator end1, iterator beg2, iterator end2， iterator dest) 容器元素合并（有序），并存储到另一容器中
void test01() {
    vector<int> v1;
    vector<int> v2;
    list<int> l3;

    srand((unsigned int)time(NULL));

    for (int i = 0; i < 10; i++) {
        v1.push_back(rand() % 10);
    }

    for (int i = 0; i < 10; i++) {
        //v2 .push_back(rand() % 10);
        l3.push_back(rand() % 10);
    }

    sort(v1.begin(), v1.end(), MyCompare01());
    //sort(v2.begin(), v2.end(), MyCompare01());
    l3.sort(MyCompare01());

    //_OutIt merge(_InIt1 _First1, _InIt1 _Last1, _InIt2 _First2, _InIt2 _Last2, _OutIt _Dest)

    vector<int> v3;
    //v3.resize(v1.size() + v2.size());
    v3.resize(v1.size() + l3.size());


    //默认从小到大
    //merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin(), MyCompare01());//v1 v2 必须为有序！
    merge(v1.begin(), v1.end(), l3.begin(), l3.end(), v3.begin(), MyCompare01());
    for_each(v3.begin(), v3.end(), MyPrint01());
    cout << endl;
}

//sort(iterator beg,iterator end, _callback)  排序  
//容器必须支持随机访问(如list就不行)
void test02() {
    vector<int> v1;
    vector<int> v2;
    //list<int> l3;//list不支持随机访问，所以不行

    srand((unsigned int)time(NULL));

    for (int i = 0; i < 10; i++) {
        v1.push_back(rand() % 10);
    }

    for (int i = 0; i < 10; i++) {
        v2.push_back(rand() % 10);
        //l3.push_back(rand() % 10);
    }

    sort(v1.begin(), v1.end(), MyCompare01());
    sort(v2.begin(), v2.end(), MyCompare01());
    //sort(l3 .begin(), l3.end(), MyCompare01());

}


//random_shuffle(iterator beg, iterator end)  洗牌打乱
//容器必须支持随机访问
void test03() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    for_each(v.begin(), v.end(), MyPrint01());
    cout << endl;
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), MyPrint01());
    cout << endl;

}


//reverse(iterator beg, iterator end)  翻转
void test04() {
    //vector<int> v;
    list<int> l;
    for (int i = 0; i < 10; i++) {
        //v.push_back(i);
        l.push_back(i);
    }

    //for_each(v.begin(), v.end(), MyPrint01());
    //cout << endl;
    //reverse(v.begin(), v.end());
    //for_each(v.begin(), v.end(), MyPrint01());
    //cout << endl;

    for_each(l.begin(), l.end(), MyPrint01());
    cout << endl;
    reverse(l.begin(), l.end());
    for_each(l.begin(), l.end(), MyPrint01());
    cout << endl;

}
int main(){
    //test01();
    //test02();
    //test03();
    test04();
    return 0;
}