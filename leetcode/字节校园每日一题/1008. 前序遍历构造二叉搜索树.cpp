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
    TreeNode* dfs(vector<int>& vec, int l, int r){
        if(l > r) return nullptr;
        auto p = new TreeNode(vec[l]);
        int i = l + 1;
        while(i <= r && vec[i] < vec[l]) i++;
        p->left = dfs(vec, l + 1, i - 1);
        p->right = dfs(vec, i, r);
        return p;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return dfs(preorder, 0, preorder.size() - 1);
    }
};