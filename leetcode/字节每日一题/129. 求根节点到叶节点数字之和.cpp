// ###################################################### 版本1 ###################################################### //
// 每个节点维护，从根节点到当前的数字。如果一个节点是叶节点，就纳入ans
class Solution {
public:
    int ans;
    void dfs(TreeNode* root, int s){
        if(!root) return;
        s = s * 10 + root->val;
        if(root->left) dfs(root->left, s);
        if(root->right) dfs(root->right, s);
        if(!root->left && !root->right) ans += s;
    }
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};

// ###################################################### 版本2 ###################################################### //
// 有节点才能dfs
class Solution {
public:
    int ans = 0;
    void dfs(TreeNode* root, int s){
        s = s * 10 + root->val;
        if(!root->left && !root->right){
            ans += s;
            return;
        }
        if(root->left) dfs(root->left, s);
        if(root->right) dfs(root->right, s);
    }
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        dfs(root, 0);
        return ans;
    }
};