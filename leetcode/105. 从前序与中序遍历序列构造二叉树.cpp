// ###################################################### 版本2 ###################################################### //
// 更简洁一点啦，打表存pos
class Solution {
public:
    unordered_map<int, int> pos;

    TreeNode* dfs(vector<int>& pre, vector<int>& in, int pl, int pr, int il, int ir){
        if(pl > pr) return nullptr;
        int k = pos[pre[pl]] - il;
        TreeNode* root = new TreeNode(pre[pl]);
        root->left = dfs(pre, in, pl + 1, pl + k, il, il + k - 1);
        root->right = dfs(pre, in, pl + k + 1, pr, il + k + 1, ir);
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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir){
        if(pl > pr) return nullptr;
        auto root = new TreeNode(preorder[pl]);
        int pos = il;
        while(inorder[pos] != preorder[pl]) pos++;
        int l_len = pos - il, r_len = il - pos;
        root->left = build(preorder, inorder, pl + 1, pl + l_len, il, pos - 1);
        root->right = build(preorder, inorder, pl + l_len + 1, pr, pos + 1, ir);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return build(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};

