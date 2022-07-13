#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    //递归
    TreeNode* traversal(vector<int>& nums, TreeNode* root){
        
        if(nums.size() == 1){
            root = new TreeNode(0);
            root->val = nums[0];
            return root;
        }

        int maxValue = 0;
        int maxValueIndex = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]>maxValue){
                maxValue = nums[i];
                maxValueIndex = i;
            }
        }
        if(root == NULL){
            root = new TreeNode(0);
        }
        root->val = maxValue;

        //左子树
        if(maxValueIndex > 0){
            vector<int> left(nums.begin(), nums.begin()+maxValueIndex);
            root->left = traversal(left, root->left);
        }
        //右子树
        if(maxValueIndex<nums.size()-1){
            vector<int> right(nums.begin()+maxValueIndex+1, nums.end());
            root->right = traversal(right, root->right);
        }

        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = new TreeNode(0);
        traversal(nums, root);
        return root;
    }
};

int main(){
    Solution s;
    int arr[] = {3};
    vector<int> nums(arr, arr + sizeof(arr)/sizeof(int));
    TreeNode* result = s.constructMaximumBinaryTree(nums);

    return 0;
}

