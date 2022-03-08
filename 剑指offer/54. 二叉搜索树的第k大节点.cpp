class Solution {
    int ans;
public:
    void dfs(TreeNode* p, int& k){
        if(!p || !k) return;   // !k 是为了剪枝
        dfs(p->right, k);
        k--;
        if(!k) ans = p->val;
        dfs(p->left, k); 
    }
    int kthLargest(TreeNode* root, int k) {
        dfs(root, k);
        return ans;
    }
};