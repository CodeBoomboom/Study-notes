//#include<vector>
//#include<iostream>
//using namespace std;
//
//int fun(vector<int>& a, int n, int x) {
//    if (n == 0)  return 0;
//    //     if(x < 0)    return 0;
//    vector<pair<int, int>> dif;//先找出数组每个元素所对应的v的范围   v范围[a[i]-x,a[i]+x]  v>0
//    dif.reserve(n);
//    for (auto& num : a) {
//        int left = num - x < 0 ? 0 : num - x;
//        int right = num + x;
//        dif.push_back({ left, right });
//    }
//    vector<pair<int, int>> over;
//    over.push_back(dif[0]);//先把第一个push进去，表示一开始v的范围，然后从第一个开始模拟
//    for (int i = 1; i < n; i++) {
//        int left = max(over.back().first, dif[i].first);//收缩范围才能满足下一个，左边界取大的，右边界取小的
//        int right = min(over.back().second, dif[i].second);
//        if (left < right) {//如果此时还满足left<right说明v在left到right范围内还可以满足，只需要更新数组最后一个元素即可
//            over.back().first = left;
//            over.back().second = right;
//        }
//        else {//否则就说明v不能满足了，那么就要变化一次伪装，需要重新添加一个dif
//            over.push_back(dif[i]);
//        }
//    }
//    return over.size() - 1;  //变化伪装的次数不包括初始值
//}
//
//
//
//
//int main() {
//    int n, x;
//    while (cin >> n >> x) {
//        vector<int> a(n, 0);
//        for (int i = 0; i < n; i++) {
//            cin >> a[i];
//        }
//        cout << fun(a, n, x) << endl;
//    }
//
//
//
//    return 0;
//}
//
//

#include<iostream>
#include<vector>
using namespace std;

//需要考虑多个连续最长1的子串，要加起来
//1、dp[i]表示以i为结尾连续1的个数为dp[i]
//2、递推公式：
//    如果str[i] == 1，      并且str[i-1] ==1, 那么dp[i] = dp[i-1] + 1， 若str[i-1] !=   1 那么dp[i]重置，dp[i] = 1
//    不为1的话        dp[i] = 0
//3、初始化：长度为1的：dp[0] = str[0] - '0'
int fun(string& str, int n) {
    int i = 0, j = -1;
    vector<int> dp(n, 0);
    dp[0] = str[0] - '0';
    int max = dp[0];
    for (int i = 1; i < n; ++i) {
        if (str[i] == '1') {
            if (str[i - 1] == '1')    dp[i] = dp[i - 1] + 1;
            else dp[i] = 1;
        }
        else {
            dp[i] = 0;
        }
        if (dp[i] > max) {
            max = dp[i];
        }
    }
    if (max == 0)  return 0;
    vector<pair<int, int>> spaces;
    for (int i = 0; i < n; i++) {
        if (dp[i] == max) {
            spaces.push_back({ i - max + 1, i });//子串的区间加进去，dp[i]可能一样，即可能有多个相同长度的最大连续子串
        }
    }
    long long res = 0;
    int left_pre = -1;
    for (auto& space : spaces) {//对每个区间均计算
        auto left = space.first;
        auto right = space.second;
        long long cur = (long long)(left - left_pre) * (n - right);//从每个子串向左向右取
        res += cur;
        left_pre = left;//为了防止重复，左边的子串已经取过了
    }
    return res % (1000000007);
}

int main() {
    int n;
    while (cin >> n) {
        string str;
        cin >> str;
        cout << fun(str, n) << endl;
    }



    return 0;
}