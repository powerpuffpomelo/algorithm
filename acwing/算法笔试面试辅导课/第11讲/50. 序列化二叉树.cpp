// ###################################################### 版本1 ###################################################### //
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    string str;
    int id;
public:
    void dfs_se(TreeNode* root){
        if(!root) str += "#,";
        else{
            str += to_string(root->val) + ',';
            dfs_se(root->left);
            dfs_se(root->right);
        }
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        dfs_se(root);
        return str;
    }
    
    TreeNode* dfs_de(string &data){
        if(data[id] == '#'){
            id += 2;
            return nullptr;
        }
        int st = id;
        while(data[id] != '#' && data[id] != ',') id++;
        auto ret = new TreeNode(stoi(data.substr(st, id - st)));  // 考虑节点值为负数的情况
        id++;
        ret->left = dfs_de(data);
        ret->right = dfs_de(data);
        return ret;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        id = 0;
        return dfs_de(data);
    }
};

// ###################################################### 版本2 ###################################################### //
class Solution {
public:
    string str;
    
    void dfs_se(TreeNode* root){
        if(!root){
            str += "#,";
            return;
        }
        str += to_string(root->val);
        str += ',';
        dfs_se(root->left);
        dfs_se(root->right);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        dfs_se(root);
        return str;
    }
    
    TreeNode* dfs_de(string& str, int& u){
        if(str[u] == '#'){
            u += 2;
            return nullptr;
        }
        int x = 0;
        bool neg = false;
        if(str[u] == '-'){
            u++;
            neg = true;
        }
        while(str[u] >= '0' && str[u] <= '9'){
            x = x * 10 + str[u] - '0';
            u++;
        }
        if(neg) x = -x;
        u++;
        TreeNode* p = new TreeNode(x);
        p->left = dfs_de(str, u);
        p->right = dfs_de(str, u);
        return p;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int u = 0;
        return dfs_de(data, u);
    }
};