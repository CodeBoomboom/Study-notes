#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//³åÅÝ¹ý³Ì
class DrinkTemplate {
public:
    virtual void BoilWater() = 0;//ÖóË®
    virtual void Brew() = 0;//³åÅÝ
    virtual void PourInCup() = 0;//µ¹Èë±­ÖÐ
    virtual void AddSomething() = 0;//¼Ó¸¨ÖúÁÏ

    //Ä£°å·½·¨
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
        cout << "Öó´¿¾»Ë®..." << endl;
    }
    virtual void Brew() {
        cout << "³åÅÝ¿§·È" << endl;
    }
    virtual void PourInCup() {
        cout << "½«¿§·Èµ¹Èë±­ÖÐ" << endl;
    }
    virtual void AddSomething() {
        cout << "¿§·È¼ÓÈëÌÇ£¬Å£ÄÌ" << endl;
    }
};

class Tea :public DrinkTemplate {
public:
    virtual void BoilWater() {
        cout << "ÖóÉ½ÈªË®..." << endl;
    }
    virtual void Brew() {
        cout << "³åÅÝÎ÷ºþÁú¾®" << endl;
    }
    virtual void PourInCup() {
        cout << "½«²èµ¹Èë±­ÖÐ" << endl;
    }
    virtual void AddSomething() {
        cout << "²èÒ¶¼ÓÈëÄûÃÊ" << endl;
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