#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
vector<int> vec;
void travserval(TreeNode* root) {
    if (root == NULL)    return;
    travserval(root->left);
    vec.push_back(root->val);
    travserval(root->right);
}
vector<int> findMode(TreeNode* root) {
    travserval(root);
    vector<int> result;
    int pre = INT_MAX;
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
        if (*it == pre) {
            if (result.empty()) {
                result.push_back(pre);
                result.push_back(*it);
            }
            else {
                if (result.back() == *it) {
                    result.push_back(*it);
                }
                else {
                    result.push_back(pre);
                    result.push_back(*it);
                }
            }

        }
        pre = *it;
    }
    return result;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);
    vector<int> ret;

    ret = findMode(root);
}