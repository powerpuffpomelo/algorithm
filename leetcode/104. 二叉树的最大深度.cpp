// ###################################################### 版本2 ###################################################### //
// 其实一行代码就能搞定
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return root ? max(maxDepth(root->left), maxDepth(root->right)) + 1 : 0;
    }
};

// ###################################################### 版本1 ###################################################### //
// dfs
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int l = maxDepth(root->left), r = maxDepth(root->right);
        return max(l, r) + 1;
    }
};

// ###################################################### 版本3 ###################################################### //
// dfs
class Solution {
public:
    int ans = 0;
    void dfs(TreeNode* root, int depth){
        if(!root) return;
        ans = max(ans, depth);
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
    int maxDepth(TreeNode* root) {
        dfs(root, 1);
        return ans;
    }
};