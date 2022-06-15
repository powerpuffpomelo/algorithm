// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    vector<int> vv;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        vv.push_back(root->val);
        dfs(root->right);
    }
    bool isValidBST(TreeNode* root) {
        dfs(root);
        for(int i = 1; i < vv.size(); i++){
            if(vv[i] <= vv[i - 1]) return false;
        }
        return true;
    }
};