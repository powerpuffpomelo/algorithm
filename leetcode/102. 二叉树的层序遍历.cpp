// ###################################################### 版本1 ###################################################### //
// 预先知道每层数量
class Solution {
public:
    vector<vector<int>> ans;
    void bfs(TreeNode* root){
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int len = q.size();
            vector<int> temp;
            for(int i = 0; i < len; i++){
                auto t = q.front();
                q.pop();
                temp.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            ans.push_back(temp);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        bfs(root);
        return ans;
    }
};

// ###################################################### 版本2 ###################################################### //
// 一层一层生成
class Solution {
public:
    vector<int> get_val(vector<TreeNode*> level)
    {
        vector<int> res;
        for (auto &u : level)
            res.push_back(u->val);
        return res;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if (!root) return res;
        vector<TreeNode*>level;
        level.push_back(root);
        res.push_back(get_val(level));
        while (true)
        {
            vector<TreeNode*> newLevel;
            for (auto &u : level)
            {
                if (u->left) newLevel.push_back(u->left);
                if (u->right) newLevel.push_back(u->right);
            }
            if (newLevel.size())
            {
                res.push_back(get_val(newLevel));
                level = newLevel;
            }
            else break;
        }
        return res;
    }
};
