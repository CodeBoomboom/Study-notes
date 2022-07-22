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



# 25 单例对象释放问题

写一个静态函数来释放

```cpp
static void freeSpace() {
    if (pSigleton != NULL) {
        delete pSigleton;
    }
}
```

类外调用这个函数

```cpp
Singleton_hungry::freeSpace();
```

然后问题出现了，大家都能调用这个函数，不知道那个傻吊给单例对象删了。所以这种方法不行的，容易出问题。



正确的写法是，来个垃圾工人嵌套类，放在单例类中：

```cpp
//饿汉式：在main函数开始执行前就已经创造好了
class Singleton_hungry
{
private:
    Singleton_hungry() { cout << "我是饿汉构造" << endl; }
public:
    static Singleton_hungry* getInstance() {
        return pSigleton;
    }
#if 0   //这样写不行，任何人都能调这个函数
    static void freeSpace() {
        if (pSigleton != NULL) {
            delete pSigleton;
        }
    }
#endif
    class Garbo {
        ~Garbo() {
            if (pSigleton != NULL) {
                delete pSigleton;
            }
        }
    };
private:
    static Singleton_hungry* pSigleton;
    static Garbo garbo;

};
//类外初始化
Singleton_hungry* Singleton_hungry::pSigleton = new Singleton_hungry;
```

程序结束时，会调用辣鸡工人析构函数，就把单例析构掉了。但实际上，程序运行结束的时候，即使没有辣鸡工人，也会释放掉单例。

结论，单例不需要考虑释放问题。



# 26 多线程基本概念

![image-20220721100620490](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220721100620490.png)





# 27 单例碰到多线程

![image-20220721100642923](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220721100642923.png)

因为如果是懒汉式，如果两个线程都进入的getInstance，而此时pSingleton正好为空，则这两个都会给pSingleton分配内存，就不是单例了，除非加锁。而饿汉式就不会出现这个问题。所以用**饿汉式**。

# 28 代理概念理解案例

![image-20220721100718060](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220721100718060.png)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//提供一种代理方式来控制对其他对象的访问

class AbstractCommonInterface {
public:
    virtual void run() = 0;
};

class MySystem : public AbstractCommonInterface {
public:
    virtual void run() {
        cout << "系统启动" << endl;
    }
};
//必须要有权限验证，不是所有人都能来启动我的系统，提供用户名和密码
class MySystemProcy : public AbstractCommonInterface {
public:
    MySystemProcy(string username, string password): mUserName(username), mPassword(password) {
        pSystem = new MySystem;
    }

    bool checkUsernameAndPahhword(){
        if(mUserName == "admin" && mPassword == "admin")
        {
            return true;
        }
        else {
            return false;
        }
    }
    virtual void run() {
        if (checkUsernameAndPahhword()) {
            cout << "用户名及密码正确，验证通过" << endl;
            this->pSystem->run();
        }
        else {
            cout << "用户名和密码错误，权限不足" << endl;
        }
    }
    ~MySystemProcy()
    {
        if (pSystem != NULL)
        {
            delete pSystem;
        }
    }
public:
    MySystem* pSystem;
    string mUserName;
    string mPassword;
};

void test01() {
    MySystemProcy* proxy = new MySystemProcy("root", "admin");
    proxy->run();
    
    delete proxy;
    proxy = new MySystemProcy("admin", "admin");
    proxy->run();
}

int main(){
    //MySystem* system = new MySystem;
    //system->run();
    test01();
    return 0;
}
```



# 29 代理模式举例

web服务器在验证用户连接信息时，使用代理服务器，不然既要验证信息，又要数据传输，服务器压力会过大。

![image-20220721111253696](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220721111253696.png)



# 30 代理模式的基本理论

![image-20220721100819946](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220721100819946.png)

![image-20220721100828896](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220721100828896.png)

![image-20220721100840729](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220721100840729.png)



# 31 上次课程回顾

略

# 32 外观模式_概念

![image-20220722141842724](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220722141842724.png)



![image-20220722141954059](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220722141954059.png)

![image-20220722142006398](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220722142006398.png)

![image-20220722142011878](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220722142011878.png)

![image-20220722142017026](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220722142017026.png)

![image-20220722142025940](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220722142025940.png)

![image-20220722142032501](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220722142032501.png)







# 33 外观模式案例代码

![image-20220722142414462](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220722142414462.png)

![image-20220722142420857](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220722142420857.png)

![image-20220722142425223](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220722142425223.png)



```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class TV {
public:
    void On() {
        cout << "电视打开" << endl;
    }
    void Off() {
        cout << "电视关闭" << endl;
    }
};
class Light {
public:
    void On() {
        cout << "灯打开" << endl;
    }
    void Off() {
        cout << "灯关闭" << endl;
    }
};
class Audio {
public:
    void On() {
        cout << "音响打开" << endl;
    }
    void Off() {
        cout << "音响关闭" << endl;
    }
};
class MKC {
public:
    void On() {
        cout << "麦克风打开" << endl;
    }
    void Off() {
        cout << "麦克风关闭" << endl;
    }
};
class DVD {
public:
    void On() {
        cout << "DVD打开" << endl;
    }
    void Off() {
        cout << "DVD关闭" << endl;
    }
};
class Gamemachine {
public:
    void On() {
        cout << "游戏机打开" << endl;
    }
    void Off() {
        cout << "游戏机关闭" << endl;
    }
};


