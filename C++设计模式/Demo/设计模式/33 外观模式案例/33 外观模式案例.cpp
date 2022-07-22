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