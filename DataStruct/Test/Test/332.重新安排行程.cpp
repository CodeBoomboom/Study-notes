#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<unordered_map>
using namespace std;

 //unordered_map<出发机场, map<到达机场, 航班次数>> targets
unordered_map<string, map<string, int>> targets;
bool backtracking(int ticketNum, vector<string>& result) {
    if (result.size() == ticketNum + 1) {
        return true;
    }
    for (pair<const string, int>& target : targets[result[result.size() - 1]]) {
        if (target.second > 0) { // 记录到达机场是否飞过了
            result.push_back(target.first);
            target.second--;
            if (backtracking(ticketNum, result)) return true;
            result.pop_back();
            target.second++;
        }
    }
    return false;
}


vector<string> findItinerary(vector<vector<string>>& tickets) {
    targets.clear();
    vector<string> result;
    for (const vector<string>& vec : tickets) {
        targets[vec[0]][vec[1]]++; // 记录映射关系
    }
    result.push_back("JFK"); // 起始机场
    backtracking(tickets.size(), result);
    return result;
}


int main() {
    vector<vector<string>> t = { {"JFK", "KUL"},  { "JFK", "NRT" },  { "NRT", "JFK" } };
    vector<string> ret = findItinerary(t);
    for (auto& i : ret) {
        cout << i << endl;
    }
    return 0;
}