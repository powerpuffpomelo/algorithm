class Solution {
public:
    bool issame(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;
        return issame(p->left, q->left) && issame(p->right, q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(issame(root, subRoot)) return true;
        if(!root || !subRoot) return false;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};