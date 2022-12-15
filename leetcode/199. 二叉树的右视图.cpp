// ###################################################### 版本2 ###################################################### //
// 在队列中，可以知道一层的开始和结束
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int len = q.size();
            for(int i = 0; i < len; i++){
                auto t = q.front();
                q.pop();
                if(!i) ans.push_back(t->val);
                if(t->right) q.push(t->right);
                if(t->left) q.push(t->left);
            }
        }
        return ans;
    }
};

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

