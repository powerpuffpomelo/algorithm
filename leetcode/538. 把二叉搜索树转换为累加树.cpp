// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int sum = 0;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->right);
        root->val = sum = sum + root->val;
        dfs(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
};