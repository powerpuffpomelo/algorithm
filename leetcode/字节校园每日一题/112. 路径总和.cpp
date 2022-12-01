// ###################################################### 版本1 ###################################################### //
// 
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