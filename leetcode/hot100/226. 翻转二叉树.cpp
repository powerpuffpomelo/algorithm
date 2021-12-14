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

// ###################################################### 版本1 ###################################################### //
// 我写的原版

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode* revert_root = new TreeNode;
        revert_root -> val = root -> val;
        revert_root -> left = invertTree(root -> right);
        revert_root -> right = invertTree(root -> left);
        return revert_root;
    }
};

// ###################################################### 版本1 ###################################################### //
// 在原树基础上修改，节省空间

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        TreeNode* left = invertTree(root -> right);
        TreeNode* right = invertTree(root -> left);
        root -> left = left;
        root -> right = right;
        return root;
    }
};