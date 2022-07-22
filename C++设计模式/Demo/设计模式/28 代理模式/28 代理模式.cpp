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