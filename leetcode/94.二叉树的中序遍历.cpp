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
