#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//工厂方法模式

class AbstractFruit {

public:
    virtual void ShowName() = 0;
};

//苹果
class  Apple :public AbstractFruit
{
public:
    virtual void ShowName() {
        cout << "我是苹果" << endl;
    }
protected:
private:
};

//香蕉
class  Banana :public AbstractFruit
{
public:
    virtual void ShowName() {
        cout << "我是香蕉" << endl;
    }
protected:
private:
};

//鸭梨
class  Pear :public AbstractFruit
{
public:
    virtual void ShowName() {
        cout << "我是鸭梨" << endl;
    }
protected:
private:
};


//水果工厂
class FriutFactorty {
public:
    virtual AbstractFruit* CreateFruit() = 0;
};

//苹果工厂
class AppleFactory : public FriutFactorty
{
public:
    virtual AbstractFruit* CreateFruit() {
        return new Apple;
    }
};

//香蕉工厂
class BananaFactory : public FriutFactorty
{
public:
    virtual AbstractFruit* CreateFruit() {
        return new Banana;
    }
};

//鸭梨工厂
class PearFactory : public FriutFactorty
{
public:
    virtual AbstractFruit* CreateFruit() {
        return new Pear;
    }
};

void test01() {
    FriutFactorty* factorty = new AppleFactory;
    AbstractFruit* fruit = factorty->CreateFruit();
    fruit->ShowName();
    delete fruit;
    delete factorty;

    factorty = new BananaFactory;
    fruit = factorty->CreateFruit();
    fruit->ShowName();
    delete fruit;
    delete factorty;

    factorty = new PearFactory;
    fruit = factorty->CreateFruit();
    fruit->ShowName();
    delete fruit;
    delete factorty;
}

int main()
{
    test01();

    return 0;
}