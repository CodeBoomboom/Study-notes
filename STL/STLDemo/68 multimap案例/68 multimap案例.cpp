#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<time.h>
#include<stdlib.h>
using namespace std;
//multimap案例
//公司今天招聘了五个员工，5名员工进入公司后，需要指派员工在哪个部门工作
//人员信息有：姓名 年龄 电话 工资等组成
//通过multimap进行信息的插入 保存 显示
//分部门显示员工信息 显示全部员工信息

#define SALE_DEPARTMENT             1       //销售部门
#define DEVELOP_DEPARTMENT      2       //研发部门
#define FINACIAL_DEPARTMENT      3      //财务部门
#define ALL_DEPAERTMENT              4      //所有部门   

class Worker {
public:
    string mName;
    string mTele;
    int mAge;
    int mSalary;
};
void Create_Worker(vector<Worker>& vWorker) {
    srand(time(NULL));
    string seedName = "ABCDE";
    for (int i = 0; i < 5; i++) {
        Worker worker;
        worker.mName = "员工";
        worker.mName += seedName[i];

        worker.mAge = rand() % 10 + 20;
        worker.mTele = "010-88888888";
        worker.mSalary = rand() % 10000 + 10000;

        vWorker.push_back(worker);
    }
}

void WorkerByGroup(vector<Worker>& vWorker, multimap<int, Worker>& workerGroup) {
    //把员工随机分配到不同部门
    for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++) {
        int departID = rand() % 3 + 1;
        switch (departID)
        {
         case SALE_DEPARTMENT:
             workerGroup.insert(make_pair(SALE_DEPARTMENT, *it));
             break;
         case DEVELOP_DEPARTMENT:
             workerGroup.insert(make_pair(DEVELOP_DEPARTMENT, *it));
             break;
         case FINACIAL_DEPARTMENT:
             workerGroup.insert(make_pair(FINACIAL_DEPARTMENT, *it));
             break;
         default:
             break;
        }
    }
}

void ShowGroupWorkers(multimap<int, Worker>& workerGroup, int departid) {
    multimap<int, Worker>::iterator it = workerGroup.find(departid);//第一次出现位置
    int DepartCount = workerGroup.count(departid);//当前部门总人数
    int num = 0;
    cout << "部门：" << departid << endl;
    for (multimap<int, Worker>::iterator pos = it; it != workerGroup.end() && num < DepartCount; pos++, num++) {
        cout << "姓名：" << pos->second.mName << " " << "年龄" << pos->second.mAge << " " << "电话" << pos->second.mTele << " " << "工资" << pos->second.mSalary << endl;
    }
}

void PrintWorkerByGroup(multimap<int, Worker>& workerGroup) {
     //打印销售部员工
    ShowGroupWorkers(workerGroup, SALE_DEPARTMENT);

     //打印研发部员工
    ShowGroupWorkers(workerGroup, DEVELOP_DEPARTMENT);
     //打印财务部员工
    ShowGroupWorkers(workerGroup, FINACIAL_DEPARTMENT);
}


void test01() {
    //存放新员工信息
    vector<Worker> vWorker;
    //multimap保存分组信息
    multimap<int, Worker> workerGroup;

    //创建员工
    Create_Worker(vWorker);
    //员工分组
    WorkerByGroup(vWorker, workerGroup);
    //打印每一部门的员工信息
    PrintWorkerByGroup(workerGroup);
}


class MyKey
{
public:
    MyKey(int index, int id) :mID(id), mIndex(index) {}


public:
    int mIndex;
    int mID;

};

struct mycompare {
    bool operator()(MyKey k1, MyKey k2) const{
        return k1.mIndex > k2.mIndex;
    }
};

void test02() {
    map<MyKey, int, mycompare> mymap;//自动排序，自定义数据类型，咋排？

    mymap.insert(make_pair(MyKey(1, 2), 10));
    mymap.insert(make_pair(MyKey(4, 5), 20));

    for (map<MyKey, int, mycompare>::iterator it = mymap.begin(); it != mymap.end(); it++) {
        cout << it->first.mIndex << ":" << it->first.mID << " = " << it->second << endl;
    }
    

}

void test03() {
    map<int, int> mymap;
    mymap.insert(pair<int, int>(1, 4));
    mymap.insert(pair<int, int>(2, 5));
    mymap.insert(pair<int, int>(3, 6));

    pair<map<int, int>::iterator, map<int, int>::iterator> ret = mymap.equal_range(2);
    if (ret.first->second) {
        cout << "找到了" << endl;
    }
    else {
        cout << "没找到" << endl;
    }
}

int main()
{
    //test01();
    //test02();
    test03();
    system("pause");
    return 0;
}