#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

vector<int> fun(int p, int q, vector<int>& sumVec, vector<int>& mainVec) {
    vector<int> result;
    unordered_map<int, int> map;
    for (vector<int>::iterator i = mainVec.begin(); i != mainVec.end(); i++) {
        for (vector<int>::iterator j = sumVec.begin(); j != sumVec.end(); ) {
            if (*i == *j) {
                map[*i]++;
                j = sumVec.erase(j);
            }
            else {
                j++;
            }
        }
    }
    for (auto& i : mainVec) {
        for (int j = map[i]; j > 0; j--) {
            result.push_back(i);
        }
    }
    sort(sumVec.begin(), sumVec.end());
    for (auto& i : sumVec) {
        result.push_back(i);
    }

    return result;
}

int main() {
    int p, q;
    cin >> p >> q;
    vector<int> sumVec;
    vector<int> mainVec;
    int temp = 0;
    while (cin >> temp) {
        sumVec.push_back(temp);
        if (cin.get() == '\n') break;
    }
    while (cin >> temp) {
        mainVec.push_back(temp);
        if (cin.get() == '\n') break;
    }

    vector<int> result = fun(p, q, sumVec, mainVec);
    for (int i = 0; i < result.size(); i++) {
        if (i == result.size() - 1)    cout << result[i];
        else cout << result[i] << " ";
    }


    return 0;
}





////另一种解法
//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<string>
//#include<vector>
//#include<algorithm>
//#include<unordered_map>
//using namespace std;
//
//vector<int> fun(int p, int q, vector<int>& sumVec, vector<int>& mainVec) {
//    vector<int> result;
//    vector<int> temp;
//    unordered_map<int, int> map;
//    //记录sumVec中mainVec元素的个数
//    //将sumVec中的mainVec元素取出后加到temp
//    for (auto i : sumVec) {
//        for (auto j : mainVec) {
//            if (i == j) {
//                map[i]++;
//            }
//        }
//    }
//    for (auto i : sumVec) {
//        if (map[i] > 0) {
//        }
//        else {
//            temp.push_back(i);
//        }
//    }
//    for (auto& i : mainVec) {
//        for (int j = map[i]; j > 0; j--) {
//            result.push_back(i);
//        }
//    }
//    sort(temp.begin(), temp.end());
//    for (auto& i : temp) {
//        result.push_back(i);
//    }
//
//    return result;
//}
//
//int main() {
//    int p, q;
//    cin >> p >> q;
//    vector<int> sumVec;
//    vector<int> mainVec;
//    int temp = 0;
//    while (cin >> temp) {
//        sumVec.push_back(temp);
//        if (cin.get() == '\n') break;
//    }
//    while (cin >> temp) {
//        mainVec.push_back(temp);
//        if (cin.get() == '\n') break;
//    }
//
//    vector<int> result = fun(p, q, sumVec, mainVec);
//    for (int i = 0; i < result.size(); i++) {
//        if (i == result.size() - 1)    cout << result[i];
//        else cout << result[i] << " ";
//    }
//
//
//    return 0;
//}
