#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//一般情况下 使用继承来实现类的功能扩展
//装饰模式  可以动态的给一个类添加功能

//抽象英雄
class AbstractHero {
public:
    virtual void ShowStatus() = 0;
public:
    int mHP;
    int mMP;
    int mAt;
    int mDf;
};

//具体英雄
class HeroA : public AbstractHero {
public:
    HeroA() {
        mHP = 0;
        mMP = 0;
        mAt = 0;
        mDf = 0;
    }
    virtual void ShowStatus() {
        cout << "血量：" << mHP << endl;
        cout << "魔法：" << mMP << endl;
        cout << "攻击：" << mAt << endl;
        cout << "防御：" << mDf << endl;
    }
};

//英雄穿上某个装饰物，那么他还是个英雄
class AbstractEquipment : public AbstractHero {
public:
    AbstractEquipment(AbstractHero* Hero){
        this->pHero = Hero;
    }
    virtual void ShowStatus(){}
public:
    AbstractHero* pHero;
};

//狂徒
class KuangTu :public AbstractEquipment {
public:
    KuangTu(AbstractHero* Hero):AbstractEquipment(Hero){}
    //增加额外功能
    void AddKuangtu() {
        cout << "英雄穿上狂徒后：" << endl;
        this->mHP = this->pHero->mHP;
        this->mMP = this->pHero->mMP;
        this->mAt = this->pHero->mAt;
        this->mDf = this->pHero->mDf + 30;
        delete this->pHero;
    }
    virtual void ShowStatus() {
        AddKuangtu();
        cout << "血量：" << mHP << endl;
        cout << "魔法：" << mMP << endl;
        cout << "攻击：" << mAt << endl;
        cout << "防御：" << mDf << endl;
    }
};

//无尽
class WuJin :public AbstractEquipment {
public:
    WuJin(AbstractHero* Hero) :AbstractEquipment(Hero) {}
    //增加额外功能
    void AddWuJin() {
        cout << "英雄穿上无尽后：" << endl;
        this->mHP = this->pHero->mHP;
        this->mMP = this->pHero->mMP;
        this->mAt = this->pHero->mAt+80;
        this->mDf = this->pHero->mDf ;
        delete this->pHero;

    }
    virtual void ShowStatus() {
        AddWuJin();
        cout << "血量：" << mHP << endl;
        cout << "魔法：" << mMP << endl;
        cout << "攻击：" << mAt << endl;
        cout << "防御：" << mDf << endl;
    }
};


void test01() {
    AbstractHero* hero = new HeroA;
    hero->ShowStatus();

    cout << "------------------------------" << endl;
    //给裸奔的英雄穿上衣服
    hero = new KuangTu(hero);
    hero->ShowStatus();
    cout << "------------------------------" << endl;
    hero = new WuJin(hero);
    hero->ShowStatus();

}

int main(){
    test01();

    return 0;
}