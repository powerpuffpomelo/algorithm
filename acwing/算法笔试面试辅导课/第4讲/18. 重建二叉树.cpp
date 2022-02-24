/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// ###################################################### 版本2 ###################################################### //
// 更简洁一点的方法，事先pos打表，查询位置O(1)，总时间复杂度O(n)
class Solution {
public:
    unordered_map<int, int> pos;
    
    TreeNode* dfs(vector<int>& pre, vector<int>& in, int pl, int pr, int il, int ir){
        if(pl > pr) return nullptr;
        TreeNode* root = new TreeNode(pre[pl]);
        int k = pos[pre[pl]] - il;
        root -> left = dfs(pre, in, pl + 1, pl + k, il, il + k - 1);
        root -> right = dfs(pre, in, pl + k + 1, pr, il + k + 1, ir);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i = 0; i < n; i++) pos[inorder[i]] = i;
        return dfs(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int l1, int r1, int l2, int r2){
        if(l1 > r1) return nullptr;
        TreeNode *root = new TreeNode(preorder[l1]);
        int p = l2;
        while(inorder[p] != root -> val) p++;
        int llen = p - l2, rlen = r2 - p;
        root -> left = dfs(preorder, inorder, l1 + 1, l1 + llen, l2, l2 + llen - 1);
        root -> right = dfs(preorder, inorder, l1 + llen + 1, r1, l2 + llen + 1, r2);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = dfs(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
        return root;
    }
};