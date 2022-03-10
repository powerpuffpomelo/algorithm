// ###################################################### 版本1 ###################################################### //
// 我的思路：层序遍历（每层从右往左），记录每个节点在第几层，第一次遇到某层就把节点value加进来
class Solution {
public:
    unordered_set<int> vis;
    unordered_map<TreeNode*, int> layer;
    vector<int> ans;
    void bfs(TreeNode* root){
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);
        layer[root] = 1;
        while(q.size()){
            auto t = q.front();
            q.pop();
            if(!vis.count(layer[t])){
                ans.push_back(t->val);
                vis.insert(layer[t]);
            }
            if(t->right){
                q.push(t->right);
                layer[t->right] = layer[t] + 1;
            }
            if(t->left){
                q.push(t->left);
                layer[t->left] = layer[t] + 1;
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        bfs(root);
        return ans;
    }
};