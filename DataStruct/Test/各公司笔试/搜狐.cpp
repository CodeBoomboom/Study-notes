#include<iostream>
using namespace std;


int main() {
    int n, k, t;
    cin >> n >> k >> t;
    string s;
    if (k > n)   cout << -1 << endl;
    else if (2 * t > n) cout << -1 << endl;
    else {
        for (int i = 0; i < t; i++) {
            s += "11";
        }
        for (int i = 0; i < k - 2 * t; i++) {
            s += "01";
        }
        for (int i = 0; i < (n - k) - (k - 2 * t); i++) {
            s += "0";
        }
        cout << s;
    }

    return 0;
}