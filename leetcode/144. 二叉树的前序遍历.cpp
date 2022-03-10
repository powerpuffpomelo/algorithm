// ###################################################### 版本1 ###################################################### //
// 递归
class Solution {
public:
    vector<int> ans;
    void dfs(TreeNode* root){
        if(!root) return;
        ans.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

// ###################################################### 版本2 ###################################################### //
// 递推
class Solution {
public:
    vector<int> ans;
    stack<TreeNode*> stk;
    vector<int> preorderTraversal(TreeNode* root) {
        stk.push(root);
        while(stk.size()){
            auto t = stk.top();
            stk.pop();
            if(!t) continue;
            ans.push_back(t->val);
            stk.push(t->right);
            stk.push(t->left);
        }
        return ans;
    }
};