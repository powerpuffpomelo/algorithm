// ###################################################### 版本1 ###################################################### //
// 我的初版
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
    int ans = 0;
    void dfs(TreeNode* p, int vmax){
        if(p->val >= vmax) ans++;
        if(p->left) dfs(p->left, max(vmax, p->left->val));
        if(p->right) dfs(p->right, max(vmax, p->right->val));
    }
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return ans;
    }
};