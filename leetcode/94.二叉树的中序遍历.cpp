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
// 递归
class Solution {
public:  
    void inorder(TreeNode* root, vector<int> &ans){
        if(root == nullptr) return;
        inorder(root -> left, ans);
        ans.push_back(root -> val);
        inorder(root -> right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;  
        inorder(root, ans);
        return ans;
    }
};

// ###################################################### 版本2 ###################################################### //
// 迭代
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;  
        stack<TreeNode*> st;
        while(root || st.size()){
            while(root){
                st.push(root);
                root = root -> left;
            }
            root = st.top();
            st.pop();
            ans.push_back(root -> val);
            root = root -> right;
        }
        return ans;
    }
};

// ###################################################### 版本3 ###################################################### //
// 迭代
class Solution {
public:
    vector<int> ans;
    stack<TreeNode*> stk;
    unordered_set<TreeNode*> vis;
    vector<int> inorderTraversal(TreeNode* root) {
        stk.push(root);
        vis.insert(root);
        while(stk.size()){
            auto t = stk.top();
            if(!t){
                stk.pop();
                continue;
            }
            if(t->left && !vis.count(t->left)){
                stk.push(t->left);
                vis.insert(t->left);
            }else{
                ans.push_back(t->val);
                stk.pop();
                stk.push(t->right);
                vis.insert(t->right);
            }
        }
        return ans;
    }
};