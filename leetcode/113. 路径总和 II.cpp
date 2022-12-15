// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(TreeNode* root, int targetSum, vector<int>& temp, int s){
        if(!root) return;
        s += root->val;
        temp.push_back(root->val);
        if(!root->left && !root->right){
            if(s == targetSum) ans.push_back(temp);
        }
        if(root->left) dfs(root->left, targetSum, temp, s);
        if(root->right) dfs(root->right, targetSum, temp, s);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        dfs(root, targetSum, temp, 0);
        return ans;
    }
};