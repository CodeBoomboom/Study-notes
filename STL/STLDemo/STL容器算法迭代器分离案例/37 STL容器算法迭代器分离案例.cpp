#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//算法，负责统计某个元素的个数
int mycount(int* begin, int* end, int val) {
    int num = 0;
    while (begin != end) {
        if (*begin == val) {
            num++;
        }
        begin++;
    }
    return num;
}


int main()
{

    //数组 容器
    int arr[] = { 0,7,5,4,9,2,0 };
    int* begin = arr;   //迭代器开始位置
    int* end = &(arr[sizeof(arr) / sizeof(int)]);

    int num = mycount(begin, end, 0);
    cout << "num:" << num << endl;
    system("pause");
    return 0;
}