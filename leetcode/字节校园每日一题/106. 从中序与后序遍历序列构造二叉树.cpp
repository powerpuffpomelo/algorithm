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
    unordered_map<int, int> x2p;
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int il, int ir, int pl, int pr){
        if(il > ir) return nullptr;
        int x = postorder[pr];
        int len = x2p[x] - il;
        TreeNode* root = new TreeNode(x);
        root->left = build(inorder, postorder, il, il + len - 1, pl, pl + len - 1);
        root->right = build(inorder, postorder, il + len + 1, ir, pl + len, pr - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i = 0; i < n; i++) x2p[inorder[i]] = i;
        int il = 0, ir = n - 1, pl = 0, pr = n - 1;
        return build(inorder, postorder, il, ir, pl, pr);
    }
};