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
    int ans = -1010;
    int dfs(TreeNode* root){
        if(root == nullptr) return 0;
        int res = root -> val;
        int ll = max(dfs(root -> left), 0);
        int rr = max(dfs(root -> right), 0);
        ans = max(ans, res + ll + rr);
        return res + max(ll, rr);
    }

public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};