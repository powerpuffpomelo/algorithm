// todo：研究其它方法

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> father;
    unordered_map<TreeNode*, int> height;

    void dfs(TreeNode* root, int h){
        if(root->left){
            father[root->left] = root;
            height[root->left] = h + 1;
            dfs(root->left, h + 1);
        }
        if(root->right){
            father[root->right] = root;
            height[root->right] = h + 1;
            dfs(root->right, h + 1);
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        height[root] = 1;
        father[root] = nullptr;
        dfs(root, 1);
        while(height[p] < height[q]) q = father[q];
        while(height[q] < height[p]) p = father[p];
        while(p != q){
            p = father[p];
            q = father[q];
        }
        return p;
    }
};