// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
    typedef pair<TreeNode*, pair<int, int>> pti;
    static bool cmp(pti& a, pti& b){
        return a.first->val < b.first->val;
    }
public:
    map<int, vector<int>> ma;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pti> q;
        q.push({root, {0, 0}});
        while(q.size()){
            int len = q.size();
            vector<pti> v;
            for(int i = 0; i < len; i++){
                auto t = q.front();
                q.pop();
                auto p = t.first;
                int r = t.second.first, c = t.second.second;
                v.push_back(t);
                if(p->left) q.push({p->left, {r + 1, c - 1}});
                if(p->right) q.push({p->right, {r + 1, c + 1}});
            }
            sort(v.begin(), v.end(), cmp);
            for(auto t : v){
                ma[t.second.second].push_back(t.first->val);
            }
        }
        vector<vector<int>> ans;
        for(auto iter = ma.begin(); iter != ma.end(); iter++){
            ans.push_back(iter->second);
        }
        return ans;
    }
};