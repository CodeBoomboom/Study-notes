#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//依赖倒转原则

//传统的业务层-中层-底层模式
#if 0
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
#endif

//依赖倒转原则：业务层-抽象层-具体实现  都依赖于抽象层

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

//业务模块
void doNewBusiness(AbstractWorker* worker) {
    worker->doBusiness();
    delete worker;
}

void test02() {
    AbstractWorker* transfer = new TransferBankWoker;
    doNewBusiness(transfer);
    doNewBusiness(new SaveBankWoker);
}

int main()
{
    test02();
    return 0;
}