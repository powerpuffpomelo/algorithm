// ###################################################### 版本2 ###################################################### //
// 更简单一点的方法，无需队列，因为reverse无需知道层数，只要一直换换换就可以了
class Solution {
    vector<int> get_val(vector<TreeNode*> vv){
        vector<int> ret;
        for(auto u : vv){
            ret.push_back(u->val);
        }
        return ret;
    }
public:
    vector<vector<int>> printFromTopToBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        vector<TreeNode*> level;
        level.push_back(root);
        ret.push_back(get_val(level));
        bool zigzag = true;
        while(true){
            vector<TreeNode*> new_level;
            for(auto u : level){
                if(u->left)  new_level.push_back(u->left);
                if(u->right) new_level.push_back(u->right);
            }
            if(!new_level.size()) break;
            vector<int> vv = get_val(new_level);
            if(zigzag) reverse(vv.begin(), vv.end());
            ret.push_back(vv);
            level = new_level;
            zigzag = !zigzag;
        }
        return ret;
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> printFromTopToBottom(TreeNode* root) {
        vector<vector<int>> ret;
        queue<pair<TreeNode*, int>> q;
        if(root) q.push({root, 1});
        else return ret;
        vector<int> vv;
        int pre_layer = 1;
        while(q.size()){
            auto t = q.front();
            q.pop();
            auto r = t.first;
            auto layer = t.second;
            if(layer != pre_layer){
                if(pre_layer % 2 == 0){
                    reverse(vv.begin(), vv.end());
                }
                ret.push_back(vv);
                vv.clear();
                pre_layer = layer;
            }
            vv.push_back(r->val);
            if(r->left) q.push({r->left, layer + 1});
            if(r->right) q.push({r->right, layer + 1});
        }
        if(pre_layer % 2 == 0) reverse(vv.begin(), vv.end());
        ret.push_back(vv);
        return ret;
    }
};
