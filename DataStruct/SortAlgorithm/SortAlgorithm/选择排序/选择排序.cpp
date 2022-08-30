#include<iostream>
#include<vector>
using namespace std;
//选择排序
//从第一个元素开始，比较当前元素与剩下元素中最小的值的大小，如果比剩余元素最小的值大，那么交换两个元素的位置
//依次向后类推，直到最后一个元素
//选择排序是一个不稳定的排序，比如说数组为{5,5,2,8}，那么第一个5首先与2交换位置，这样原来的第一个5和第二个5的先后次序就颠倒了，所以是不稳定排序


void selectSort(vector<int>& nums) {
    int len = nums.size();
    int minIndex = 0;
    for (int i = 0; i < len; i++) {
        minIndex = i;//每次都要重置minIndex为i
        for (int j = i + 1; j < len; j++) {
            if (nums[j] < nums[minIndex])    minIndex = j;
        }
        swap(nums[i], nums[minIndex]);
    }
}

int main() {
    vector<int> test = { 3,2,1 };
    selectSort(test);
    for (auto i: test) {
        cout << i;
    }
    cout << endl;

    return 0;
}