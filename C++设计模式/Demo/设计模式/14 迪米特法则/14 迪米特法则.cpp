#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
using namespace std;

//迪米特法则：最少知识原则，低耦合，高内聚
class AbstractBuliding {
public:
    virtual void sale() = 0;
    virtual string getQuality() = 0;

};

//楼盘A
class BulidingA : public AbstractBuliding {
public:
    BulidingA() {
        mQulity = "高品质";
    }
    virtual void sale() {
        cout << "楼盘A" << mQulity << "被售卖" << endl;
    }
    virtual string getQuality() {
        return mQulity;
    }
public:
    string mQulity;
};

//楼盘B
class BulidingB : public AbstractBuliding {
public:
    BulidingB() {
        mQulity = "低品质";
    }
    virtual void sale() {
        cout << "楼盘B" << mQulity << "被售卖" << endl;
    }
    virtual string getQuality() {
        return mQulity;
    }
public:
    string mQulity;
};

//客户端
void test01() {
    BulidingA* ba = new BulidingA;
    if (ba->mQulity == "低品质") {
        ba->sale();
    }

    BulidingB* bb = new BulidingB;
    if (bb->mQulity == "低品质") {
        bb->sale();
    }

}

//中介类
class Mediator {
public:
    Mediator() {
        AbstractBuliding* buliding = new BulidingA;

        vBuliding.push_back(buliding);
        buliding = new BulidingB;
        vBuliding.push_back(buliding);
    }
      //对外提供接口
    AbstractBuliding* findMyBuliding(string quality) {
        for (vector<AbstractBuliding*>::iterator it = vBuliding.begin(); it != vBuliding.end(); it++) {
            if ((*it)->getQuality() == quality) {
                return *it;
            }
        }
        return NULL;
    }

    ~Mediator() {
        for (vector<AbstractBuliding*>::iterator it = vBuliding.begin(); it != vBuliding.end(); it++) {
            if (*it != NULL) {
                delete* it;
            }
        }
    }
public:
    vector<AbstractBuliding* > vBuliding;
};


void test02() {
    Mediator* mediator = new Mediator;
    AbstractBuliding* building = mediator->findMyBuliding("高品质");
    if (building != NULL) {
        building->sale();
    }
    else {
        cout << "没有符合条件的楼盘" << endl;
    }
}

int main()
{
    //test01();
    test02();
    return 0;
}