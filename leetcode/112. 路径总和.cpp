/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// ###################################################### 版本2 ###################################################### //
// 递归
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(!root->left && !root->right) return root->val == targetSum;
        if(root->left && hasPathSum(root->left, targetSum - root->val)) return true;
        if(root->right && hasPathSum(root->right, targetSum - root->val)) return true;
        return false;
    }
};

// ###################################################### 版本1 ###################################################### //
// 
class Solution {
public:
    int targetSum;
    bool flag = false;
    void dfs(TreeNode* p, int s){
        if(flag) return;
        if(!p->left && !p->right && s == targetSum) flag = true;
        if(p->left) dfs(p->left, s + p->left->val);
        if(p->right) dfs(p->right, s + p->right->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        this->targetSum = targetSum;
        if(!root) return false;
        dfs(root, root->val);
        return flag;
    }
};