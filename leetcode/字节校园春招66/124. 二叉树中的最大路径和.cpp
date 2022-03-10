class Solution {
public:
    int ans = -1010;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int ret;
        int ll = dfs(root->left), rr = dfs(root->right);
        ret = root->val + max(max(ll, rr), 0);
        ans = max(ans, ret);
        ans = max(ans, ll + rr + root->val);
        return ret;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};