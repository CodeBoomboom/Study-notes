#include<iostream>
#include<vector>
using namespace std;

int getMax(vector<int>& vec, int n, int k, int x) {
    while (k--) {
        int maxi = 0;//最大值下标
        for (int i = 0; i < vec.size(); i++) {
            maxi = vec[maxi] > vec[i] ? maxi : i;
        }
        vec[maxi] -= x;
    }
    //找最大值
    int max = INT_MIN;
    for (auto& i : vec) {
        max = max > i ? max : i;
    }
    return max;
}


int main() {
    int n, k, x;//n数组大小k操作次数x每次减去的数
    cin >> n >> k >> x;
    int temp;
    vector<int> vec;
    while (cin >> temp) {
        vec.push_back(temp);
        if (cin.get() == '\n') break;
    }
    int result = getMax(vec, n, k, x);
    cout << result << endl;


    return 0;
}