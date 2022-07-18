#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void test01() {
	
}

int main(){
    string s;
    while (cin >> s) {
        if (cin.get() == '\n') break;
    }
    cout << s.size();
    return 0;
}