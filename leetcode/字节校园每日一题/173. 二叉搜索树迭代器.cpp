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
class BSTIterator {
public:
    vector<int> vv;
    int p;

    void dfs(TreeNode* root){
        if(root->left) dfs(root->left);
        vv.push_back(root->val);
        if(root->right) dfs(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        dfs(root);
        p = 0;
    }
    
    int next() {
        return vv[p++];
    }
    
    bool hasNext() {
        return p < vv.size();
    }
};