#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
using namespace std;

//抽象的英雄
class AbstractHero {
public:
    virtual void Update() = 0;

};
class HeroA :public AbstractHero {
public:
    HeroA() {
        cout << "英雄A正在撸BOSS..." << endl;
    }
    virtual void Update() {
        cout << "英雄A停止撸，待机状态..." << endl;
    }
};
class HeroB :public AbstractHero {
public:
    HeroB() {
        cout << "英雄B正在撸BOSS..." << endl;
    }
    virtual void Update() {
        cout << "英雄B停止撸，待机状态..." << endl;

    }
}; 
class HeroC :public AbstractHero {
public:
    HeroC() {
        cout << "英雄C正在撸BOSS..." << endl;
    }
    virtual void Update() {
        cout << "英雄C停止撸，待机状态..." << endl;

    }
};
class HeroD :public AbstractHero {
public:
    HeroD() {
        cout << "英雄D正在撸BOSS..." << endl;
    }
    virtual void Update() {
        cout << "英雄D停止撸，待机状态..." << endl;

    }
};
class HeroE :public AbstractHero {
public:
    HeroE() {
        cout << "英雄E正在撸BOSS..." << endl;
    }
    virtual void Update() {
        cout << "英雄E停止撸，待机状态..." << endl;

    }
};

//观察目标抽象
class AbstractBoss {
public:
    virtual void addHero(AbstractHero* hero) = 0;//添加观察者
    virtual void deleteHero(AbstractHero* hero) = 0;//删除观察者
    virtual void notify() = 0;  //通知所有观察者
};

class BOSSA: public AbstractBoss {
public:
    virtual void addHero(AbstractHero* hero) {
        pHeroList.push_back(hero);
    }
    virtual void deleteHero(AbstractHero* hero) {
        pHeroList.remove(hero);
    }
    virtual void notify() {
        for (list< AbstractHero*>::iterator it = pHeroList.begin(); it != pHeroList.end(); it++) {
            (*it)->Update();
        }
    }
public:
    list< AbstractHero*> pHeroList;
};


void test01() {
    //创建观察者
    AbstractHero* heroA = new HeroA;
    AbstractHero* heroB = new HeroB;
    AbstractHero* heroC = new HeroC;
    AbstractHero* heroD = new HeroD;
    AbstractHero* heroE = new HeroE;

    //创建观察目标
    AbstractBoss* bossA = new BOSSA;
    bossA->addHero(heroA);
    bossA->addHero(heroB);
    bossA->addHero(heroC);
    bossA->addHero(heroD);
    bossA->addHero(heroE);

    cout << "heroC阵亡..." << endl;
    bossA->deleteHero(heroC);

    cout << "BOSS死了，通知其他英雄停止攻击，抢装备..." << endl;
    bossA->notify();

}

int main(){
    test01();

    return 0;
}