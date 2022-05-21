// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans;
        while(q.size()){
            int len = q.size();
            ans = q.front()->val;
            for(int i = 0; i < len; i++){
                auto t = q.front();
                q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }
        return ans;
    }
};