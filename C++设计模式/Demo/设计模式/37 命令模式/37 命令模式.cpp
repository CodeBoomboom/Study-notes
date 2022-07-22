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