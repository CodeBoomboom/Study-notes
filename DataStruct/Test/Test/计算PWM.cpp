#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
    string str = {};
    char ch = {};
    getline(cin, str);
    cin >> ch;
    map<char, size_t> mul;
    for (auto i : str) {
        char temp = tolower(i);
        mul[temp] +=1;
    }
    cout << mul[tolower(ch)] << endl;

}