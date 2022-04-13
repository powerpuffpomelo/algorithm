class Solution {
public:
    bool flag = true;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int left = dfs(root->left), right = dfs(root->right);
        if(left - right > 1 || left - right < -1) flag = false;
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return flag;
    }
};