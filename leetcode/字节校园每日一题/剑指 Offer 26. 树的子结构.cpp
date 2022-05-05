// ###################################################### 版本1 ###################################################### //
// 我的初版，比较奇特
class Solution {
public:
    bool same(TreeNode* a, TreeNode* b){  // b刚好是a从根节点开始的子树
        if(!b) return true;
        if(!a) return false;
        if(a->val != b->val) return false;
        return same(a->left, b->left) && same(a->right, b->right);
    }
    bool dfs(TreeNode* a, TreeNode* b){  // b是a的子树
        if(!b) return true;
        if(!a) return false;
        if(a->val != b->val) return dfs(a->left, b) || dfs(a->right, b);
        return same(a->left, b->left) && same(a->right, b->right) || dfs(a->left, b) || dfs(a->right, b);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!B) return false;
        return dfs(A, B);
    }
};