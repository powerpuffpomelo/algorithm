/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode *father;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL), father(NULL) {}
 * };
 */

// ###################################################### 版本3 ###################################################### //
// 模拟，O(h)
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* p) {
        if(p->right){
            p = p->right;
            while(p->left) p = p->left;
            return p;
        }
        while(p->father && p == p->father->right) p = p->father;
        return p->father;
    }
};

// ###################################################### 版本2 ###################################################### //
// 我的修改，模拟
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* p) {
        TreeNode* ans;
        if(p -> right){
            ans = p -> right;
            while(ans -> left) ans = ans -> left;
            return ans;
        }
        while(p -> father){
            ans = p -> father;
            if(ans -> left == p) return ans;
            else p = ans;
        }
        return nullptr;
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版，中序遍历
class Solution {
public:
    TreeNode* ans;
    int cur;
    bool flag = false;
    
    TreeNode* find(TreeNode* p){
        while(p -> father) p = p -> father;
        return p;
    }
    
    void inorder(TreeNode* p){
        if(!p) return;
        inorder(p -> left);
        if(flag){
            ans = p;
            flag = false;
            return;
        }
        if(p -> val == cur) flag = true;
        inorder(p -> right);
    }
    
    TreeNode* inorderSuccessor(TreeNode* p) {
        cur = p -> val;
        TreeNode* root = find(p);
        inorder(root);
        return ans;
    }
};