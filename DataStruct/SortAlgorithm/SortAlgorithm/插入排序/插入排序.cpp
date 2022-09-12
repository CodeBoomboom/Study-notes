#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

//插入排序
//在一个已经有序的小序列的基础上一次插入一个元素
//刚开始这个有序的小序列只有1个元素，就是第一个元素
//比较是从有序序列的末尾开始，也就是将想要插入的元素和已经有序的最大元素对比
//若比它大则直接插入在最后面，如果比它大那么一直向前找直到找到该插入的位置
//如果碰到一个与想插入的元素相等的元素，那么会将其放在相等元素的后面，这就保证了序列的稳定性没有改变，所以说插入排序是一个稳定性排序

void insertSort(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++)//从1开始遍历
    {
        //只有当第i个小于第i-1个才进行插入排序，否则直接查到最后面（也就是不用动）就行
        if (nums[i] < nums[i - 1]) {
            int val = nums[i];//记录一下，因为后面会移动覆盖
            int j = i - 1;//记录有序序列最后一个元素下标，用来遍历
            while (j >= 0 && nums[j] > val)//val小于nums[j]的话才继续向前找插入的位置
            {
                //更新位置，全部向后移
                nums[j + 1] = nums[j];
                j--;//继续向前找
            }
            //找到位置了，直接插入
            nums[j+1] = val;
        }
    }
}



void printfVector(vector<int>& nums) {
    for (auto& i : nums) {
        cout << i;
    }
    cout << endl;
}

void test01() {
    vector<int> test = { 3,2,1 };
    insertSort(test);

    printfVector(test);

}

int main(){
    test01();
    //string a = "111";
    //int b = atoi(a.c_str());
    //cout << b;
    return 0;
}