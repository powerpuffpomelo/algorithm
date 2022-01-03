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
    int ans = 0;
    int cal_depth(TreeNode* root){
        if(!root) return 0;
        int L = cal_depth(root -> left);
        int R = cal_depth(root -> right);
        ans = max(ans, L + R);
        return max(L, R) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root){
        cal_depth(root);
        return ans;
    }
};