class KTVMode {
public:
    KTVMode() {
        pTV = new TV;
        pLight = new Light;
        pAudio = new Audio;
        pMKC = new MKC;
        pDVD = new DVD;
    }

    void runKTV() {
        pTV->On();
        pLight->Off();
        pMKC->On();
        pAudio->On();
        pDVD->On();
    }
    void offKTV() {
        pTV->Off();
        pLight->On();
        pMKC->Off();
        pAudio->Off();
        pDVD->Off();
    }

    ~KTVMode() {
       delete pTV ;
       delete pLight;
       delete pAudio;
       delete pMKC;
       delete pDVD;
    }

public:
    TV* pTV;
    Light* pLight;
    Audio* pAudio;
    MKC* pMKC;
    DVD* pDVD;
};


void test01() {
    KTVMode* ktv = new KTVMode;
    ktv->runKTV();
}

int main(){
    test01();
    
    return 0;
}
```



# 34 适配器模式

![image-20220722144326316](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220722144326316.png)

![image-20220722144331574](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220722144331574.png)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//适配器模式就是将已经写好的接口，但是这个接口不符合需求
//将写好的接口转换成目标接口

//这函数我已经写好，是两个参数的，但是for_each需要的是一个参数的，需要转换适配成一个参数的
struct MyPrint{
    void operator()(int v1, int v2) {
        cout << v1 + v2 << endl;
    }
};

//定义目标接口，我要适配成什么样的
class Targrt {
public:
    virtual void operator()(int val) = 0;
};

//适配器
class Adapter :public Targrt {
public:
    Adapter(int param) {
        this->param = param;
    }
    virtual void operator()(int val) {
        print(val , param);
    }
public:
    MyPrint print;
    int param;
};

//MyBind2nd
Adapter MyBind2nd(int v) {
    return Adapter(v);
}

int main(){

    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    for_each(v.begin(), v.end(), MyBind2nd(10));

    return 0;
}
```



# 35 模板方法模式

![image-20220722150933538](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220722150933538.png)

![image-20220722150940133](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220722150940133.png)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//冲泡过程
class DrinkTemplate {
public:
    virtual void BoilWater() = 0;//煮水
    virtual void Brew() = 0;//冲泡
    virtual void PourInCup() = 0;//倒入杯中
    virtual void AddSomething() = 0;//加辅助料

    //模板方法
    void Make() {
        this->BoilWater();
        this->Brew();
        this->PourInCup();
        this-> AddSomething();
    }
};

class Coffee :public DrinkTemplate {
public:
    virtual void BoilWater() {
        cout << "煮纯净水..." << endl;
    }
    virtual void Brew() {
        cout << "冲泡咖啡" << endl;
    }
    virtual void PourInCup() {
        cout << "将咖啡倒入杯中" << endl;
    }
    virtual void AddSomething() {
        cout << "咖啡加入糖，牛奶" << endl;
    }
};

class Tea :public DrinkTemplate {
public:
    virtual void BoilWater() {
        cout << "煮山泉水..." << endl;
    }
    virtual void Brew() {
        cout << "冲泡西湖龙井" << endl;
    }
    virtual void PourInCup() {
        cout << "将茶倒入杯中" << endl;
    }
    virtual void AddSomething() {
        cout << "茶叶加入柠檬" << endl;
    }
};

void test01() {
    Tea* tea = new Tea;
    tea->Make();

    Coffee* coffee = new Coffee;
    coffee->Make();

}

int main(){
    test01();

    return 0;
}
```

![image-20220722152715506](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220722152715506.png)

# 36 策略模式

![image-20220722152744066](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220722152744066.png)

![image-20220722152749772](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220722152749772.png)



```c++
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//抽象武器 武器策略
class WeapomStrategy {
public:
    virtual void UseWeapon() = 0;
};

