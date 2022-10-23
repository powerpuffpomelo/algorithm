// ###################################################### 版本3 ###################################################### //
// 中序遍历迭代
class BSTIterator {
public:
    stack<TreeNode*> stk;

    BSTIterator(TreeNode* root) {
        while(root){
            stk.push(root);
            root = root->left;
        }
    }
    
    int next() {
        auto root = stk.top();
        stk.pop();
        int ret = root->val;
        root = root->right;
        while(root){
            stk.push(root);
            root = root->left;
        }
        return ret;
    }
    
    bool hasNext() {
        return stk.size();
    }
};

// ###################################################### 版本2 ###################################################### //
// 中序遍历迭代
class BSTIterator {
public:
    stack<TreeNode*> stk;
    TreeNode* p;
    BSTIterator(TreeNode* root) {
        p = root;
    }
    
    int next() {
        int ret;
        while(p){
            stk.push(p);
            p = p->left;
        }
        p = stk.top();
        stk.pop();
        ret = p->val;
        p = p->right;
        return ret;
    }
    
    bool hasNext() {
        return p || stk.size();
    }
};

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