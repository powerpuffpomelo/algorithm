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