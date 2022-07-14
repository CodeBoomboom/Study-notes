#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
using namespace std;

void PirntMap(map<int, int>& m) {
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        //*it取出来是一个pair
        cout << "key:" << it->first << "value:" << (*it).second << endl;
    }
}

//map容器初始化
void test01() {
    map<int, int> mymap;//map容器模板参数，第一个参数key的类型，第二个参数value的类型

    //插入数据  pair.first key值，pair.second value值
    //第一种
    pair<map<int, int>::iterator ,bool> ret = mymap.insert(pair<int, int>(10, 10));//insert返回一个pair，first是迭代器，second是bool类型（是否成功）
    if (ret.second) {
        cout << "第一次插入成功" << endl;
    }
    else {
        cout << "第一次插入失败" << endl;
    }
    ret = mymap.insert(pair<int, int>(10, 20));//key一样value改变
    if (ret.second) {
        cout << "第二次插入成功" << endl;
    }
    else {
        cout << "第二次插入失败" << endl;
    }
    //第二种
    mymap.insert(make_pair(20, 20));
    //第三种
    mymap.insert(map<int, int>::value_type(30, 30));
    //第四种
    mymap[40] = 40;
    mymap[10] = 20;//如果key不存在则创建pair插入，如果key存在，会修改对应的value值
    mymap[50] = 50;

    //打印：通过迭代器
    //for (map<int, int>::iterator it = mymap.begin(); it != mymap.end(); it++) {
    //    //*it取出来是一个pair
    //    cout << "key:" << it->first << "value:" << (*it).second << endl;
    //}
    PirntMap(mymap);
    //如果通过[]的方式去访问map中不存在的key，map会将这个访问的key插入到map中并给value一个默认值0
    cout << mymap[60] << endl;
    PirntMap(mymap);

}

int main()
{
    test01();
    system("pause");
    return 0;
}