#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//区间1和2重叠：区间1的end > 区间2的start （等于算不算？）
//先按end排序从小到大
static bool mycmp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> result;
    if (intervals.size() == 0) return result;
    sort(intervals.begin(), intervals.end(), mycmp);

    //若有重叠则将区间1（上一区间）的begin和区间2（当前区间）的end组合成新区间加入result，并向后移一个区间
    //若没有重叠则直接将上一区间加入result
    //定义一个flag来判断最后一个区间有没有合并
    bool flag = false;
    for (int i = 1; i < intervals.size(); i++) {
        int start = 0, end = 0;
        if (intervals[i][0] < intervals[i - 1][1]) {
            //重叠：区间1的end > 区间2的start
            //将区间1的begin和区间2的end组合成新区间加入result
            if (i == intervals.size() - 1) {
                flag = true;    //说明最后一个区间被合并了
            }
            start = intervals[i - 1][0];
            end = intervals[i][1];
            i++;//向后移一位，因为当前区间已经和上一区间完成合并了
        }
        else {
            //不重叠，直接将区间1加入result
            start = intervals[i - 1][0];
            end = intervals[i - 1][1];
        }
        result.push_back({ start, end });//加入
    }
    if (flag = false) {//最后一个区间未被合并
        result.push_back({ intervals[intervals.size()][0], intervals[intervals.size()][1] });
    }
    return result;
}


int main(){
    int i = 0;
    for (i = 0; i < 5; i++) {

    }
    cout << i << endl;
    return 0;
}