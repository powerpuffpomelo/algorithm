// ###################################################### 版本2 ###################################################### //
// 放在一个二维数组就可以啦！
class Solution {
public:
    unordered_map<TreeNode*, unordered_map<int, int>> dp;  // 二维数组，键不是int，可以通通unordered_map搞定
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        dfs(root->right);
        dp[root][1] = root->val + dp[root->left][0] + dp[root->right][0];
        dp[root][0] = max(dp[root->left][0], dp[root->left][1]) + max(dp[root->right][0], dp[root->right][1]);
    }
    int rob(TreeNode* root) {
        dfs(root);
        return max(dp[root][0], dp[root][1]);
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版，两个dp数组
class Solution {
public:
    unordered_map<TreeNode*, int> f, g;
    void cal(TreeNode* root){
        if(!root) return;
        cal(root->left);
        cal(root->right);
        f[root] = root->val + g[root->left] + g[root->right];
        g[root] = max(f[root->left], g[root->left]) + max(f[root->right], g[root->right]);
    }
    int rob(TreeNode* root) {
        f[nullptr] = 0;
        g[nullptr] = 0;
        cal(root);
        return max(f[root], g[root]);
    }
};