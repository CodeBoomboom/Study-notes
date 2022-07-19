# 07—10 UML类图

见hzl笔记

# 11 设计模式基本概念

![image-20220704161650830](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704161650830.png)

![image-20220704161655880](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704161655880.png)

![image-20220704161703160](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704161703160.png)

![image-20220704161723683](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704161723683.png)

![image-20220704161741129](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704161741129.png)

![image-20220704161810636](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704161810636.png)

![image-20220704161831941](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704161831941.png)

![image-20220704161837760](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704161837760.png)

![image-20220704161903453](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704161903453.png)

![image-20220704161909198](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704161909198.png)

![image-20220704161916221](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704161916221.png)

![image-20220704161924674](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704161924674.png)

![image-20220704161931133](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704161931133.png)

![image-20220704161938471](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704161938471.png)

![image-20220704161944572](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704161944572.png)

# 12 面向对象设计原则

![image-20220704163637117](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704163637117.png)

![image-20220704163643798](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704163643798.png)

![image-20220704163938873](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704163938873.png)

![image-20220704164044232](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704164044232.png)

![image-20220704164101894](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704164101894.png)

![image-20220704164110505](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704164110505.png)

![image-20220704164118855](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220704164118855.png)

# 13 开闭原则

![image-20220705190417020](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220705190417020.png)

![image-20220705190424124](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220705190424124.png)

![image-20220705190431163](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220705190431163.png)

![image-20220705190440164](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220705190440164.png)

![image-20220705190457621](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220705190457621.png)

![image-20220705190503292](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220705190503292.png)

修改一下，将setOperatorNumber方法写成纯虚函数

![image-20220719145940591](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220719145940591.png)

这时候，运行测试一波

![image-20220719145949619](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220719145949619.png)

用这个代码，扩展新功能就很方便，不用修改原有代码。

本质就是利用了多态，父类作为通用接口，扩展需要的子类。

# 14 迪米特法则

![image-20220705192037995](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220705192037995.png)

```cpp
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
```

# 15合成复用原则

就一句话，能用组合就别用继承

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//合成复用原则

class AbstractCar {
public:
    virtual void run() = 0;
};

class DaZhong :public AbstractCar {
public:
    virtual void run() {
        cout << "大众启动" << endl;
    }
};

class Tuolaji :public AbstractCar {
public:
    virtual void run() {
        cout << "拖拉机启动" << endl;
    }
};

#if 0
//针对具体类，不适用继承
class Person :public Tuolaji {
public:
    void Doufeng() {
        run();
    }
};
#endif

//可以使用组合
class Person {
public:
    void setCar(AbstractCar* car) {
        this->Car = car;
    }
    void Doufeng() {
        this->Car->run();
    }
    ~Person() {
        if (this->Car != NULL) {
            delete this->Car;
        }
    }
public:
    AbstractCar* Car;
};
void test02() {
    Person* p = new Person;
    p->setCar(new DaZhong);
    p->Doufeng();

    delete p;
}

int main()
{
    test02();
    return 0;
}
```

# 16 昨天课程回顾

略

# 17 依赖倒转原则

![image-20220705201020160](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220705201020160.png)

![image-20220705201028017](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220705201028017.png)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//依赖倒转原则

//银行工作人员
class BankWorker {
public:
    void saveService() {
        cout << "办理存款业务" << endl;
    }
    void payService() {
        cout << "办理支付业务" << endl;
    }
    void transferService() {
        cout << "办理转账业务" << endl;
    }
};

//中层模块
void doSaveBussiness(BankWorker* worker) {
    worker->saveService();
}
void doPayBussiness(BankWorker* worker) {
    worker->payService();
}
void doTransferBussiness(BankWorker* worker) {
    worker->transferService();
}

void test01() {
    BankWorker* worker = new BankWorker;
    doSaveBussiness(worker);    //  办理存款业务
    doPayBussiness(worker);    //  办理支付业务
    doTransferBussiness(worker);    //  办理转账业务
}

//银行工作人员
class AbstractWorker {
public:
    virtual void doBusiness() = 0;
};

//专门负责办理存款的人员
class SaveBankWoker : public AbstractWorker {
public:
    virtual void doBusiness() {
        cout << "办理存款业务" << endl;
    }
};
//专门负责支付存款的人员
class PayBankWoker : public AbstractWorker {
public:
    virtual void doBusiness() {
        cout << "办理支付业务" << endl;
    }
};
//专门负责办理转账的人员
class TransferBankWoker : public AbstractWorker {
public:
    virtual void doBusiness() {
        cout << "办理转账业务" << endl;
    }
};

//中层业务模块
void doNewBusiness(AbstractWorker* worker) {
    worker->doBusiness();
    delete worker;
}

void test02() {
    AbstractWorker* transfer = new TransferBankWoker;
    transfer->doBusiness();
}

int main()
{
    test02();


    return 0;
}
```

