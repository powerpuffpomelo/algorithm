class Solution {
public:
    vector<vector<int>> ans;
    bool rev = false;
    void bfs(TreeNode* root){
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int len = q.size();
            vector<int> temp;
            for(int i = 0; i < len; i++){
                auto p = q.front();
                q.pop();
                temp.push_back(p->val);
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            if(rev) reverse(temp.begin(), temp.end());
            rev = !rev;
            ans.push_back(temp);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bfs(root);
        return ans;
    }
};