#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
//冒泡排序：
//1.比较相邻的元素，若第一个元素比第二个大，就交换它们两个
//2.对每一对相邻的元素做同样的操作，从前向后，这样完成一圈，最后的元素就是最大的数
//3.每次对越来越少的元素重复以上步骤，直到没有一个数字需要比较。

void bubbleSort(vector<int>& nums) {

    int len = nums.size();
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (nums[j] > nums[j + 1])  swap(nums[j], nums[j + 1]);
        }
    }
}





void test01() {
    vector<int> test = { 3,2,1,8,5};
    bubbleSort(test);
    for (auto i : test) {
        cout << i ;
    }
    cout << endl;
	
}

int main(){
    test01();

    return 0;
}