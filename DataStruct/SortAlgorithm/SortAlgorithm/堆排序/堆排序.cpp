#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
//归并排序

//合并
void merge(vector<int>& nums, vector<int>& temp, int left, int mid, int right) {
    //标记左半区和右半区未排序的第一个元素
    int l_pos = left;
    int r_pos = mid + 1;
    //临时数组元素的下标
    int pos = left;

    //合并
    while (l_pos <= mid && r_pos <= right) {
        if (nums[l_pos] < nums[r_pos]) {//左半区第一个元素更小
            temp[pos++] = nums[l_pos++];
        }
        else {//右半区第一个元素更小
            temp[pos++] = nums[r_pos++];
        }
    }

    //合并左半区剩余的元素（将合并完剩余的元素放进temp，也就是左半区/右半区只剩一个元素的情况）
    while (l_pos <= mid)     temp[pos++] = nums[l_pos++];
    //合并右半区剩余的元素
    while (r_pos <= mid)     temp[pos++] = nums[r_pos++];

    //把临时数组中合并后的元素复制回nums数组
    while (left <= right) {
        nums[left] = temp[left];
        left++;
    }
}

//
void MSort(vector<int>& nums, vector<int>& temp, int left, int right) {

    if (left < right) {//只有left<right即left和right之间的元素个数大于1才划分（如果等于1，那么返回递归上层执行merge合并操作）
        int mid = (left + right) / 2;//从中间划分
        MSort(nums, temp, left, mid);//对左半部分归并排序
        MSort(nums, temp, mid + 1, right);//对右半部分归并排序
        merge(nums, temp, left, mid, right);//归并
    }
}

//归并函数入口（搞这个入口的目的是为了分配temp数组，不然的话就只能在逻辑外自己创建temp数组了）
void MergeSort(vector<int>& nums) {
    vector<int> temp(nums.size());//分配一个辅助数组
    MSort(nums, temp, 0, nums.size() - 1);
}




void test01() {
    vector<int> test = { 3,2,1,8,5 };
    MergeSort(test);
    for (auto i : test) {
        cout << i;
    }
    cout << endl;
}

int main() {
    test01();

    return 0;
}