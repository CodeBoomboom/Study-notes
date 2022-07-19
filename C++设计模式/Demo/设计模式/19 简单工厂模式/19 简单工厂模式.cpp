#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//简单工厂模式

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
    static AbstractFruit* CreateFruit(string flag) {
        if (flag == "Apple") {
            return new Apple;
        }
        else if (flag == "Banana") {
            return new Banana;
        }
        else if (flag == "Pear") {
            return new Pear;
        }
        else {
            return NULL;
        }
    }
};

void test01() {
    FriutFactorty* factorty = new FriutFactorty;
    AbstractFruit* fruit = factorty->CreateFruit("Apple");
    fruit->ShowName();
    delete fruit;

    fruit = factorty->CreateFruit("Banana");
    fruit->ShowName();
    delete fruit;

    fruit = factorty->CreateFruit("Pear");
    fruit->ShowName();
    delete fruit;

    delete factorty;
}

int main()
{
    test01();

    return 0;
}