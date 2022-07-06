#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

template<class T>
class Animal {
public:
    void Jiao() {
        cout << mAge << "岁动物在叫！" << endl;
    }
    T mAge;
};

//Cat也是模板，不实例化对象
template<class T>
class Cat : public Animal<T> {

};

int main()
{


    printf("\n");
    system("pause");
    return 0;
}