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
        stack<TreeNode*> stk;
        vector<int> ans;
        while(root || stk.size()){    // root指向当前该从哪里遍历了，stk里装遍历候选
            while(root){    // 在遍历一个节点的时候，保证该节点的左子节点优先遍历
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            ans.push_back(root->val);
            root = root->right;   // 遍历完一个节点，就该遍历该节点的右子树了
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