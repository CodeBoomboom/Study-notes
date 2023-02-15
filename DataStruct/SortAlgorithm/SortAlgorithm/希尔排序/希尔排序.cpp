#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
//希尔排序是直接插入排序的一种变种，对于排序数据量比较大的数据具有较快的速率
void shellSortCore(vector<int>& nums, int gap, int i) {
    int inserted = nums[i];
    int j;
    //  插入的时候按组进行插入
    for (j = i - gap; j >= 0 && inserted < nums[j]; j -= gap) {
        nums[j + gap] = nums[j];
    }
    nums[j + gap] = inserted;//这一步的作用是将nums[i]放到最终的nums[j+gap]上（这个j+gap就是j一直向前遍历最终停在的地方）
}

void shellSort(vector<int>& nums) {
    int len = nums.size();
    //进行分组，最开始的时候，gap为数组长度一半
    for (int gap = len / 2; gap > 0; gap /= 2) {
        //对各个分组进行插入分组
        for (int i = gap; i < len; ++i) {
            //将nums[i]插入到所在分组正确的位置上
            shellSortCore(nums, gap, i);
        }
    }

}




void test01() {
    vector<int> test = { 3,2,1,8,5 };
    shellSort(test);
    for (auto i : test) {
        cout << i;
    }
    cout << endl;
}

int main(){
    test01();

    return 0;
}