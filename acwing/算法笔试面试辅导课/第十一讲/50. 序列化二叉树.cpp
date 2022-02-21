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