class Knife :public WeapomStrategy {
public:
    virtual void UseWeapon() {
        cout << "使用匕首" << endl;
    }
};
class AK47 :public WeapomStrategy {
public:
    virtual void UseWeapon() {
        cout << "使用AK47" << endl;
    }
};

class Character {
public:
    void setWeapon(WeapomStrategy* weapon) {
        this->pWeapon = weapon;
    }
    void ThrowWeapon() {
       this->pWeapon->UseWeapon();
    }
public:
    WeapomStrategy* pWeapon;
};

void test01() {
    //创建角色
    Character* character = new Character;

    //武器策略
    WeapomStrategy* knife = new Knife;
    WeapomStrategy* ak47 = new AK47;

    character->setWeapon(knife);
    character->ThrowWeapon();
    character->setWeapon(ak47);
    character->ThrowWeapon();

}

int main(){
    test01();

    return 0;
}
```





# 37 命令模式

![image-20220722161948100](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220722161948100.png)



```c++
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<Windows.h>
using namespace std;

//协议处理类
class HandleClientProtocol {
public:
    //处理增加金币
    void AddMoney() {
        cout << "给玩家增加金币" << endl;
    }
    //处理增加钻石
    void AddDiamond() {
        cout << "给玩家增加钻石" << endl;
    }
    //处理玩家装备
    void AddEquipemnt() {
        cout << "给玩家穿装备" << endl;
    }
    //处理玩家升级
    void AddLevel() {
        cout << "给玩家升级" << endl;
    }
};

//命令接口
class AbstractCommand {
public:
    virtual void handle() = 0;//处理客户端请求的接口
};

//处理增加金币
class AddMoneyCommand : public AbstractCommand {
public:
    AddMoneyCommand(HandleClientProtocol* protocol) {
        this->pProtocol = protocol;
    }
    virtual void handle() {
        this->pProtocol->AddMoney();
    }
public:
    HandleClientProtocol* pProtocol;
};
//处理增加钻石
class AddDiamondCommand : public AbstractCommand {
public:
    AddDiamondCommand(HandleClientProtocol* protocol) {
        this->pProtocol = protocol;
    }
    virtual void handle() {
        this->pProtocol->AddDiamond();
    }
public:
    HandleClientProtocol* pProtocol;
};
//处理给玩家穿装备
class AddEquipemntCommand : public AbstractCommand {
public:
    AddEquipemntCommand(HandleClientProtocol* protocol) {
        this->pProtocol = protocol;
    }
    virtual void handle() {
        this->pProtocol->AddEquipemnt();
    }
public:
    HandleClientProtocol* pProtocol;
};
//处理给玩家升级
class AddLevelCommand : public AbstractCommand {
public:
    AddLevelCommand(HandleClientProtocol* protocol) {
        this->pProtocol = protocol;
    }
    virtual void handle() {
        this->pProtocol->AddLevel();
    }
public:
    HandleClientProtocol* pProtocol;
};



//服务器程序
class Server {
public:
    void addRequest(AbstractCommand* command) {
        mCommand.push(command);
    }
    void startHandle() {
        while (!mCommand.empty()) {
            Sleep(2000);
            AbstractCommand* command = mCommand.front();
            command->handle();
            mCommand.pop();
        }
    }
public:
    queue<AbstractCommand*> mCommand;
};


void test01() {
    HandleClientProtocol* protocol = new HandleClientProtocol;
    
    AbstractCommand* addmoney = new AddMoneyCommand(protocol);
    AbstractCommand* adddiamond = new AddDiamondCommand(protocol);
    AbstractCommand* addequpment = new AddEquipemntCommand(protocol);
    AbstractCommand* addlevel = new AddLevelCommand(protocol);

    Server* sever = new Server;
    sever->addRequest(addmoney);
    sever->addRequest(adddiamond);
    sever->addRequest(addequpment);
    sever->addRequest(addlevel);
    sever->startHandle();

}

int main(){
    test01();

    return 0;
}
```



# 38 观察者模式

![image-20220722170853746](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220722170853746.png)

![image-20220722170919746](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220722170919746.png)

```c++
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
```



# 39 装饰器模式

![image-20220722172919960](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220722172919960.png)

![image-20220722172928979](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220722172928979.png)

![image-20220722172942680](C:\Users\Administrator\AppData\Roaming\Typora\typora-user-images\image-20220722172942680.png)

```cpp
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
```





