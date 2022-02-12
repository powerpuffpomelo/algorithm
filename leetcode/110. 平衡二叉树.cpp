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
    bool flag = true;
    int dfs(TreeNode* root){
        if(!flag) return 0;
        if(!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if(left - right > 1 || right - left > 1){
            flag = false;
            return 0;
        }
        int h = max(left, right) + 1;
        return h;
    }
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return flag;
    }
};