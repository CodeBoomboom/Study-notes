#include <iostream>
#include <string>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};



int sum = 0;
vector<vector<int>>  traversal(TreeNode* root) {
    vector<vector<int>> paths;
    if (root == nullptr) return paths;
    stack<TreeNode*> st;
    stack<vector<int>> sst;
    vector<int> first;
    first.push_back(root->val);
    sst.push(first);
    st.push(root);
    while (!st.empty()) {
        TreeNode* cur = st.top();
        st.pop();
        vector<int> scur = sst.top();
        sst.pop();
        sum += cur->val;
        if (!cur->left && !cur->right) {
            paths.push_back(scur);
        }
        if (cur->right) {
            st.push(cur->right);
            sst.push(scur);
            sst.top().push_back(cur->right->val);
        }
        if (cur->left) {
            st.push(cur->left);
            sst.push(scur);
            sst.top().push_back(cur->left->val);

        }
    }
    return paths;
}

int res = 0;
int  fun(vector<vector<int>>& paths){
    int midSum = 0;

    for (int i = 0; i < paths.size(); i++) {
        vector<int> curPath = paths[i];
        int preSum = curPath[0], lastSum = curPath[curPath.size()-1];
        int left = 0, right = curPath.size()-1;
        while (left < right-2) {
            if (preSum > lastSum) {
                right--;
                lastSum += curPath[right];
            }
            else if (preSum < lastSum) {
                left++;
                preSum += curPath[left];
            }
            else if (preSum == lastSum && (right - left > 1)) {
                left++; right--;
                lastSum += curPath[right];
                preSum += curPath[left];
            }
        }
        int mid = curPath[left+1];
        midSum += mid;
    }
    return sum - midSum;
}

int f(TreeNode* root) {
    vector<vector<int>> paths = traversal(root);
    int res = fun(paths);
    return res;
}

// 请按你的实际需求修改参数和返回值类型
int main( )
{
    //TreeNode* root = new TreeNode(7);
    //root->left = new TreeNode(6);
    //root->left->left = new TreeNode(3);
    //root->left->left->left = new TreeNode(11);
    //root->left->left->left->left = new TreeNode(2);
    //root->right = new TreeNode(5);
    //root->right->left = new TreeNode(4);
    //root->right->left->left = new TreeNode(1);
    //root->right->left->right = new TreeNode(3);
    //root->right->left->left->right = new TreeNode(16);
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);

    root->left->left->left = new TreeNode(1);
    root->left->left->right = new TreeNode(1);
    root->left->left->right->left = new TreeNode(4);
    root->left->left->right->right = new TreeNode(2);
    //fun(root);
    //vector<vector<int>> res = traversal(root);
    int res = f(root);
    cout << res << endl;


    return 0;

}