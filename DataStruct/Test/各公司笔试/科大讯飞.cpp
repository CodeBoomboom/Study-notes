#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void fun(vector<long long>& xn, long long N, vector<long long>& result) {
    long long temp1 = 0;
    long long temp2 = 0;
    for (int k = 0; k < N; k++) {
        for (int n = 0; n <= (N - k - 1); n++) {
            temp1 += xn[n] * xn[n + k];
        }
        if (N - k <= N - 1) {
            for (int n1 = N - k; n1 <= (N - 1); n1++) {
                temp2 += xn[n1] * xn[n1 + k - N];
            }
        }
        else {
            temp2 = 0;
        }
        result[k] = (long long)(temp1 + temp2);
        temp1 = 0;
        temp2 = 0;
    }
}

bool maxNum(vector<long long>& result, long long& maxresult) {\
    int len = result.size();
    if (len == 1) return false;
    for (int i = 0; i < len - 1; i++) { //ÅÅ³ýr(0£©
        result[i] = abs(result[i + 1]);
    }
    result.resize(len - 1);
    vector<long long> max;
    int pre = 0, cur = 1, next = 2;
    if (result.size() == 1) {
        maxresult = result[0];
        return true;
    }
    else if (result.size() == 2) {
        maxresult = result[0] > result[1] ? result[0] : result[1];
        return true;
    }
    else {
        while (next < result.size()) {
            if (result[cur] > result[pre] && result[cur] > result[next]) {
                max.push_back(result[cur]);
            }
            pre++;
            cur++;
            next++;
        }
        if (!max.empty()) {
            for (auto& i : max) {
                maxresult = maxresult > i ? maxresult : i;
            }
            return true;
        }
       else return false;
    }
    return  false;
}

int main() {
    long long N;
    cin >> N;
    long long xn;
    vector<long long> xnVec;
    while (cin >> xn) {
        xnVec.push_back(xn);
        if (cin.get() == '\n') break;
    }
    vector<long long> result(N);
    fun(xnVec, N, result);
    for (int i = 0; i < result.size(); i++) {
        if (i == result.size() - 1) {
            cout << result[i];
        }
        else {
            cout << result[i] << " ";
        }
    }
    cout << endl;
    long long maxresult = 0;
    if (maxNum(result, maxresult)) {
        cout << maxresult << endl;
    }
    else {
        cout << "NO" << endl;
    }


    return 0;
}