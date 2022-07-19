#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//抽象苹果
class AbstractApple
{
public:
    virtual void showName() = 0;
};
//中国苹果
class ChinaApple : public AbstractApple {
public:
    virtual void showName() {
        cout << "中国苹果" << endl;
    }
};
//美帝苹果
class USAApple : public AbstractApple {
public:
    virtual void showName() {
        cout << "美帝苹果" << endl;
    }
};
//倭寇苹果
class JapanApple : public AbstractApple {
public:
    virtual void showName() {
        cout << "倭寇苹果" << endl;
    }
};


//抽象香蕉
class AbstractBanana
{
public:
    virtual void showName() = 0;
};
//中国香蕉
class ChinaBanana : public AbstractBanana {
public:
    virtual void showName() {
        cout << "中国香蕉" << endl;
    }
};
//美帝香蕉
class USABanana : public AbstractBanana {
public:
    virtual void showName() {
        cout << "美帝香蕉" << endl;
    }
};
//倭寇香蕉
class JapanBanana : public AbstractBanana {
public:
    virtual void showName() {
        cout << "倭寇香蕉" << endl;
    }
};


//抽象鸭梨
class AbstractPear
{
public:
    virtual void showName() = 0;
};
//中国鸭梨
class ChinaPear : public AbstractPear {
public:
    virtual void showName() {
        cout << "中国鸭梨" << endl;
    }
};
//美帝鸭梨
class USAPear : public AbstractPear {
public:
    virtual void showName() {
        cout << "美帝鸭梨" << endl;
    }
};
//倭寇鸭梨
class JapanPear : public AbstractPear {
public:
    virtual void showName() {
        cout << "倭寇鸭梨" << endl;
    }
};


//抽象工厂
class AbstractFactory {
public:
    virtual AbstractApple* CreateApple() = 0;
    virtual AbstractBanana* CreateBanana() = 0;
    virtual AbstractPear* CreatePear() = 0;
};
//中国工厂
class ChinaFactory : public AbstractFactory {
public:
    virtual AbstractApple* CreateApple() {
        return new ChinaApple;
    }
    virtual AbstractBanana* CreateBanana() {
        return new ChinaBanana;
    }
    virtual AbstractPear* CreatePear() {
        return new ChinaPear;
    }
};
//美帝工厂
class USAFactory : public AbstractFactory {
public:
    virtual AbstractApple* CreateApple() {
        return new USAApple;
    }
    virtual AbstractBanana* CreateBanana() {
        return new USABanana;
    }
    virtual AbstractPear* CreatePear() {
        return new USAPear;
    }
};
//倭寇工厂
class JapanFactory : public AbstractFactory {
public:
    virtual AbstractApple* CreateApple() {
        return new JapanApple;
    }
    virtual AbstractBanana* CreateBanana() {
        return new JapanBanana;
    }
    virtual AbstractPear* CreatePear() {
        return new JapanPear;
    }
};


void test01() {
	//创建一个工厂，依次让中国工厂、美帝工厂、倭寇工厂生产苹果、香蕉、鸭梨
    AbstractFactory* factory = NULL;
    AbstractApple* apple = NULL;
    AbstractBanana* banana = NULL;
    AbstractPear* pear = NULL;

    //中国苹果
    factory = new ChinaFactory;
    apple = factory->CreateApple();
    apple->showName();
    delete apple;
    //中国香蕉
    banana = factory->CreateBanana();
    banana->showName();
    delete banana;
    //中国鸭梨
    pear = factory->CreatePear();
    pear->showName();
    delete pear;
    delete factory;

    //美帝苹果
    factory = new USAFactory;
    apple = factory->CreateApple();
    apple->showName();
    delete apple;
    //美帝香蕉
    banana = factory->CreateBanana();
    banana->showName();
    delete banana;
    //美帝鸭梨
    pear = factory->CreatePear();
    pear->showName();
    delete pear;
    delete factory;

    //倭寇苹果
    factory = new JapanFactory;
    apple = factory->CreateApple();
    apple->showName();
    delete apple;
    //倭寇香蕉
    banana = factory->CreateBanana();
    banana->showName();
    delete banana;
    //倭寇鸭梨
    pear = factory->CreatePear();
    pear->showName();
    delete pear;
    delete factory;

}

int main(){
    test01();

    return 0;
}