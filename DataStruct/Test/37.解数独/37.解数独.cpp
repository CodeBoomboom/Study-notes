#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void test01() {
    int row = 2;
    int col = 5;
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    cout << startRow << startCol << endl;

}

int main() {
    test01();

    return 0;
}