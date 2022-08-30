#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

//快排序
//先选择一个基准，这里选择第一个为基准
//然后高位指针high先从后向前找到第一个比基准小的值，记录其下标
//然后低位指针low从前向后找到第一个比基准大的值，记录其下标
//交换这两个值
//重复，直到基准值左边都是比其大的，右边都是比其小的
//然后递归对基准值左边区间、右边区间依次进行以上过程

void quickSort(vector<int>& nums, int low, int high) {
    //终止条件
    if (low >= high) return;

    int first = low;//
    int last = high;
    int key = nums[first];//基准值

    while (first < last) {

        while (first < last && nums[last] > key)    last--;//last指针从后向前找第一个比key小的
        if (first < last)   nums[first++] = nums[last];//将first指针指向的换为这个数，低位指针first+1

        while (first < last && nums[first] <= key)    first++;//first指针从前向后找第一个比key大的
        if (first < last) nums[last--] = nums[first];//将last指针指向的换为这个数，高位指针last-1
    }
    nums[first] = key;//将基准值添加到最后的中间位置
    //左子区间递归上述操作
    quickSort(nums, low, first - 1);

    //右子区间递归上述操作
    quickSort(nums, first + 1, high);


}


void printfVector(vector<int>& nums) {
    for (auto& i : nums) {
        cout << i;
    }
    cout << endl;
}

void test01() {
    vector<int> test = { 3,2,1,4 };

    quickSort(test, 0, test.size() - 1);
    printfVector(test);

}

int main(){
    test01();

    return 0;
}