# 18 简单工厂模式-理论

![image-20220706190924850](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220706190924850.png)

# 19 简单工厂模式-代码实现

![image-20220706192200965](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220706192200965.png)

```cpp
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
    AbstractFruit* apple = factorty->CreateFruit("Apple");
    apple->ShowName();
    delete apple;

    AbstractFruit* banana = factorty->CreateFruit("Banana");
    banana->ShowName();
    delete banana;

    AbstractFruit* pear = factorty->CreateFruit("Pear");
    pear->ShowName();
    delete pear;

    delete factorty;
}

int main()
{
    test01();

    return 0;
}
```



# 20 工厂方法模式

简单工厂中，工厂不符合开闭原则。这里，再将工厂抽象出来，让工厂也符合开闭原则。

![image-20220719160511307](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220719160511307.png)

![image-20220719160526432](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220719160526432.png)

![image-20220719160537043](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220719160537043.png)



![image-20220719160552001](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220719160552001.png)

```cpp
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
```



# 21 简单工厂和工厂方法模式适用场景

工厂方法模式：

![image-20220719162208920](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220719162208920.png)

简单工厂：

![image-20220719162213409](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220719162213409.png)



# 22 抽象工厂模式

![image-20220719162611368](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220719162611368.png)

```cpp
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
```



# 23 单例模式 饿汉式和懒汉式创建

![image-20220719170419977](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220719170419977.png)

![image-20220719170425317](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220719170425317.png)



```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//实现单例的步骤
//1.构造函数私有化
//2.增加静态私有的当前类的指针变量
//3.提供静态对外接口，可以让用户获得单例对象
class A {
private:
    A(){
        a = new A;
    }

public:
    static A* getInstace() {
        return a;
    }
private:
    static A* a;
};
A* A::a = NULL;


//单例分为懒汉式、饿汉式

//懒汉式：只有在调用getInstance的时候才会new一个对象出来
class Singleton_lazzy
{
private:
	Singleton_lazzy(){}
public:
    static Singleton_lazzy* getInstance() {
        if (pSigleton == NULL) {
            pSigleton = new Singleton_lazzy;
        }
        return pSigleton;
    }

private:
    static Singleton_lazzy* pSigleton;

};
//类外初始化
Singleton_lazzy* Singleton_lazzy::pSigleton = NULL;

//饿汉式：在main函数开始执行前就已经创造好了
class Singleton_hungry
{
private:
    Singleton_hungry() { cout << "我是饿汉构造" << endl; }
public:
    static Singleton_hungry* getInstance() {
        return pSigleton;
    }

private:
    static Singleton_hungry* pSigleton;

};
//类外初始化
Singleton_hungry* Singleton_hungry::pSigleton = new Singleton_hungry;


int main(){
    cout << "main函数开始执行" << endl;
    //A::getInstace();
    return 0;
}
```

其实单例模式的核心就是构造函数私有化，让用户不能自己new一个对象。饿汉式是直接类内new一个对象，懒汉式是在需要访问对象时才实例化。完事儿通过static来保证大家访问的都是同一个实例

![image-20220719173742958](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220719173742958.png)

懒汉式：

![image-20220719173809582](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220719173809582.png)

# 24 上午课程回顾

略



















































