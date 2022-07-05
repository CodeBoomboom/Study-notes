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

![img](file:///C:/Users/Administrator/AppData/Local/Packages/oice_16_974fa576_32c1d314_11ba/AC/Temp/msohtmlclip1/01/clip_image002.jpg)

这时候，运行测试一波

![img](file:///C:/Users/Administrator/AppData/Local/Packages/oice_16_974fa576_32c1d314_11ba/AC/Temp/msohtmlclip1/01/clip_image004.jpg)

 

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



# 19 简单工厂模式-代码实现
