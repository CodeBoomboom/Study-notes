#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

int lastStoneWeightII(vector<int>& stones) {
    int sum = 0;
    for (int a : stones) sum += a;
    int target = sum / 2;//如果不能整除，则target是向下取整 如sum=7，target=sum/2=3。这也就导致得到的dp[stones.size()-1][target]即重量相同两堆中的一堆总是比另一堆sum-dp[stones.size()-1][target]小

    vector<vector<int>> dp(stones.size(), vector<int>(target + 1, 0));
    for (int b = stones[0]; b <= target; b++)    dp[0][b] = stones[0];//当物品0（石头0）时，若背包容量小于物品0的重量，则为0，否则为stones[0]
    //先物品后背包
    for (int i = 1; i < stones.size(); i++) {
        for (int j = 0; j <= target; j++) {
            if (j < stones[i])   dp[i][j] = dp[i - 1][j];//第j个背包装不下stones[i]
            if (j >= stones[i])  dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i]] + stones[i]);
        }
    }

    return (sum - dp[stones.size() - 1][target]) - dp[stones.size() - 1][target];//最终两堆石头的插值就是粉碎完最小的重量

}

int main(){
    vector<int> stones = { 1,2 };
    lastStoneWeightII(stones);

    return 0;
}