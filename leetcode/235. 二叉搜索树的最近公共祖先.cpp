// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(p->val > q->val) return lowestCommonAncestor(root, q, p);
        if(root->val >= p->val && root->val <= q->val) return root;
        if(root->val > q->val) return lowestCommonAncestor(root->left, p, q);
        if(root->val < p->val) return lowestCommonAncestor(root->right, p, q);
        return nullptr;
    }
};